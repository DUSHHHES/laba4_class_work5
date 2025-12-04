#pragma once

#include "Entities.h" 

namespace Project2kurs_4laba { 

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;


	public ref class AddEditTariffForm : public System::Windows::Forms::Form
	{
	public:
		property Tariff^ ResultTariff;
		// Перегрузка конструктора AddEditTariffForm: 
		AddEditTariffForm(void)
		{
			InitializeComponent();
			this->Text = "Добавить новый тариф";
			comboBoxCargoType->DataSource = nullptr;
			comboBoxCargoType->Items->Clear();

			for (int i = 0; i <= (int)CargoType::PERISHABLE; i++) {
				comboBoxCargoType->Items->Add(CargoTypeToString((CargoType)i));
			}
		}

		AddEditTariffForm(Tariff^ tariffToEdit)// Заполняет форму дял редактирования + меняет заголовок формы
		{
			InitializeComponent();
			this->Text = "Редактировать тариф";

			comboBoxCargoType->DataSource = nullptr;
			comboBoxCargoType->Items->Clear();

			for (int i = 0; i <= (int)CargoType::PERISHABLE; i++) {
				comboBoxCargoType->Items->Add(CargoTypeToString((CargoType)i));
			}

			// Сохраняем переданный тариф и заполняем поля
			ResultTariff = tariffToEdit;
			textBoxName->Text = ResultTariff->Name;
			textBoxPrice->Text = ResultTariff->PricePerKm.ToString();
			textBoxDiscount->Text = ResultTariff->Discount.ToString();
			comboBoxCargoType->SelectedIndex = (int)ResultTariff->Type;
		}


	protected:
		~AddEditTariffForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxPrice;
	private: System::Windows::Forms::TextBox^ textBoxDiscount;
	private: System::Windows::Forms::ComboBox^ comboBoxCargoType;
	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::Button^ buttonCancel;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDiscount = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxCargoType = (gcnew System::Windows::Forms::ComboBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название тарифа:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Цена за км:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Скидка (%):";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(30, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Тип груза:";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(240, 30);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(250, 31);
			this->textBoxName->TabIndex = 4;
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Location = System::Drawing::Point(240, 80);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(250, 31);
			this->textBoxPrice->TabIndex = 5;
			// 
			// textBoxDiscount
			// 
			this->textBoxDiscount->Location = System::Drawing::Point(240, 130);
			this->textBoxDiscount->Name = L"textBoxDiscount";
			this->textBoxDiscount->Size = System::Drawing::Size(250, 31);
			this->textBoxDiscount->TabIndex = 6;
			// 
			// comboBoxCargoType
			// 
			this->comboBoxCargoType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCargoType->FormattingEnabled = true;
			this->comboBoxCargoType->Location = System::Drawing::Point(240, 180);
			this->comboBoxCargoType->Name = L"comboBoxCargoType";
			this->comboBoxCargoType->Size = System::Drawing::Size(250, 33);
			this->comboBoxCargoType->TabIndex = 7;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(240, 240);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(120, 50);
			this->buttonOK->TabIndex = 8;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &AddEditTariffForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(370, 240);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(120, 50);
			this->buttonCancel->TabIndex = 9;
			this->buttonCancel->Text = L"Отмена";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &AddEditTariffForm::buttonCancel_Click);
			// 
			// AddEditTariffForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 303);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->comboBoxCargoType);
			this->Controls->Add(this->textBoxDiscount);
			this->Controls->Add(this->textBoxPrice);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddEditTariffForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"AddEditTariffForm";
			this->Load += gcnew System::EventHandler(this, &AddEditTariffForm::AddEditTariffForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(textBoxName->Text)) {
			MessageBox::Show("Название тарифа не может быть пустым.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Проверка ввода цены
		String^ priceText = textBoxPrice->Text->Replace(",", ".");
		if (priceText->Split('.')->Length > 2) {
			MessageBox::Show("Цена введена некорректно (слишком много точек/запятых).", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (priceText->Contains(".") && priceText->Substring(priceText->IndexOf(".") + 1)->Length > 2) {
			MessageBox::Show("Цена не может иметь более двух знаков после запятой.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		double price;
		if (!Double::TryParse(priceText, NumberStyles::Any, CultureInfo::InvariantCulture, price)) {
			MessageBox::Show("Цена должна быть числом.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (price <= 0 || price > 1000) {
			MessageBox::Show("Цена должна быть в диапазоне от 0.01 до 1000.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Проверка ввода скидки
		String^ discountText = textBoxDiscount->Text->Replace(",", ".");
		if (discountText->Split('.')->Length > 2) {
			MessageBox::Show("Скидка введена некорректно (слишком много точек/запятых).", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (discountText->Contains(".") && discountText->Substring(discountText->IndexOf(".") + 1)->Length > 2) {
			MessageBox::Show("Скидка не может иметь более двух знаков после запятой.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		double discount;
		if (!Double::TryParse(discountText, NumberStyles::Any, CultureInfo::InvariantCulture, discount)) {
			MessageBox::Show("Скидка должна быть числом.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (discount < 0 || discount > 100) {
			MessageBox::Show("Скидка должна быть в диапазоне от 0 до 100.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// Создание или обновление объекта
		if (ResultTariff == nullptr) {
			ResultTariff = gcnew Tariff();
		}
		ResultTariff->Name = textBoxName->Text;
		ResultTariff->PricePerKm = price;
		ResultTariff->Discount = discount;
		ResultTariff->Type = (CargoType)comboBoxCargoType->SelectedIndex;

		// Установка результата и закрытие формы
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}

	private: System::Void buttonCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	private: System::Void AddEditTariffForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}