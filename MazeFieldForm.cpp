#include "MazeFieldForm.h"
#include <Windows.h>


using namespace System;
using namespace System::Windows::Forms;
using namespace MazeCraze;

int WINAPI WinField(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    /*MazeCraze::MazeFieldForm MazeFieldForm;
    Application::Run(% MazeFieldForm);*/
    return 0;
}
