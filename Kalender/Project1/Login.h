#pragma once
#include "MyForm.h"
#include <curl/curl.h>
#include <rapidjson/document.h>



namespace Project1 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace rapidjson;


	namespace test {

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

	namespace rapidjson {

		template<typename CharType = char>
		struct UTF8;

	}

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		CURL *curl;
		CURLcode res;
		Login(void)
		{
			InitializeComponent();
			curl_global_init(CURL_GLOBAL_ALL);
			curl = curl_easy_init();
		}

		void MarshalString(String ^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		void MarshalString(String ^ s, wstring& os) {
			using namespace Runtime::InteropServices;
			const wchar_t* chars =
				(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
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
			this->textBox1->Location = System::Drawing::Point(219, 74);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(195, 20);
			this->textBox1->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(219, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(195, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(219, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::validate);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(619, 270);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void validate(System::Object^  sender, System::EventArgs^  e) {

		String^ uname = this->textBox1->Text;
		std::string anamn = "asd";
		MarshalString(uname, anamn);
		String^ password = this->textBox2->Text;
		std::string losenord = "asd";
		MarshalString(password, losenord);
		std::string readBuffer;
		std::string opt = "anamn=" + anamn + "&password=" + losenord + "&tjanst=kalender";

		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://10.130.216.101/TP/Login/login.php");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, opt.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, test::callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
			res = curl_easy_perform(curl);
			if (res != CURLE_OK) {
				MessageBox::Show("Något gick fel med curl");
			}
			else {
				Document doc;
				doc.Parse(readBuffer.c_str());
				curl_easy_cleanup(curl);
				if (doc.IsObject()) {
					if (doc["success"] == true) {

						std::string s = doc["anvandarId"].GetString();
						this->Hide();
						MyForm^ form = gcnew MyForm(s);
						form->ShowDialog();
					}
				}
			}
			curl_global_cleanup();
		}
	}
	};
}
