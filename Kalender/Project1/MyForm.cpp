#include "MyForm.h"
#include "accountstuff.h"
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	//Application::Run(%form);

	CURL *curl;

	curl = curl_easy_init();
	curl_easy_cleanup(curl);
}