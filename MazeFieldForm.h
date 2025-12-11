#pragma once
#include "MazeField.h"
#include "Player.h"
#include <iostream>
//#include "MainMenuForm.h"


namespace MazeCraze {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MazeFieldForm
	/// </summary>
	public ref class MazeFieldForm : public System::Windows::Forms::Form
	{
	public:
		//Создание графических инструментов
		Pen^ pen = gcnew Pen(Color::Blue, 10);
		SolidBrush^ brushwhite = gcnew SolidBrush(Color::White);
		SolidBrush^ brushblue = gcnew SolidBrush(Color::Blue);

		MazeField* MazeFieldObj; // создаем указатель MazeField (класс, который писал я)
		Form^ MainMenuObj; // создаем указатель на MainMenuForm (первую выскакивающую форму)
		Player* PlayerObj; // создаем указатель на Player (класс, который писал я)

		MazeFieldForm(Form^ MMObj)
		{
			InitializeComponent();
			// создаем объекты моего класса
			MazeFieldObj = new MazeField();  
			
			PlayerObj = new Player();
			PlayerObj->x = 0;
			PlayerObj->y = 190;
			
			// присваиваем ссылку на MainMenuForm
			this->MainMenuObj = MMObj; 

			MazeFieldObj->CreateField();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MazeFieldForm()
		{	
			// перед закрытием MazeFieldForm выполняется код диструктора -> снова открывается MainMenuForm
			this->MainMenuObj->Show(); 

			// очищаем память от указателя на мой класс
			delete MazeFieldObj; 
			
			if (components)
			{
				delete components;
			}
		}

	protected:


	protected:


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
			this->SuspendLayout();
			// 
			// MazeFieldForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1874, 1129);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MazeFieldForm";
			this->Text = L"MazeCraze";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MazeFieldForm::MazeFieldForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MazeFieldForm::MazeFieldForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MazeFieldForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Refresh();
		Graphics^ g = e->Graphics;
		// Рисуем прямоугольник с верхним левым углом в точке (20, 20) и размерами 150x100
		/*g->DrawRectangle(pen, 20, 20, 150, 100);
		g->FillRectangle(brush, 20, 20, 150, 100); */
		//надо пройтись по вектору стен в объекте mazeField и нарисовать прямоугольники с координатами стен
		for (int i = 0; i < MazeFieldObj->walls.size(); i++) {
			//в coord сохранится x1, y1, x2, y2
			int x1 = MazeFieldObj->walls[i].coord[0], y1 = MazeFieldObj->walls[i].coord[1];
			int width = MazeFieldObj->walls[i].coord[2], height = MazeFieldObj->walls[i].coord[3];
			g->FillRectangle(brushwhite, x1, y1, width, height);
		}
		g->FillRectangle(brushblue, PlayerObj->x, PlayerObj->y, PlayerObj->size, PlayerObj->size);
	}	
	private: System::Void MazeFieldForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Провека на W or w
		if (((int)e->KeyCode == 87) || ((int)e->KeyCode == 119)) {
			MazeFieldObj->MayMove(PlayerObj, "up");
		}
		if (((int)e->KeyCode == 83) || ((int)e->KeyCode == 115)) {
			MazeFieldObj->MayMove(PlayerObj, "down");
		}
		if (((int)e->KeyCode == 65) || ((int)e->KeyCode == 97)) {
			MazeFieldObj->MayMove(PlayerObj, "left");
		}
		if (((int)e->KeyCode == 68) || ((int)e->KeyCode == 100)) {
			MazeFieldObj->MayMove(PlayerObj, "right");
		}
		
	}
	};
}
