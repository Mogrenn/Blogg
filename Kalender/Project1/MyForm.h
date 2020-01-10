#pragma once
#include <ctime>
#include <string>
#include <cmath>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "taBort.h"
#include "skapaKonto.h"
#include "rapidjson/encodings.h"
#include <curl/curl.h>
#include <algorithm>
#include <codecvt>
#include "inbjudningar.h"
#include "taBortKonto.h"
#include "redigera.h"
#include "skapa.h"
#include "iostream"
#include "bjudIn.h"
#define CURL_STATICLIB

namespace Project1 {
	using namespace rapidjson;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace rapidjson;
	using namespace std;

	namespace callback
	{
	
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
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		int curMonth;
		int curWeekDay;
		int curDay;
		int curYear;
		int markDay;
		int markMonth;
		int markYear;
		cli::array<String^>^ months = gcnew cli::array<String^>(12);

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::MenuItem^  menuItem9;
	private: System::Windows::Forms::MenuItem^  menuItem10;
	private: System::Windows::Forms::MenuItem^  menuItem11;

	public:
		int curWeek;
		MyForm(std::string id)
		{
			InitializeComponent();
			try {
				//anvandarId::anvadarId = id;
				months[0] = "Januari";
				months[1] = "Februari";
				months[2] = "Mars";
				months[3] = "April";
				months[4] = "Maj";
				months[5] = "Juni";
				months[6] = "Juli";
				months[7] = "Augusti";
				months[8] = "September";
				months[9] = "Oktober";
				months[10] = "November";
				months[11] = "December";
				time_t curday = time(0);
				tm *ltm = localtime(&curday);
				curWeekDay = ltm->tm_wday;
				curDay = ltm->tm_mday;
				curMonth = 1 + ltm->tm_mon;
				curYear = 1900+ltm->tm_year;
				curWeek = 1+ltm->tm_yday / 7;
				markDay = curDay;
				markMonth = curMonth;
				markYear = curYear;
				curDay = 1;
				curWeekDay = weekDay(1, curMonth, curYear);
				
				insertCalenderData();
				
			}
			catch (...) {
				MessageBox::Show("Det blev fel");
			};
			
		}

	public:

		void setToday() {
			time_t curday = time(0);
			tm *ltm = localtime(&curday);
			curWeekDay = ltm->tm_wday-1;
			curDay = ltm->tm_mday;
			curMonth = 1 + ltm->tm_mon;
			curYear = 1900 + ltm->tm_year;
			curWeek = 1 + ltm->tm_yday / 7;
			curDay = 1;
			insertCalenderData();
		}

		int weekDay(int day, int month, int year) {
			int y = getLastDigits(year);
			int c = getFirstDigits(year);
			int d = day;
			int m = getShiftedMonth(month);
			
			if (month > 2) {
				return  (int)(day + floor(2.6*m - 0.2) + y + floor(y / 4) + floor(c / 4) - 2 * c) % 7;
			}
			else
				return (int)(day + floor(2.6*m - 0.2) + (y - 1) + floor((y - 1) / 4) + floor(c / 4) - 2 * c) % 7;
		}

		int getLastDigits(int year) {
			return abs(year) % (int)(pow(10, 2));
		}

		int getFirstDigits(int year) {
			return floor(year / pow(10,(int(log10(year)) - 2 + 1)));
		}

		int getShiftedMonth(int month) {

			if (month >= 3) {
				return month - 2;
			}
			else {
				return month + 10;
			}
		}

		int ordinalDateCorerection(int month) {
			return 30 * (month - 1) + (int(floor(0.6*(month + 1)))) - 3;
		}

		int ordinalDateCorrectionLeapyear(int month) {
			return 30 * (month - 1) + (int(floor(0.6*(month + 1)))) - 2;
		}

		int ordinalDate(int day, int month, bool leapYear) {
			if (leapYear) {
				return ordinalDateCorrectionLeapyear(month) + day;
			}
			else {
				return ordinalDateCorerection(month) + day;
			}
		}

		int isLeapYear(int year) {
			if (year % 4 == 0) {
				return true;
			}
			else {
				return false;
			}
		}

