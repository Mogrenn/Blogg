#include "MyForm.h"
#include "accountstuff.h"
#include <nlohmann/json.hpp>
#include "stdafx.h"
#include <iostream>
#define CURL_STATICLIB
#include <curl/curl.h>
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	//Application::Run(%form);


	char ret;
	CURL *curl;

	curl = curl_easy_init();
	if (curl) {
		const char *data = "funktion=skapaAKonto&anamn=jorgen&rollid=1&tjanst=1";
		curl_easy_setopt(curl, CURLOPT_URL, "10.130.216.101/TP/Admin/funktioner/skapa.php");

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		ret = curl_easy_perform(curl);
		std::cout << ret;
		curl_easy_cleanup(curl);
	}

	}
