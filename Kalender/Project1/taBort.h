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

	namespace UTF4{
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
	inline std::string namefordeletion(){
			CURL *curl1;
			CURLcode ret;
			int httpCode(0);
			std::string readBuffer;

			if (curl1) {
				const char* url = "10.130.216.101/TP/Kalender/json/kalenderjson.php";
				std::string param = "nyckel=iRxOUsizwhoXddb4&tjanstId=47";
				const char *data = param.c_str();
				curl_easy_setopt(curl1, CURLOPT_URL, url);
				curl_easy_getinfo(curl1, CURLINFO_RESPONSE_CODE, &httpCode);
				curl_easy_setopt(curl1, CURLOPT_POSTFIELDS, data);
				curl_easy_setopt(curl1, CURLOPT_WRITEFUNCTION, UTF4::callback);
				curl_easy_setopt(curl1, CURLOPT_WRITEDATA, &readBuffer);

				ret = curl_easy_perform(curl1);
				if (ret != CURLE_OK)
					Console::Write("fel på begäran");

				std::cout << readBuffer;
				curl_easy_cleanup(curl1);
				const char* json = readBuffer.c_str();

				Document d;
				d.Parse(json);
				std::string namn = d["anamn"].GetString();
				
				return namn;
			}
	}

	
	/// <summary>
	/// Summary for taBort
	/// </summary>

	public ref class taBort : public System::Windows::Forms::Form
	{

	public:
		CURL *curl;
		
		CURLcode res;
		
	public:
		taBort(void)
		{
			InitializeComponent();
			curl_global_init(CURL_GLOBAL_ALL);
			curl = curl_easy_init();
			try{
			namefordeletion();
			//this->listBox1->Items->Add("lelleborg" );
			}
			catch(...){
				MessageBox::Show("det blev inte som det skulle");
			};
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~taBort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:

	protected:

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			
			this->listBox1->Location = System::Drawing::Point(35, 50);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(211, 17);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(60, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 47);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &taBort::button1_Click);
			// 
			// taBort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 188);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"taBort";
			this->Text = L"taBort";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Windows::Forms::DialogResult test = MessageBox::Show("Är du säker", "dubbel koll", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (test == System::Windows::Forms::DialogResult::Yes) {
			int httpCode(0);
			std::string readBuffer;
			if (curl) {
				String^ choice = "this->listBox1->GetSelected()";
				const char* url = "10.130.216.101/TP/Admin/funktioner/tabort.php";
				std::string param = "nyckel=iRxOUsizwhoXddb4&funktion=skapaAKonto&anvandarid="+msclr::interop::marshal_as<std::string>(choice);
				const char *data = param.c_str();
				curl_easy_setopt(curl, CURLOPT_URL, url);
				curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
				curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, UTF4::callback);
				curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

				res = curl_easy_perform(curl);
				if (res != CURLE_OK)
					Console::Write("fel på begäran");

				std::cout << readBuffer;
				curl_easy_cleanup(curl);

				const char* json = readBuffer.c_str();

				Document d;
				d.Parse(json);
				std::string anvandare = d["username"].GetString();
				std::string losen = d["password"].GetString();
				std::string msg = anvandare + " skapad, lösenord: " + losen;
				StringBuffer buffer;
				Writer<StringBuffer, Document::EncodingType, UTF8<> > writer(buffer);
				d.Accept(writer);
				const char* output = buffer.GetString();
				std::cout << output;

				if (output == NULL) {
					MessageBoxA(NULL, "fel på begäran/ upptaget användarnamn", "serversvar:", MB_OK | MB_ICONQUESTION);
				}
				else
					MessageBoxA(NULL, msg.c_str(), "serversvar:", MB_OK | MB_ICONQUESTION);
			}
			
		}
		curl_global_cleanup();
		this->Close();
	}
	};
}
