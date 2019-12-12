#pragma once
#include "curl/curl.h"
#include "rapidjson/document.h"
#include <cstring>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace rapidjson;

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
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Joel", L"Brandon", L"Alvar", L"Viktor" });
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
			//Skriv i json här för att delete konto
			if (curl) {
				curl_easy_setopt(curl, CURLOPT_URL, "http://10.130.216.101/TP/Admin/funktioner/tabort.php");
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "name=daniel");
				res = curl_easy_perform(curl);
				if (res != CURLE_OK) {
					Console::Write("Hej ");

				}
				else {
					/*
					
					Document* doc;
					doc->Parse(res.ToString);
					*/
				}
				curl_easy_cleanup(curl);
			}
		}
		curl_global_cleanup();
		this->Close();
	}
	};
}
