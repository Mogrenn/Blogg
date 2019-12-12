#include <msclr\marshal_cppstd.h>
#include <ctime>
#include <list>
#include <string>
#include <cmath>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/encodings.h"
#define CURL_STATICLIB
#include <curl/curl.h>
#include <algorithm>
#include <codecvt>
#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace rapidjson;

	/// <summary>
	/// Summary for skapaKonto
	/// </summary>




	public ref class skapaKonto : public System::Windows::Forms::Form
	{
		std::string parseson(const char *parametrar, const char *url) {
			CURLcode ret;
			CURL *curl;
			std::string* retval;
			int httpCode(0);
			std::string readBuffer;
			curl = curl_easy_init();
			if (curl) {
				const char *data = parametrar;
				curl_easy_setopt(curl, CURLOPT_URL, url);
				curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

				ret = curl_easy_perform(curl);
				if (ret != CURLE_OK)
					cout << "fel på begäran";

				cout << readBuffer;
				curl_easy_cleanup(curl);

				const char* json = readBuffer.c_str();

				Document d;
				d.Parse(json);

				StringBuffer buffer;
				Writer<StringBuffer, Document::EncodingType, UTF8<> > writer(buffer);
				d.Accept(writer);
				const char* output = buffer.GetString();
				std::cout << output;

				return output;
			}
		}
		void requestData(string params, const char *url) {
			/*string titel = "party";
			string action = "skapaKalenderevent";
			string anvandarId = "42";
			string kalenderId = "2";
			string innehall = "vi festar hos mig med morotskaka. ta med egna servetter";
			string start = "2019-02-01 16:00:00";
			string slut = "2019-02-02 06:00:00";*/
			//string params = "nyckel=iRxOUsizwhoXddb4&funktion="+action+"&titel=" + titel + "&anvandarId="+anvandarId+"&kalenderId="+kalenderId+"&innehall="+innehall+"&startTid="+start+"&slutTid="+slut;
			//string params = "nyckel=iRxOUsizwhoXddb4&funktion=skapaAKonto&anamn=kalenderuser2&tjanst=47&rollid=6";
			//string params = "nyckel=iRxOUsizwhoXddb4&kalendersida=1";
			//string params = "nyckel=iRxOUsizwhoXddb4&funktion=bjudin&eventID=5";
			//string params = "nyckel=iRxOUsizwhoXddb4&funktion=skapaKalender&anvandarId="+anvandarId+"&titel=systemkalendern";
			//const char* url = "10.130.216.101/TP/Kalender/funktioner/skapa.php";
			//const char* url = "10.130.216.101/TP/Admin/funktioner/skapa.php";
			//const char* url = "10.130.216.101/TP/Kalender/json/kalenderjson.php";
			MessageBoxA(NULL, parseson(params.c_str(), url).c_str(), "serversvar:", MB_OK | MB_ICONQUESTION);
			// nyckel=iRxOUsizwhoXddb4
		}
	public:
		skapaKonto(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~skapaKonto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(60, 78);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(328, 22);
			this->textBox1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(60, 110);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(328, 22);
			this->textBox2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 142);
			this->button1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 62);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Skapa";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &skapaKonto::bclick);
			// 
			// skapaKonto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 286);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"skapaKonto";
			this->Text = L"skapaKonto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void bclick(System::Object^  sender, System::EventArgs^  e) {
		String^ anamn = this->textBox1->Text;

		requestData("nyckel=iRxOUsizwhoXddb4&funktion=skapaAKonto&anamn=" + msclr::interop::marshal_as<std::string>(anamn) + "&tjanst=47&rollid=6", "10.130.216.101/TP/Admin/funktioner/skapa.php");

		

	}
	};
}
