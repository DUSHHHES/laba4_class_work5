#pragma once

#include "Entities.h"

namespace Project2kurs_4laba {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms; // Для MessageBox
	// Подключаем пространства имен SQLite
	using namespace System::Data::SQLite;

	public ref class DatabaseManager {
	private:
		SQLiteConnection^ dbConnection;
		String^ connectionString;

	public:
		DatabaseManager() {
			connectionString = "Data Source=database.db;Version=3;";
		}

		bool Connect() {
			try {
				dbConnection = gcnew SQLiteConnection(connectionString);
				dbConnection->Open();
				InitializeDatabase(); // Создаем таблицу, если ее еще нет
				return true;
			}
			catch (Exception^ ex) {
				
				MessageBox::Show("Не удалось подключиться к базе данных: " + ex->Message, "Критическая ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return false;
			}
		}

		~DatabaseManager() {
			if (dbConnection != nullptr) {
				dbConnection->Close();
			}
		}

		void InitializeDatabase() {
			String^ sql = "CREATE TABLE IF NOT EXISTS Tariffs ("
				"Name TEXT PRIMARY KEY NOT NULL, "
				"PricePerKm REAL NOT NULL, "
				"Discount REAL NOT NULL, "
				"CargoType INTEGER NOT NULL)";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			command->ExecuteNonQuery();
		}

		List<Tariff^>^ GetAllTariffs() {
			List<Tariff^>^ tariffs = gcnew List<Tariff^>();
			String^ sql = "SELECT * FROM Tariffs";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			SQLiteDataReader^ reader = command->ExecuteReader();
			while (reader->Read()) {
				Tariff^ tariff = gcnew Tariff();
				tariff->Name = Convert::ToString(reader["Name"]);
				tariff->PricePerKm = Convert::ToDouble(reader["PricePerKm"]);
				tariff->Discount = Convert::ToDouble(reader["Discount"]);
				tariff->Type = (CargoType)Convert::ToInt32(reader["CargoType"]);
				tariffs->Add(tariff);
			}
			return tariffs;
		}

		void AddTariff(Tariff^ tariff) {
			String^ sql = "INSERT OR IGNORE INTO Tariffs (Name, PricePerKm, Discount, CargoType) "
				"VALUES (@Name, @PricePerKm, @Discount, @CargoType)";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			command->Parameters->AddWithValue("@Name", tariff->Name);
			command->Parameters->AddWithValue("@PricePerKm", tariff->PricePerKm);
			command->Parameters->AddWithValue("@Discount", tariff->Discount);
			command->Parameters->AddWithValue("@CargoType", (int)tariff->Type);
			command->ExecuteNonQuery();
		}

		void UpdateTariff(Tariff^ tariff, String^ oldName) {
			String^ sql = "UPDATE Tariffs SET Name = @NewName, PricePerKm = @PricePerKm, "
				"Discount = @Discount, CargoType = @CargoType WHERE Name = @OldName";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			command->Parameters->AddWithValue("@NewName", tariff->Name);
			command->Parameters->AddWithValue("@PricePerKm", tariff->PricePerKm);
			command->Parameters->AddWithValue("@Discount", tariff->Discount);
			command->Parameters->AddWithValue("@CargoType", (int)tariff->Type);
			command->Parameters->AddWithValue("@OldName", oldName);
			command->ExecuteNonQuery();
		}

		void DeleteTariff(String^ tariffName) {
			String^ sql = "DELETE FROM Tariffs WHERE Name = @Name";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			command->Parameters->AddWithValue("@Name", tariffName);
			command->ExecuteNonQuery();
		}

		// (Для импорта) Очистить всю таблицу
		void ClearAllTariffs() {
			String^ sql = "DELETE FROM Tariffs";
			SQLiteCommand^ command = gcnew SQLiteCommand(sql, dbConnection);
			command->ExecuteNonQuery();
		}
	};
}