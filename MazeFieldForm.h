#pragma once
#include "MazeField.h"
#include "Player.h"
#include "Robber.h"
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
	/// —водка дл€ MazeFieldForm
	/// </summary>
	public ref class MazeFieldForm : public System::Windows::Forms::Form
	{
	public:
		//—оздание графических инструментов
		Pen^ pen = gcnew Pen(Color::Blue, 10);
		SolidBrush^ brushwhite = gcnew SolidBrush(Color::White);
		SolidBrush^ brushblue = gcnew SolidBrush(Color::Blue);

		MazeField* MazeFieldObj;// создаем указатель MazeField (класс, который писал €)
		Form^ MainMenuObj;		// создаем указатель на MainMenuForm (первую выскакивающую форму)
		Form^ WinAreaObj;		// создаем указатель на WinAreaForm 
		Player* PlayerObj;		// создаем указатель на Player (класс, который писал €)
		//Robber* RobberObj; // создаем указатель на Robber (класс, который написал €)

		bool winFlag = false; // флаг победы

		MazeFieldForm(Form^ MMObj, Form^ WAObj) {
			InitializeComponent();
			// создаем объекты моего класса
			MazeFieldObj = new MazeField();  
			
			PlayerObj = new Player();
			PlayerObj->x = 0;
			PlayerObj->y = 190;

		/*	RobberObj = new Robber();
			RobberObj->x = 200;
			RobberObj->y = 200;*/
			
			// присваиваем ссылку на MainMenuForm
			this->MainMenuObj = MMObj; 

			// присваиваем ссылку на WinAreaForm
			this->WinAreaObj = WAObj;

			MazeFieldObj->CreateField();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MazeFieldForm() {	
			// если только мы не победили
			if (!winFlag) {
				// перед закрытием MazeFieldForm выполн€етс€ код диструктора -> снова открываетс€ MainMenuForm
				this->MainMenuObj->Show();
			}

			// очищаем пам€ть от указател€ на мой класс
			delete MazeFieldObj; 
			// очищаем пам€ть от указател€
			//delete MainMenuObj;
			//// очищаем пам€ть от указател€
			//delete WinAreaObj;
			// очищаем пам€ть от указател€
			delete PlayerObj;
			
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
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
		// –исуем пр€моугольник с верхним левым углом в точке (20, 20) и размерами 150x100
		/*g->DrawRectangle(pen, 20, 20, 150, 100);
		g->FillRectangle(brush, 20, 20, 150, 100); */
		//надо пройтись по вектору стен в объекте mazeField и нарисовать пр€моугольники с координатами стен
		for (int i = 0; i < MazeFieldObj->walls.size(); i++) {
			//в coord сохранитс€ x1, y1, x2, y2
			int x1 = MazeFieldObj->walls[i].coord[0], y1 = MazeFieldObj->walls[i].coord[1];
			int width = MazeFieldObj->walls[i].coord[2], height = MazeFieldObj->walls[i].coord[3];
			g->FillRectangle(brushwhite, x1, y1, width, height);
		}
		g->FillRectangle(brushblue, PlayerObj->x, PlayerObj->y, PlayerObj->size, PlayerObj->size);
	}	
	private: System::Void MazeFieldForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//Ќе забыть передавать уровень через переменную!
		bool flag;
		// ѕроверка на W or w
		if (((int)e->KeyCode == 87) || ((int)e->KeyCode == 119)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "up", 1);
		}
		if (((int)e->KeyCode == 83) || ((int)e->KeyCode == 115)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "down", 1);
		}
		if (((int)e->KeyCode == 65) || ((int)e->KeyCode == 97)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "left", 1);
		}
		if (((int)e->KeyCode == 68) || ((int)e->KeyCode == 100)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "right", 1);
		}
		if (flag) {
			this->winFlag = true;
			WinAreaObj->Show();
			this->Close();
		}
	}
	};
}