		int getWeek() {
			return floor((ordinalDate(curDay, curMonth, isLeapYear(curYear)) - weekDay(curYear, curMonth, curDay) + 10) / 7);
		}

		void insertCalenderData() {
			
			int numberOfDays;
			curWeek = getWeek();
			if (curMonth == 4 || curMonth == 6 || curMonth == 9 || curMonth == 11)
				numberOfDays = 30;
			else if (curMonth == 2)
			{
				bool isLeapYear = (curYear % 4 == 0 && curYear % 100 != 0) || (curYear % 400 == 0);
				if (isLeapYear)
					numberOfDays = 29;
				else
					numberOfDays = 28;
			}
			else
				numberOfDays = 31;
			
			int iterationi = 1;
			int iterationj = 0;
			int iterationFound = false;
			while(curDay <= numberOfDays) {

				int weekDays[7] = { 0,0,0,0,0,0,0 };

				for (int i = 0; i < 7; i++) {

					if (curDay == numberOfDays+1) {
						break;
					}

					if (i + 1 < curWeekDay) {
						weekDays[i] = 0;
					}
					else {
						weekDays[i] = curDay;
						curDay++;
						if (curWeekDay == 7) {
							curWeekDay = 1;
						}
						else
							curWeekDay++;
					}

					if (!iterationFound)
						iterationi++;

					if (curMonth == markMonth && curYear == markYear && curDay == markDay) {
						iterationFound = true;
					}
				}
				dataGridView2->Rows->Add(curWeek, weekDays[0], weekDays[1], weekDays[2], weekDays[3], weekDays[4], weekDays[5], weekDays[6]);
				dataGridView2->Columns["Sondag"]->DefaultCellStyle->ForeColor = Color::Red;

				if (iterationFound) {
					dataGridView2->Rows[iterationj]->Cells[iterationi]->Style->BackColor = Color::Red;
				}

				if (curWeek == 52) {
					curWeek = 1;
				}else
					curWeek++;
				
				if (!iterationFound) {
					iterationj++;
					iterationi = 1;
				}
				
			}
			this->richTextBox1->Text = months[curMonth - 1] + " " + curYear;
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

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Event;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Vecka;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Mandag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tisdag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Onsdag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Torsdag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Fredag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Lordag;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Sondag;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::MainMenu^  mainMenu1;
private: System::Windows::Forms::MenuItem^  menuItem1;
private: System::Windows::Forms::MenuItem^  menuItem2;
private: System::Windows::Forms::MenuItem^  menuItem3;
private: System::Windows::Forms::MenuItem^  menuItem4;
private: System::Windows::Forms::MenuItem^  menuItem5;
private: System::Windows::Forms::MenuItem^  menuItem7;
private: System::Windows::Forms::MenuItem^  menuItem6;
private: System::Windows::Forms::MenuItem^  menuItem8;

	private: System::ComponentModel::IContainer^  components;


	protected:

	protected:

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Tid = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Event = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Vecka = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Mandag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tisdag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Onsdag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Torsdag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Fredag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Lordag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sondag = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->mainMenu1 = (gcnew System::Windows::Forms::MainMenu(this->components));
			this->menuItem1 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem2 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem3 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem4 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem5 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem7 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem6 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem8 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem9 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem10 = (gcnew System::Windows::Forms::MenuItem());
			this->menuItem11 = (gcnew System::Windows::Forms::MenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::MenuHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Tid, this->Event });
			this->dataGridView1->Location = System::Drawing::Point(882, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(314, 587);
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
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Vecka,
					this->Mandag, this->Tisdag, this->Onsdag, this->Torsdag, this->Fredag, this->Lordag, this->Sondag
			});
			this->dataGridView2->Location = System::Drawing::Point(115, 69);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 28;
			this->dataGridView2->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->Size = System::Drawing::Size(563, 350);
			this->dataGridView2->TabIndex = 31;
			this->dataGridView2->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::selectDay);
			// 
			// Vecka
			// 
			this->Vecka->FillWeight = 40.60913F;
			this->Vecka->HeaderText = L"V";
			this->Vecka->Name = L"Vecka";
			this->Vecka->ReadOnly = true;
			this->Vecka->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Mandag
			// 
			this->Mandag->FillWeight = 108.4844F;
			this->Mandag->HeaderText = L"Mån";
			this->Mandag->Name = L"Mandag";
			this->Mandag->ReadOnly = true;
			this->Mandag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Mandag->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Tisdag
			// 
			this->Tisdag->FillWeight = 108.4844F;
			this->Tisdag->HeaderText = L"Tis";
			this->Tisdag->Name = L"Tisdag";
			this->Tisdag->ReadOnly = true;
			this->Tisdag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Onsdag
			// 
			this->Onsdag->FillWeight = 108.4844F;
			this->Onsdag->HeaderText = L"Ons";
			this->Onsdag->Name = L"Onsdag";
			this->Onsdag->ReadOnly = true;
			this->Onsdag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Torsdag
			// 
			this->Torsdag->FillWeight = 108.4844F;
			this->Torsdag->HeaderText = L"Tor";
			this->Torsdag->Name = L"Torsdag";
			this->Torsdag->ReadOnly = true;
			this->Torsdag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Fredag
			// 
			this->Fredag->FillWeight = 108.4844F;
			this->Fredag->HeaderText = L"Fre";
			this->Fredag->Name = L"Fredag";
			this->Fredag->ReadOnly = true;
			this->Fredag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Lordag
			// 
			this->Lordag->FillWeight = 108.4844F;
			this->Lordag->HeaderText = L"Lör";
			this->Lordag->Name = L"Lordag";
			this->Lordag->ReadOnly = true;
			this->Lordag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Sondag
			// 
			this->Sondag->FillWeight = 108.4844F;
			this->Sondag->HeaderText = L"Sön";
			this->Sondag->Name = L"Sondag";
			this->Sondag->ReadOnly = true;
			this->Sondag->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(199, 424);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(138, 30);
			this->button7->TabIndex = 33;
			this->button7->Text = L"Föregående";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::previousMonth);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(343, 424);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(138, 30);
			this->button8->TabIndex = 34;
			this->button8->Text = L"Nuvarande";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::nuvarandeDate);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(487, 424);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(138, 30);
			this->button9->TabIndex = 35;
			this->button9->Text = L"Nästa";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::nextMonth);
			// 
			// mainMenu1
			// 
			this->mainMenu1->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(2) { this->menuItem1, this->menuItem9 });
			// 
			// menuItem1
			// 
			this->menuItem1->Index = 0;
			this->menuItem1->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(3) {
				this->menuItem2, this->menuItem6,
					this->menuItem8
			});
			this->menuItem1->Text = L"Menu";
			this->menuItem1->Click += gcnew System::EventHandler(this, &MyForm::menuItem1_Click);
			// 
			// menuItem2
			// 
			this->menuItem2->Index = 0;
			this->menuItem2->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(4) {
				this->menuItem3, this->menuItem4,
					this->menuItem5, this->menuItem7
			});
			this->menuItem2->Text = L"Event";
			// 
			// menuItem3
			// 
			this->menuItem3->Index = 0;
			this->menuItem3->Text = L"Skapa";
			this->menuItem3->Click += gcnew System::EventHandler(this, &MyForm::skapaEvent);
			// 
			// menuItem4
			// 
			this->menuItem4->Index = 1;
			this->menuItem4->Text = L"Redigera";
			this->menuItem4->Click += gcnew System::EventHandler(this, &MyForm::redigeraEvent);
			// 
			// menuItem5
			// 
			this->menuItem5->Index = 2;
			this->menuItem5->Text = L"Ta Bort";
			this->menuItem5->Click += gcnew System::EventHandler(this, &MyForm::taBortEvent);
			// 
			// menuItem7
			// 
			this->menuItem7->Index = 3;
			this->menuItem7->Text = L"Bjud in";
			this->menuItem7->Click += gcnew System::EventHandler(this, &MyForm::bjudInEvent);
			// 
			// menuItem6
			// 
			this->menuItem6->Index = 1;
			this->menuItem6->Text = L"Inbjudningar";
			this->menuItem6->Click += gcnew System::EventHandler(this, &MyForm::visaInbjudningar);
			// 
			// menuItem8
			// 
			this->menuItem8->Index = 2;
			this->menuItem8->Text = L"Logga ut";
			this->menuItem8->Click += gcnew System::EventHandler(this, &MyForm::exitApplikation);
			// 
			// menuItem9
			// 
			this->menuItem9->Index = 1;
			this->menuItem9->MenuItems->AddRange(gcnew cli::array< System::Windows::Forms::MenuItem^  >(2) { this->menuItem10, this->menuItem11 });
			this->menuItem9->Text = L"Konto";
			// 
			// menuItem10
			// 
			this->menuItem10->Index = 0;
			this->menuItem10->Text = L"Skapa";
			this->menuItem10->Click += gcnew System::EventHandler(this, &MyForm::openSkapaKonto);
			// 
			// menuItem11
			// 
			this->menuItem11->Index = 1;
			this->menuItem11->Text = L"Ta bort";
			this->menuItem11->Click += gcnew System::EventHandler(this, &MyForm::taBortkonto);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(286, 20);
			this->richTextBox1->Multiline = false;
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(214, 44);
			this->richTextBox1->TabIndex = 36;
			this->richTextBox1->Text = L"November 2019";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1244, 603);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->Menu = this->mainMenu1;
			this->Name = L"MyForm";
			this->Text = L"Best kalender EU";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::shutdown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void selectDay(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	dataGridView1->Rows->Clear();
	
	for (int i = 0; i < 24; i++) {
		dataGridView1->Rows->Add(i,1);
	}

}

