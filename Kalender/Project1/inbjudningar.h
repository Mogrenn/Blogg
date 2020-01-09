#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for inbjudningar
	/// </summary>
	public ref class inbjudningar : public System::Windows::Forms::Form
	{
	public:
		inbjudningar(void)
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
		~inbjudningar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 35);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(424, 17);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 87);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 60);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Acceptera";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(211, 87);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 60);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Ta Bort";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// inbjudningar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 249);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"inbjudningar";
			this->Text = L"inbjudningar";
			this->Load += gcnew System::EventHandler(this, &inbjudningar::inbjudningar_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void inbjudningar_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}
