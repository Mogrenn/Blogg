

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
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace rapidjson;

namespace Project1 {

	namespace UTF2 {
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
	/// Summary for skapaKonto
	/// </summary>
	public ref class skapaKonto : public System::Windows::Forms::Form
	{
	public:
		CURL *curl;
	private: System::Windows::Forms::Label^  label1;
	public:

	public:
		CURLcode ret;

		skapaKonto(void)
		{
			InitializeComponent();
			curl_global_init(CURL_GLOBAL_ALL);
			curl = curl_easy_init();
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(71, 80);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(137, 142);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 62);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Skapa";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &skapaKonto::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(200, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"användarnamn";
			// 
			// skapaKonto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 286);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"skapaKonto";
			this->Text = L"skapaKonto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^  e) {
		int httpCode(0);
		std::string readBuffer;
		//string* retval;
		if (curl) {
			String^ anamn = this->textBox1->Text;
			const char* url = "10.130.216.101/TP/Admin/funktioner/skapa.php";
			std::string param = "nyckel=iRxOUsizwhoXddb4&funktion=skapaAKonto&anamn=" + msclr::interop::marshal_as<std::string>(anamn) + "&tjanst=47&rollid=6";
			const char *data = param.c_str();
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UTF2::callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

			ret = curl_easy_perform(curl);
			if (ret != CURLE_OK)
				Console::Write("fel på begäran");

			std::cout << readBuffer;
			curl_easy_cleanup(curl);
			
			const char* json = readBuffer.c_str();

			Document d;
			d.Parse(json);
			std::string losen = d["password"].GetString();
			StringBuffer buffer;
			Writer<StringBuffer, Document::EncodingType, UTF8<> > writer(buffer);
			d.Accept(writer);
			const char* output = buffer.GetString();
			std::cout << output;

			if (output == NULL) {
				MessageBoxA(NULL, "fel på begäran/ upptaget användarnamn", "serversvar:", MB_OK | MB_ICONQUESTION);
			}
			else
				MessageBoxA(NULL, output, "serversvar:", MB_OK | MB_ICONQUESTION);
		}
	}
	};
}