private: System::Void nextMonth(System::Object^  sender, System::EventArgs^  e) {
	
	dataGridView2->Rows->Clear();
	
	if (curMonth == 12) {
		curMonth = 1;
		curYear++;
	}
	else
		curMonth++;

	curDay = 1;
	curWeekDay = weekDay(curDay, curMonth, curYear);
	if (curWeekDay == 0) {
		curWeekDay = 7;
	}
	else if (curWeekDay < 0) {
		curWeekDay += 7;
	}

	insertCalenderData();
}
private: System::Void previousMonth(System::Object^  sender, System::EventArgs^  e) {
	dataGridView2->Rows->Clear();

	if (curMonth == 1) {
		curMonth = 12;
		curYear--;
	}
	else
		curMonth--;

	curDay = 1;

	curWeekDay = weekDay(curDay, curMonth, curYear);
	
	if (curWeekDay == 0) {
		curWeekDay = 7;
	}
	else if (curWeekDay < 0) {
		curWeekDay += 7;
	}
	
	insertCalenderData();
}

private: System::Void menuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void openSkapaKonto(System::Object^  sender, System::EventArgs^  e) {
	skapaKonto^ form = gcnew skapaKonto();
	form->ShowDialog();

}
private: System::Void taBortkonto(System::Object^  sender, System::EventArgs^  e) {
	taBort^ form = gcnew taBort();
	form->ShowDialog();
}
private: System::Void skapaEvent(System::Object^  sender, System::EventArgs^  e) {
	skapa^ form = gcnew skapa();
	form->ShowDialog();
}
private: System::Void redigeraEvent(System::Object^  sender, System::EventArgs^  e) {
	redigera^ form = gcnew redigera();
	form->ShowDialog();
}
private: System::Void visaInbjudningar(System::Object^  sender, System::EventArgs^  e) {
	inbjudningar^ form = gcnew inbjudningar();
	form->ShowDialog();
}
private: System::Void exitApplikation(System::Object^  sender, System::EventArgs^  e) {
	
	this->Close();
}
private: System::Void taBortEvent(System::Object^  sender, System::EventArgs^  e) {
	taBortKonto^ form = gcnew taBortKonto();
	form->ShowDialog();
}
private: System::Void bjudInEvent(System::Object^  sender, System::EventArgs^  e) {
	bjudIn^ form = gcnew bjudIn();
	form->ShowDialog();
}
private: System::Void shutdown(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	exit(0);
}
private: System::Void nuvarandeDate(System::Object^  sender, System::EventArgs^  e) {
	dataGridView2->Rows->Clear();
	setToday();
}
};
}
