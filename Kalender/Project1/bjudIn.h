#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for bjudIn
	/// </summary>
	public ref class bjudIn : public System::Windows::Forms::Form
	{
	public:
		bjudIn(void)
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
		~bjudIn()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::ListView^  listView1;
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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 44);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(360, 17);
			this->listBox1->TabIndex = 0;
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(35, 67);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(292, 53);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 42);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Skicka";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(193, 126);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 42);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Avbryt";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// bjudIn
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 211);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->listBox1);
			this->Name = L"bjudIn";
			this->Text = L"bjudIn";
			this->ResumeLayout(false);

		}
#pragma endregion

};
}
