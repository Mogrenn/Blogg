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
	Application::Run(%form);

	CURL *curl = curl_easy_init();
	if (curl) {
		CURLcode res;
		curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}