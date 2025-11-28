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
	/// —водка дл€ MazeFieldForm
	/// </summary>
	public ref class MazeFieldForm : public System::Windows::Forms::Form
	{
	public:
		MazeField* MazeFieldObj; // создаем указатель MazeField (класс, который писал €)
		Form^ MainMenuObj; // создаем указатель на MainMenuForm (первую выскакивающую форму)

		MazeFieldForm(Form^ MMObj)
		{
			InitializeComponent();
			// создаем объект моего класса
			MazeFieldObj = new MazeField();  
			// присваиваем ссылку на MainMenuForm
			this->MainMenuObj = MMObj; 


		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MazeFieldForm()
		{	
			// перед закрытием MazeFieldForm выполн€етс€ код диструктора -> снова открываетс€ MainMenuForm
			this->MainMenuObj->Show(); 

			// очищаем пам€ть от указател€ на мой класс
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MazeFieldForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		MazeFieldObj->CreateField();
		Pen^ pen = gcnew Pen(Color::Blue, 10);
		SolidBrush^ brush = gcnew SolidBrush(Color::White);
		// –исуем пр€моугольник с верхним левым углом в точке (20, 20) и размерами 150x100
		/*g->DrawRectangle(pen, 20, 20, 150, 100);
		g->FillRectangle(brush, 20, 20, 150, 100); */
		//надо пройтись по вектору стен в объекте mazeField и нарисовать пр€моугольники с координатами стен
		for (int i = 0; i < MazeFieldObj->walls.size(); i++) {
			//в coord сохранитс€ x1, y1, x2, y2
			int x1 = MazeFieldObj->walls[i].coord[0], y1 = MazeFieldObj->walls[i].coord[1];
			int width = MazeFieldObj->walls[i].coord[2], height = MazeFieldObj->walls[i].coord[3];
			cout << x1 << y1 << width << height;
			g->FillRectangle(brush, x1, y1, width, height);
		}
	}	
	};
}
