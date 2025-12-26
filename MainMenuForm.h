#pragma once
#include "MazeFieldForm.h"
#include "WinAreaForm.h"

namespace MazeCraze {
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainMenuForm
	/// </summary>
	public ref class MainMenuForm : public System::Windows::Forms::Form
	{
	public:
		MazeField* MazeFieldObj;// создаем указатель MazeField (класс, который писал я)
		MainMenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			MazeFieldObj = new MazeField(1);
			MazeFieldObj->CreateField();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainMenuForm()
		{
			if (components)
			{
				delete components;
			}

			// очищаем память от указателя на мой класс
			delete MazeFieldObj; 
		}
	private: System::Windows::Forms::Button^ btnLevel1;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnLevel2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLevel1 = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnLevel2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnLevel1
			// 
			this->btnLevel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnLevel1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnLevel1->Location = System::Drawing::Point(361, 110);
			this->btnLevel1->Name = L"btnLevel1";
			this->btnLevel1->Size = System::Drawing::Size(135, 43);
			this->btnLevel1->TabIndex = 4;
			this->btnLevel1->Text = L"Уровень 1";
			this->btnLevel1->UseVisualStyleBackColor = false;
			this->btnLevel1->Click += gcnew System::EventHandler(this, &MainMenuForm::btnLevel1_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnExit->Location = System::Drawing::Point(361, 222);
			this->btnExit->Margin = System::Windows::Forms::Padding(2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(135, 43);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainMenuForm::btnExit_Click);
			// 
			// btnLevel2
			// 
			this->btnLevel2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnLevel2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnLevel2->Location = System::Drawing::Point(361, 159);
			this->btnLevel2->Name = L"btnLevel2";
			this->btnLevel2->Size = System::Drawing::Size(135, 43);
			this->btnLevel2->TabIndex = 5;
			this->btnLevel2->Text = L"Уровень 2";
			this->btnLevel2->UseVisualStyleBackColor = false;
			this->btnLevel2->Click += gcnew System::EventHandler(this, &MainMenuForm::btnLevel2_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(857, 433);
			this->Controls->Add(this->btnLevel2);
			this->Controls->Add(this->btnLevel1);
			this->Controls->Add(this->btnExit);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainMenuForm";
			this->Text = L"MazeCraze";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnLevel1_Click(System::Object^ sender, System::EventArgs^ e) {
		// форма победы
		MazeCraze::WinAreaForm^ WinAreaObj = gcnew MazeCraze::WinAreaForm(this, MazeFieldObj);
		WinAreaObj->Hide();

		// форма лабиринта
		MazeCraze::MazeFieldForm^ MazeFieldFormObj = gcnew MazeCraze::MazeFieldForm(this, WinAreaObj, MazeFieldObj);
		MazeFieldFormObj->Show();
		this->Hide();

	}
	private: System::Void btnLevel2_Click(System::Object^ sender, System::EventArgs^ e) {
		// вызываем второй уровень 
		MazeFieldObj->LevelUp();
		// форма победы
		MazeCraze::WinAreaForm^ WinAreaObj = gcnew MazeCraze::WinAreaForm(this, MazeFieldObj);
		WinAreaObj->Hide();

		// форма лабиринта
		MazeCraze::MazeFieldForm^ MazeFieldFormObj = gcnew MazeCraze::MazeFieldForm(this, WinAreaObj, MazeFieldObj);
		MazeFieldFormObj->Show();
		this->Hide();
	}
};
}
