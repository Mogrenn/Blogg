#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for taBortKonto
	/// </summary>
	public ref class taBortKonto : public System::Windows::Forms::Form
	{
	public:
		taBortKonto(void)
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
		~taBortKonto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

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
			this->listBox1->Location = System::Drawing::Point(12, 47);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(303, 17);
			this->listBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(101, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Ta Bort";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// taBortKonto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(327, 226);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Name = L"taBortKonto";
			this->Text = L"taBortKonto";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

