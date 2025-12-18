#pragma once
#include "MazeFieldForm.h"

namespace MazeCraze {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для WinAreaForm
	/// </summary>
	public ref class WinAreaForm : public System::Windows::Forms::Form
	{
	public:
		Form^ MainMenuObj; // создаем указатель на MainMenuForm (первую выскакивающую форму)

		WinAreaForm(Form^ MMObj) {
			InitializeComponent();

			
			// присваиваем ссылку на MainMenuForm
			this->MainMenuObj = MMObj;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WinAreaForm() {
			// перед закрытием MazeFieldForm выполняется код диструктора -> снова открывается MainMenuForm
			this->MainMenuObj->Show();

			// очищаем память от указателя на мой класс
			/*delete MainMenuObj;*/

			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnNextLevel;
	private: System::Windows::Forms::Button^ btnExit;
	protected:

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
			this->btnNextLevel = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNextLevel
			// 
			this->btnNextLevel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnNextLevel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnNextLevel->Location = System::Drawing::Point(562, 349);
			this->btnNextLevel->Margin = System::Windows::Forms::Padding(5);
			this->btnNextLevel->Name = L"btnNextLevel";
			this->btnNextLevel->Size = System::Drawing::Size(332, 89);
			this->btnNextLevel->TabIndex = 5;
			this->btnNextLevel->Text = L"Следующий уровень";
			this->btnNextLevel->UseVisualStyleBackColor = false;
			this->btnNextLevel->Click += gcnew System::EventHandler(this, &WinAreaForm::btnNextLevel_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnExit->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnExit->Location = System::Drawing::Point(562, 462);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(332, 82);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"Выйти";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &WinAreaForm::btnExit_Click);
			// 
			// WinAreaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1470, 961);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnNextLevel);
			this->Name = L"WinAreaForm";
			this->Text = L"WinAreaForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnNextLevel_Click(System::Object^ sender, System::EventArgs^ e) {
		MazeCraze::MazeFieldForm^ MazeField = gcnew MazeCraze::MazeFieldForm(MainMenuObj, this);
		MazeField->Show();
		this->Hide();
	}
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
