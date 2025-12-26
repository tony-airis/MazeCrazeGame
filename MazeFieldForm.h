#pragma once
#include "MazeField.h"
#include "Player.h"
#include "Robber.h"
#include <iostream>
#include <time.h>
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
		SolidBrush^ brushwhite = gcnew SolidBrush(Color::White);
		SolidBrush^ brushblue = gcnew SolidBrush(Color::Blue);
		SolidBrush^ brushyellow = gcnew SolidBrush(Color::Yellow);

		MazeField* MazeFieldObj;// создаем указатель MazeField (класс, который писал я)
		Form^ MainMenuObj;		// создаем указатель на MainMenuForm (первую выскакивающую форму)
		Form^ WinAreaObj;		// создаем указатель на WinAreaForm 
		Player* PlayerObj;		// создаем указатель на Player (класс, который писал я)
		Robber* RobberObj; // создаем указатель на Robber (класс, который написал я)

		//Таймер
		Timer^ timer = gcnew Timer();


		
		bool winFlag = false; // флаг победы

		MazeFieldForm(Form^ MMObj, Form^ WAObj, MazeField* MFObj) {
			InitializeComponent();
			// создаем объекты моего класса
			
			PlayerObj = new Player();
			PlayerObj->x = 0;
			PlayerObj->y = 190;
			
			// присваиваем ссылку на MainMenuForm
			this->MainMenuObj = MMObj; 

			// присваиваем ссылку на WinAreaForm
			this->WinAreaObj = WAObj;

			// сохраняю ссылку на MazeField
			this->MazeFieldObj = MFObj;

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MazeFieldForm() {	
			// если только мы не победили
			if (!winFlag) {
				// перед закрытием MazeFieldForm выполняется код диструктора -> снова открывается MainMenuForm
				this->MainMenuObj->Show();
			}
			// очищаем память от указателя
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
			this->ClientSize = System::Drawing::Size(1111, 1070);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MazeFieldForm";
			this->Text = L"MazeCraze";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MazeFieldForm::MazeFieldForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MazeFieldForm::MazeFieldForm_KeyDown);
			this->ResumeLayout(false);

			//Задаем параметры для таймера
			//Как часто он обновляется (в млсек)
			timer->Interval = 100;
			//Какая функция выывается при каждом выхове таймера
			timer->Tick += gcnew EventHandler(this, &MazeFieldForm::OnTimerTick);
			timer->Start();

		}
#pragma endregion
		void OnTimerTick(Object^ obj, EventArgs^ e) {
			//перерисовываем изображение 10 раз в секунду
			this->Refresh();
		}
	private: System::Void MazeFieldForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {

		Graphics^ g = e->Graphics;

		//надо пройтись по вектору стен в объекте mazeField и нарисовать прямоугольники с координатами стен
		for (int i = 0; i < MazeFieldObj->walls.size(); i++) {
			//в coord сохранится x1, y1, x2, y2
			int x1 = MazeFieldObj->walls[i].coord[0], y1 = MazeFieldObj->walls[i].coord[1];
			int width = MazeFieldObj->walls[i].coord[2], height = MazeFieldObj->walls[i].coord[3];
			g->FillRectangle(brushwhite, x1, y1, width, height);
		}

		//Рисуем игрока
		g->FillRectangle(brushblue, PlayerObj->x, PlayerObj->y, PlayerObj->size, PlayerObj->size);

		//Рисуем Разбойников
		if ((MazeFieldObj->WhichLevel() > 1) && (MazeFieldObj->robbers.size() != 0)) {
			int robberSize = MazeFieldObj->robbers[0].size;
			for (int i = 0; i < MazeFieldObj->robbers.size(); i++) {
				int x = MazeFieldObj->robbers[i].x;
				int y = MazeFieldObj->robbers[i].y;
				g->FillRectangle(brushyellow, x, y, robberSize, robberSize);
			}
		}
		
		//this->Invalidate();
	}	
	private: System::Void MazeFieldForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//Не забыть передавать уровень через переменную!
		bool flag = false;
		// Проверка на W or w
		if (((int)e->KeyCode == 87) || ((int)e->KeyCode == 119)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "up");
		}
		if (((int)e->KeyCode == 83) || ((int)e->KeyCode == 115)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "down");
		}
		if (((int)e->KeyCode == 65) || ((int)e->KeyCode == 97)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "left");
		}
		if (((int)e->KeyCode == 68) || ((int)e->KeyCode == 100)) {
			flag = MazeFieldObj->MayMove(PlayerObj, "right");
		}
		if (flag) {
			this->winFlag = true;
			MazeFieldObj->LevelUp();
			WinAreaObj->Show();
			this->Close();
		}
	}
	};
}
