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
		MainMenuForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
		}
	private: System::Windows::Forms::Button^ btnStart;
	protected:
	private: System::Windows::Forms::Button^ btnExit;

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
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStart->Location = System::Drawing::Point(542, 263);
			this->btnStart->Margin = System::Windows::Forms::Padding(5);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(203, 67);
			this->btnStart->TabIndex = 4;
			this->btnStart->Text = L"Играть";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &MainMenuForm::btnStart_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnExit->Location = System::Drawing::Point(542, 347);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(203, 67);
			this->btnExit->TabIndex = 3;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MainMenuForm::btnExit_Click);
			// 
			// MainMenuForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1286, 677);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->btnExit);
			this->Name = L"MainMenuForm";
			this->Text = L"MazeCraze";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
		// форма победы
		MazeCraze::WinAreaForm^ WinAreaObj = gcnew MazeCraze::WinAreaForm(this);
		WinAreaObj->Hide();
		
		// форма лабиринта
		MazeCraze::MazeFieldForm^ MazeFieldObj = gcnew MazeCraze::MazeFieldForm(this, WinAreaObj);
		MazeFieldObj->Show();
		this->Hide();

	}
	};
}
