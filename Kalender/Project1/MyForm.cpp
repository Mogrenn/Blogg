#include "MyForm.h"
#include "accountstuff.h"
#include "stdafx.h"
#include <iostream>
#define CURL_STATICLIB
#include <curl/curl.h>
#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}


[STAThreadAttribute]
void Main(array<String ^> ^args) {

	/*CURL *curl;
	CURLcode res;
	std::string readBuffer;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://10.130.216.101/TP/Kalender/funktioner/skapa.php");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		std::cout << readBuffer+" hej" << std::endl;
	}
	exit(0);*/

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm form;
	Application::Run(%form);



	/*
	char ret;
	CURL *curl;

	curl = curl_easy_init();
	if (curl) {
		const char *data = "funktion=skapaAKonto&anamn=ketchup&rollid=1&tjanst=1";
		curl_easy_setopt(curl, CURLOPT_URL, "10.130.216.101/TP/Admin/funktioner/skapa.php");

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		ret = curl_easy_perform(curl);
		std::cout << ret;

		curl_easy_cleanup(curl);
	}
	*/
	}
