#pragma once
#include <ctime>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Event;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker3;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

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
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Tid = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Event = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker4 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->monthCalendar1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monthCalendar1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->monthCalendar1->Location = System::Drawing::Point(692, 10);
			this->monthCalendar1->Margin = System::Windows::Forms::Padding(10, 11, 10, 11);
			this->monthCalendar1->MaxDate = System::DateTime(2019, 11, 30, 0, 0, 0, 0);
			this->monthCalendar1->MinDate = System::DateTime(2019, 11, 1, 0, 0, 0, 0);
			this->monthCalendar1->MinimumSize = System::Drawing::Size(2, 2);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->ShowWeekNumbers = true;
			this->monthCalendar1->TabIndex = 1;
			this->monthCalendar1->TitleBackColor = System::Drawing::SystemColors::Desktop;
			this->monthCalendar1->TitleForeColor = System::Drawing::SystemColors::Desktop;
			this->monthCalendar1->TrailingForeColor = System::Drawing::SystemColors::Desktop;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(5, 106);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Namn på event";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(5, 196);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(280, 26);
			this->dateTimePicker1->TabIndex = 3;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(5, 228);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(280, 26);
			this->dateTimePicker2->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(5, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(280, 45);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Skapa Event";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(5, 593);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(280, 28);
			this->comboBox1->TabIndex = 7;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 20;
			this->listBox1->Location = System::Drawing::Point(5, 627);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(280, 44);
			this->listBox1->TabIndex = 8;
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(5, 677);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(280, 78);
			this->listView1->TabIndex = 9;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(5, 761);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(280, 45);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Bjud in";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::MenuHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Tid, this->Event });
			this->dataGridView1->Location = System::Drawing::Point(1065, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(327, 903);
			this->dataGridView1->TabIndex = 11;
			// 
			// Tid
			// 
			this->Tid->HeaderText = L"Tid";
			this->Tid->Name = L"Tid";
			this->Tid->ReadOnly = true;
			// 
			// Event
			// 
			this->Event->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Event->HeaderText = L"Event";
			this->Event->Name = L"Event";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(5, 401);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(280, 28);
			this->comboBox2->TabIndex = 12;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(5, 435);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(280, 45);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Ta bort Event";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(352, 452);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(280, 28);
			this->comboBox3->TabIndex = 14;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(352, 569);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(136, 45);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Acceptera";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(352, 486);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(280, 77);
			this->textBox2->TabIndex = 16;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(494, 569);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(138, 45);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Neka";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(5, 138);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(280, 52);
			this->textBox4->TabIndex = 19;
			this->textBox4->Text = L"Beskrivning";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(352, 166);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(280, 56);
			this->textBox5->TabIndex = 24;
			this->textBox5->Text = L"Beskrivning";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(352, 288);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(280, 49);
			this->button6->TabIndex = 23;
			this->button6->Text = L"Redigera Event";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker3
			// 
			this->dateTimePicker3->Location = System::Drawing::Point(352, 260);
			this->dateTimePicker3->Name = L"dateTimePicker3";
			this->dateTimePicker3->Size = System::Drawing::Size(280, 26);
			this->dateTimePicker3->TabIndex = 22;
			// 
			// dateTimePicker4
			// 
			this->dateTimePicker4->Location = System::Drawing::Point(352, 228);
			this->dateTimePicker4->Name = L"dateTimePicker4";
			this->dateTimePicker4->Size = System::Drawing::Size(280, 26);
			this->dateTimePicker4->TabIndex = 21;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(352, 138);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(280, 26);
			this->textBox6->TabIndex = 20;
			this->textBox6->Text = L"Namn på event";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(352, 104);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(280, 28);
			this->comboBox4->TabIndex = 25;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(352, 401);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 39);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Inbjudningar";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 540);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(290, 39);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Bjud in deltagare";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(13, 352);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 39);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Ta bort event";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(217, 39);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Skapa event";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(344, 52);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(302, 46);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Redigera event";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1402, 927);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->dateTimePicker3);
			this->Controls->Add(this->dateTimePicker4);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->monthCalendar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"Best kalender EU";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {



	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}

};
}
