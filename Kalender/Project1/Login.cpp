#include "Login.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Login() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::Login form;
	Application::Run(%form);
}