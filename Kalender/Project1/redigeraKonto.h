#pragma once
#include <ctime>
#include <list>
#include <string>
#include <cmath>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "rapidjson/encodings.h"
#define CURL_STATICLIB
#include <curl/curl.h>
#include <algorithm>
#include <codecvt>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace rapidjson;


	namespace UTF3 {
		inline std::size_t callback(
			const char* in,
			std::size_t size,
			std::size_t num,
			std::string* out)
		{
			const std::size_t totalBytes(size * num);
			out->append(in, totalBytes);

			return totalBytes;
		}
	}
	/// <summary>
	/// Summary for redigeraKonto
	/// </summary>
	public ref class redigeraKonto : public System::Windows::Forms::Form
	{
	public:
		CURL *curl;
		CURLcode ret;
		String^ anvandarid;
		redigeraKonto(String^ id)
		{
			InitializeComponent();
			anvandarid = id;
			curl_global_init(CURL_GLOBAL_ALL);
			curl = curl_easy_init();
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~redigeraKonto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label2;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(257, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"lösenord";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(242, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"användarnamn";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(200, 218);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 62);
			this->button1->TabIndex = 8;
			this->button1->Text = L"redigera konto";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &redigeraKonto::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(135, 188);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(328, 22);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(135, 141);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(328, 22);
			this->textBox1->TabIndex = 6;
			// 
			// redigeraKonto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(592, 420);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"redigeraKonto";
			this->Text = L"redigeraKonto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int httpCode(0);
		std::string readBuffer;
		//std::string anvandarid = msclr::interop::marshal_as<std::string>(anvandarId); //to be changed
		if (curl) {
			String^ anamn = this->textBox1->Text;
			String^ losenord = this->textBox2->Text;
			String^ anvid = anvandarid;
			const char* url = "10.130.216.101/TP/Admin/funktioner/redigera.php";
			std::string param = "nyckel=iRxOUsizwhoXddb4&funktion=redigeraKonto&anvandarid=" + msclr::interop::marshal_as<std::string>(anvid) + "&anamn=" + msclr::interop::marshal_as<std::string>(anamn) + "&losenord=" + msclr::interop::marshal_as<std::string>(losenord);

			const char* parametrar = param.c_str();
			const char *data = parametrar;
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UTF3::callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

			ret = curl_easy_perform(curl);
			if (ret != CURLE_OK)
				std::cout << "fel på begäran";

			std::cout << readBuffer;
			curl_easy_cleanup(curl);

			const char* json = readBuffer.c_str();

			Document d;
			d.Parse(json);
			std::string kod = d["code"].GetString();
			std::string stat = d["status"].GetString();
			std::string msg = d["msg"].GetString();
			StringBuffer buffer;
			Writer<StringBuffer, Document::EncodingType, UTF8<> > writer(buffer);
			d.Accept(writer);

			const char* output = buffer.GetString();
			std::cout << output;
			std::string skrift = "kod: " + kod + " : " + msg;
			const char* ut = skrift.c_str();
			if (output == NULL) {
				MessageBoxA(NULL, "Fel på begäran", "serversvar:", MB_OK | MB_ICONQUESTION);
			}
			else
				MessageBoxA(NULL, msg.c_str(), "serversvar:", MB_OK | MB_ICONQUESTION);
		}
	}
	};
}
