#include <curl/curl.h>
#define CURL_STATICLIB
using namespace System;
char ret;
CURL *curl;
int main(array<System::String ^> ^args) {
	curl = curl_easy_init();
	if (curl) {
		const char *data = "funktion=skapaAKonto&anamn=kalle&rollid=1&tjanst=1";
		curl_easy_setopt(curl, CURLOPT_URL, "10.130.216.101/TP/Admin/funktioner/skapa.php");

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
		ret = curl_easy_perform(curl);

		curl_easy_cleanup(curl);
	}
}