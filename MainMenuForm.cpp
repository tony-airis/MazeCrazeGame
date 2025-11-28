#include "MainMenuForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace MazeCraze;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MazeCraze::MainMenuForm MainMenuForm;
    Application::Run(% MainMenuForm);
    return 0;
}
