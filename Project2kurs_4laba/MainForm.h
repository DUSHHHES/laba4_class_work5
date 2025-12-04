#pragma once

#include "Entities.h"
#include "AddEditTariffForm.h"
#include "DatabaseManager.h" 

namespace Project2kurs_4laba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			dbManager = gcnew DatabaseManager();
			if (!dbManager->Connect()) {
				MessageBox::Show(" ËÚË˜ÂÒÍ‡ˇ Ó¯Ë·Í‡: ÌÂ Û‰‡ÎÓÒ¸ ÔÓ‰ÍÎ˛˜ËÚ¸Òˇ Í ·‡ÁÂ ‰‡ÌÌ˚ı. ‘ÛÌÍˆËÓÌ‡Î ·Û‰ÂÚ Ó„‡ÌË˜ÂÌ.", "Œ¯Ë·Í‡ ÔÓ‰ÍÎ˛˜ÂÌËˇ", MessageBoxButtons::OK, MessageBoxIcon::Error);
				for each (Control ^ ctrl in this->Controls) {
					ctrl->Enabled = false;
				}
			}
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		DatabaseManager^ dbManager;

	private: System::Windows::Forms::DataGridView^ dataGridViewTariffs;
	private: System::Windows::Forms::Button^ buttonAddTariff;
	private: System::Windows::Forms::Button^ buttonEditTariff;
	private: System::Windows::Forms::Button^ buttonDeleteTariff;
	private: System::Windows::Forms::Button^ buttonSortTariffs;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ËÏÔÓÚ»ÁCSVToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ˝ÍÒÔÓÚ¬CSVToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->dataGridViewTariffs = (gcnew System::Windows::Forms::DataGridView());
			   this->buttonAddTariff = (gcnew System::Windows::Forms::Button());
			   this->buttonEditTariff = (gcnew System::Windows::Forms::Button());
			   this->buttonDeleteTariff = (gcnew System::Windows::Forms::Button());
			   this->buttonSortTariffs = (gcnew System::Windows::Forms::Button());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->Ù‡ÈÎToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem()); // »ÁÏÂÌÂÌÓ
			   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem()); // »ÁÏÂÌÂÌÓ
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTariffs))->BeginInit();
			   this->menuStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // dataGridViewTariffs
			   // 
			   this->dataGridViewTariffs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridViewTariffs->Location = System::Drawing::Point(12, 40);
			   this->dataGridViewTariffs->Name = L"dataGridViewTariffs";
			   this->dataGridViewTariffs->RowHeadersWidth = 82;
			   this->dataGridViewTariffs->RowTemplate->Height = 33;
			   this->dataGridViewTariffs->Size = System::Drawing::Size(1000, 500);
			   this->dataGridViewTariffs->TabIndex = 0;
			   // 
			   // buttonAddTariff
			   // 
			   this->buttonAddTariff->Location = System::Drawing::Point(1020, 40);
			   this->buttonAddTariff->Name = L"buttonAddTariff";
			   this->buttonAddTariff->Size = System::Drawing::Size(230, 50);
			   this->buttonAddTariff->TabIndex = 1;
			   this->buttonAddTariff->Text = L"ƒÓ·‡‚ËÚ¸";
			   this->buttonAddTariff->UseVisualStyleBackColor = true;
			   this->buttonAddTariff->Click += gcnew System::EventHandler(this, &MainForm::buttonAddTariff_Click);
			   // 
			   // buttonEditTariff
			   // 
			   this->buttonEditTariff->Location = System::Drawing::Point(1020, 100);
			   this->buttonEditTariff->Name = L"buttonEditTariff";
			   this->buttonEditTariff->Size = System::Drawing::Size(230, 50);
			   this->buttonEditTariff->TabIndex = 2;
			   this->buttonEditTariff->Text = L"»ÁÏÂÌËÚ¸";
			   this->buttonEditTariff->UseVisualStyleBackColor = true;
			   this->buttonEditTariff->Click += gcnew System::EventHandler(this, &MainForm::buttonEditTariff_Click);
			   // 
			   // buttonDeleteTariff
			   // 
			   this->buttonDeleteTariff->Location = System::Drawing::Point(1020, 160);
			   this->buttonDeleteTariff->Name = L"buttonDeleteTariff";
			   this->buttonDeleteTariff->Size = System::Drawing::Size(230, 50);
			   this->buttonDeleteTariff->TabIndex = 3;
			   this->buttonDeleteTariff->Text = L"”‰‡ÎËÚ¸";
			   this->buttonDeleteTariff->UseVisualStyleBackColor = true;
			   this->buttonDeleteTariff->Click += gcnew System::EventHandler(this, &MainForm::buttonDeleteTariff_Click);
			   // 
			   // buttonSortTariffs
			   // 
			   this->buttonSortTariffs->Location = System::Drawing::Point(1020, 220);
			   this->buttonSortTariffs->Name = L"buttonSortTariffs";
			   this->buttonSortTariffs->Size = System::Drawing::Size(230, 73);
			   this->buttonSortTariffs->TabIndex = 4;
			   this->buttonSortTariffs->Text = L"—ÓÚËÓ‚‡Ú¸ ÔÓ ËÏÂÌË";
			   this->buttonSortTariffs->UseVisualStyleBackColor = true;
			   this->buttonSortTariffs->Click += gcnew System::EventHandler(this, &MainForm::buttonSortTariffs_Click);
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Ù‡ÈÎToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1264, 42);
			   this->menuStrip1->TabIndex = 5;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // Ù‡ÈÎToolStripMenuItem
			   // 
			   this->Ù‡ÈÎToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem,
					   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem
			   });
			   this->Ù‡ÈÎToolStripMenuItem->Name = L"Ù‡ÈÎToolStripMenuItem";
			   this->Ù‡ÈÎToolStripMenuItem->Size = System::Drawing::Size(262, 38);
			   this->Ù‡ÈÎToolStripMenuItem->Text = L"‘‡ÈÎ (»ÏÔÓÚ/›ÍÒÔÓÚ)";
			   // 
			   // ËÏÔÓÚ»ÁCSVToolStripMenuItem
			   // 
			   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem->Name = L"ËÏÔÓÚ»ÁCSVToolStripMenuItem";
			   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem->Size = System::Drawing::Size(418, 44);
			   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem->Text = L"»ÏÔÓÚ ËÁ CSV ‚ ¡ƒ...";
			   this->ËÏÔÓÚ»ÁCSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ËÏÔÓÚ»ÁCSVToolStripMenuItem_Click);
			   // 
			   // ˝ÍÒÔÓÚ¬CSVToolStripMenuItem
			   // 
			   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem->Name = L"˝ÍÒÔÓÚ¬CSVToolStripMenuItem";
			   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem->Size = System::Drawing::Size(418, 44);
			   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem->Text = L"›ÍÒÔÓÚ ËÁ ¡ƒ ‚ CSV...";
			   this->˝ÍÒÔÓÚ¬CSVToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::˝ÍÒÔÓÚ¬CSVToolStripMenuItem_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1264, 561);
			   this->Controls->Add(this->buttonSortTariffs);
			   this->Controls->Add(this->buttonDeleteTariff);
			   this->Controls->Add(this->buttonEditTariff);
			   this->Controls->Add(this->buttonAddTariff);
			   this->Controls->Add(this->dataGridViewTariffs);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MainForm";
			   this->Text = L"”Ô‡‚ÎÂÌËÂ „ÛÁÓÔÂÂ‚ÓÁÍ‡ÏË (¡ƒ)";
			   this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTariffs))->EndInit();
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private:
		void RefreshTariffGrid() {
			dataGridViewTariffs->Rows->Clear();
			List<Tariff^>^ tariffsFromDb = dbManager->GetAllTariffs();
			for each (Tariff ^ tariff in tariffsFromDb) {
				dataGridViewTariffs->Rows->Add(
					tariff->Name,
					tariff->PricePerKm,
					tariff->Discount,
					CargoTypeToString(tariff->Type) // »ÒÔÓÎ¸ÁÛÂÏ ÛÒÒÍËÈ ˇÁ˚Í
				);
			}
		}

		int CompareTariffsByName(Tariff^ a, Tariff^ b) {
			return String::Compare(a->Name, b->Name);
		}

		// œË Á‡„ÛÁÍÂ ÙÓÏ˚ Ì‡ÒÚ‡Ë‚‡ÂÏ Ú‡·ÎËˆÛ Ë Á‡„ÛÊ‡ÂÏ ‰‡ÌÌ˚Â ËÁ ¡ƒ
		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			dataGridViewTariffs->ColumnCount = 4;
			dataGridViewTariffs->Columns[0]->Name = "Õ‡Á‚‡ÌËÂ";
			dataGridViewTariffs->Columns[1]->Name = "÷ÂÌ‡/ÍÏ";
			dataGridViewTariffs->Columns[2]->Name = "—ÍË‰Í‡, %";
			dataGridViewTariffs->Columns[3]->Name = "“ËÔ „ÛÁ‡";

			dataGridViewTariffs->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewTariffs->AllowUserToAddRows = false;
			dataGridViewTariffs->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			dataGridViewTariffs->RowHeadersVisible = false;
			dataGridViewTariffs->MultiSelect = false;
			dataGridViewTariffs->ReadOnly = true;

			RefreshTariffGrid();
		}

		
		System::Void buttonAddTariff_Click(System::Object^ sender, System::EventArgs^ e) {
			AddEditTariffForm^ addForm = gcnew AddEditTariffForm();
			if (addForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				dbManager->AddTariff(addForm->ResultTariff);
				RefreshTariffGrid();
			}
		}

		
		System::Void buttonEditTariff_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dataGridViewTariffs->CurrentRow == nullptr) {
				MessageBox::Show("œÓÊ‡ÎÛÈÒÚ‡, ‚˚·ÂËÚÂ Ú‡ËÙ ‰Îˇ Â‰‡ÍÚËÓ‚‡ÌËˇ.", "¬ÌËÏ‡ÌËÂ", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ oldName = dataGridViewTariffs->CurrentRow->Cells["Õ‡Á‚‡ÌËÂ"]->Value->ToString();

			Tariff^ selectedTariff = gcnew Tariff();
			selectedTariff->Name = oldName;
			selectedTariff->PricePerKm = Convert::ToDouble(dataGridViewTariffs->CurrentRow->Cells["÷ÂÌ‡/ÍÏ"]->Value);
			selectedTariff->Discount = Convert::ToDouble(dataGridViewTariffs->CurrentRow->Cells["—ÍË‰Í‡, %"]->Value);
			String^ typeStr = dataGridViewTariffs->CurrentRow->Cells["“ËÔ „ÛÁ‡"]->Value->ToString();
			for (int i = 0; i <= (int)CargoType::PERISHABLE; i++) {
				if (CargoTypeToString((CargoType)i) == typeStr) {
					selectedTariff->Type = (CargoType)i;
					break;
				}
			}

			AddEditTariffForm^ editForm = gcnew AddEditTariffForm(selectedTariff);
			if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				dbManager->UpdateTariff(editForm->ResultTariff, oldName);
				RefreshTariffGrid();
			}
		}

		System::Void buttonDeleteTariff_Click(System::Object^ sender, System::EventArgs^ e) {
			if (dataGridViewTariffs->CurrentRow == nullptr) {
				MessageBox::Show("œÓÊ‡ÎÛÈÒÚ‡, ‚˚·ÂËÚÂ Ú‡ËÙ ‰Îˇ Û‰‡ÎÂÌËˇ.", "¬ÌËÏ‡ÌËÂ", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ tariffNameToDelete = dataGridViewTariffs->CurrentRow->Cells["Õ‡Á‚‡ÌËÂ"]->Value->ToString();

			String^ message = "¬˚ Û‚ÂÂÌ˚, ˜ÚÓ ıÓÚËÚÂ Û‰‡ÎËÚ¸ Ú‡ËÙ '" + tariffNameToDelete + "' ËÁ ·‡Á˚ ‰‡ÌÌ˚ı?";
			if (MessageBox::Show(message, "œÓ‰Ú‚ÂÊ‰ÂÌËÂ Û‰‡ÎÂÌËˇ", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				dbManager->DeleteTariff(tariffNameToDelete);
				RefreshTariffGrid();
			}
		}

		System::Void buttonSortTariffs_Click(System::Object^ sender, System::EventArgs^ e) {
			List<Tariff^>^ tariffsFromDb = dbManager->GetAllTariffs();
			tariffsFromDb->Sort(gcnew Comparison<Tariff^>(this, &MainForm::CompareTariffsByName));

			dataGridViewTariffs->Rows->Clear();
			for each (Tariff ^ tariff in tariffsFromDb) {
				dataGridViewTariffs->Rows->Add(tariff->Name, tariff->PricePerKm, tariff->Discount, CargoTypeToString(tariff->Type));
			}
		}

		System::Void ËÏÔÓÚ»ÁCSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			openFileDialog1->Filter = "CSV-Ù‡ÈÎ˚ (*.csv)|*.csv|¬ÒÂ Ù‡ÈÎ˚ (*.*)|*.*";
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				if (MessageBox::Show("Œ˜ËÒÚËÚ¸ ‚ÒÂ ÒÛ˘ÂÒÚ‚Û˛˘ËÂ ‰‡ÌÌ˚Â ‚ ¡ƒ ÔÂÂ‰ ËÏÔÓÚÓÏ?", "¬ÌËÏ‡ÌËÂ", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					dbManager->ClearAllTariffs();
				}
				try {
					StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
					String^ line;
					while ((line = reader->ReadLine()) != nullptr) {
						array<String^>^ parts = line->Split(';');
						if (parts->Length == 4) {
							Tariff^ newTariff = gcnew Tariff();
							newTariff->Name = parts[0];
							newTariff->PricePerKm = Double::Parse(parts[1]);
							newTariff->Discount = Double::Parse(parts[2]);
							newTariff->Type = (CargoType)Enum::Parse(CargoType::typeid, parts[3], true); // true - Ë„ÌÓËÓ‚‡Ú¸ Â„ËÒÚ
							dbManager->AddTariff(newTariff);
						}
					}
					reader->Close();
					RefreshTariffGrid();
					MessageBox::Show("ƒ‡ÌÌ˚Â ÛÒÔÂ¯ÌÓ ËÏÔÓÚËÓ‚‡Ì˚ ‚ ·‡ÁÛ ‰‡ÌÌ˚ı.", "”ÒÔÂı", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Œ¯Ë·Í‡ ÔË ËÏÔÓÚÂ Ù‡ÈÎ‡: " + ex->Message, "Œ¯Ë·Í‡", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}

		System::Void ˝ÍÒÔÓÚ¬CSVToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			saveFileDialog1->Filter = "CSV-Ù‡ÈÎ˚ (*.csv)|*.csv|¬ÒÂ Ù‡ÈÎ˚ (*.*)|*.*";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				List<Tariff^>^ tariffsToExport = dbManager->GetAllTariffs();
				try {
					StreamWriter^ writer = gcnew StreamWriter(saveFileDialog1->FileName);
					for each (Tariff ^ tariff in tariffsToExport) {
						writer->WriteLine(String::Format("{0};{1};{2};{3}",
							tariff->Name,
							tariff->PricePerKm.ToString(),
							tariff->Discount.ToString(),
							tariff->Type.ToString("G") // "G" - ‰Îˇ ÔÓÎÛ˜ÂÌËˇ ËÏÂÌË (GENERAL)
						));
					}
					writer->Close();
					MessageBox::Show("ƒ‡ÌÌ˚Â ÛÒÔÂ¯ÌÓ ˝ÍÒÔÓÚËÓ‚‡Ì˚ ËÁ ·‡Á˚ ‰‡ÌÌ˚ı.", "”ÒÔÂı", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Œ¯Ë·Í‡ ÔË ˝ÍÒÔÓÚÂ Ù‡ÈÎ‡: " + ex->Message, "Œ¯Ë·Í‡", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	};
}