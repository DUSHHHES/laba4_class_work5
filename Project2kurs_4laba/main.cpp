#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project2kurs_4laba;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MainForm form;

    Application::Run(% form);

    return 0;
}