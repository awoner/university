#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iostream>
#include <functional>
#include <sstream>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <regex>
#include <cstdlib>
#include "MyForm.h"
#include "MyForm1.h"
namespace Курсач {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Printing;
	/// <summary>
	/// Сводка для Form1
	/// </summary>
	
	string path="Безимянный";
	string filename="Безимянный.txt";
	string startText = "";
  

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(/*String^ text*/)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
		 // Search_Text->Visible = false;	//
			//Search_Text->Text = text;
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сОздатьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьКакToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;



	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  правкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  отменитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  вырезатьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  копироватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вставитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  удалитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem4;




	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  выделитьВсеToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  видToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  просмотретьСправкуToolStripMenuItem;


	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  вырезатьToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  копироватьToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  вставитьToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  удалитьToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  найтиToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  шрифтToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  переносКурсораНаЦентрToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  Search_Text;
	private: System::Windows::Forms::ToolStripMenuItem^  печатьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::PrintDialog^  printDialog1;
	private: System::Drawing::Printing::PrintDocument^  printDocument1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сОздатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->печатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->правкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->отменитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->вырезатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->копироватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вставитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->найтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->выделитьВсеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->переносКурсораНаЦентрToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->шрифтToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->просмотретьСправкуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->вырезатьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->копироватьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вставитьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Search_Text = (gcnew System::Windows::Forms::TextBox());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocument1 = (gcnew System::Drawing::Printing::PrintDocument());
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Gainsboro;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->файлToolStripMenuItem, 
				this->правкаToolStripMenuItem, this->видToolStripMenuItem, this->справкаToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(331, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->сОздатьToolStripMenuItem, 
				this->открытьToolStripMenuItem, this->сохранитьToolStripMenuItem, this->сохранитьКакToolStripMenuItem, this->toolStripMenuItem1, 
				this->печатьToolStripMenuItem, this->toolStripMenuItem2, this->выходToolStripMenuItem});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::файлToolStripMenuItem_Click);
			// 
			// сОздатьToolStripMenuItem
			// 
			this->сОздатьToolStripMenuItem->Name = L"сОздатьToolStripMenuItem";
			this->сОздатьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->сОздатьToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->сОздатьToolStripMenuItem->Text = L"Создать";
			this->сОздатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сОздатьToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть...";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сохранитьToolStripMenuItem_Click);
			// 
			// сохранитьКакToolStripMenuItem
			// 
			this->сохранитьКакToolStripMenuItem->Name = L"сохранитьКакToolStripMenuItem";
			this->сохранитьКакToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->сохранитьКакToolStripMenuItem->Text = L"Сохранить как...";
			this->сохранитьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сохранитьКакToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(170, 6);
			// 
			// печатьToolStripMenuItem
			// 
			this->печатьToolStripMenuItem->Name = L"печатьToolStripMenuItem";
			this->печатьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
			this->печатьToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->печатьToolStripMenuItem->Text = L"Печать";
			this->печатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::печатьToolStripMenuItem_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(170, 6);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// правкаToolStripMenuItem
			// 
			this->правкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->отменитьToolStripMenuItem, 
				this->toolStripMenuItem3, this->вырезатьToolStripMenuItem, this->копироватьToolStripMenuItem, this->вставитьToolStripMenuItem, 
				this->удалитьToolStripMenuItem, this->toolStripMenuItem4, this->найтиToolStripMenuItem, this->toolStripMenuItem5, this->выделитьВсеToolStripMenuItem, 
				this->переносКурсораНаЦентрToolStripMenuItem});
			this->правкаToolStripMenuItem->Name = L"правкаToolStripMenuItem";
			this->правкаToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->правкаToolStripMenuItem->Text = L"Правка";
			this->правкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::правкаToolStripMenuItem_Click);
			// 
			// отменитьToolStripMenuItem
			// 
			this->отменитьToolStripMenuItem->Name = L"отменитьToolStripMenuItem";
			this->отменитьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->отменитьToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->отменитьToolStripMenuItem->Text = L"Отменить";
			this->отменитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::отменитьToolStripMenuItem_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(277, 6);
			// 
			// вырезатьToolStripMenuItem
			// 
			this->вырезатьToolStripMenuItem->Name = L"вырезатьToolStripMenuItem";
			this->вырезатьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->вырезатьToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->вырезатьToolStripMenuItem->Text = L"Вырезать";
			this->вырезатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::вырезатьToolStripMenuItem_Click);
			// 
			// копироватьToolStripMenuItem
			// 
			this->копироватьToolStripMenuItem->Name = L"копироватьToolStripMenuItem";
			this->копироватьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->копироватьToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->копироватьToolStripMenuItem->Text = L"Копировать";
			this->копироватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::копироватьToolStripMenuItem_Click);
			// 
			// вставитьToolStripMenuItem
			// 
			this->вставитьToolStripMenuItem->Name = L"вставитьToolStripMenuItem";
			this->вставитьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->вставитьToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->вставитьToolStripMenuItem->Text = L"Вставить";
			this->вставитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::вставитьToolStripMenuItem_Click);
			// 
			// удалитьToolStripMenuItem
			// 
			this->удалитьToolStripMenuItem->Name = L"удалитьToolStripMenuItem";
			this->удалитьToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::Delete;
			this->удалитьToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->удалитьToolStripMenuItem->Text = L"Удалить";
			this->удалитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::удалитьToolStripMenuItem_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(277, 6);
			// 
			// найтиToolStripMenuItem
			// 
			this->найтиToolStripMenuItem->Name = L"найтиToolStripMenuItem";
			this->найтиToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->найтиToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->найтиToolStripMenuItem->Text = L"Найти";
			this->найтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::найтиToolStripMenuItem_Click_1);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(277, 6);
			// 
			// выделитьВсеToolStripMenuItem
			// 
			this->выделитьВсеToolStripMenuItem->Name = L"выделитьВсеToolStripMenuItem";
			this->выделитьВсеToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->выделитьВсеToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->выделитьВсеToolStripMenuItem->Text = L"Выбрать всё";
			this->выделитьВсеToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выделитьВсеToolStripMenuItem_Click);
			// 
			// переносКурсораНаЦентрToolStripMenuItem
			// 
			this->переносКурсораНаЦентрToolStripMenuItem->CheckOnClick = true;
			this->переносКурсораНаЦентрToolStripMenuItem->Name = L"переносКурсораНаЦентрToolStripMenuItem";
			this->переносКурсораНаЦентрToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::K));
			this->переносКурсораНаЦентрToolStripMenuItem->Size = System::Drawing::Size(280, 22);
			this->переносКурсораНаЦентрToolStripMenuItem->Text = L"Переместить курсор на центр";
			this->переносКурсораНаЦентрToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::переносКурсораНаЦентрToolStripMenuItem_Click);
			// 
			// видToolStripMenuItem
			// 
			this->видToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->шрифтToolStripMenuItem});
			this->видToolStripMenuItem->Name = L"видToolStripMenuItem";
			this->видToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->видToolStripMenuItem->Text = L"Вид";
			// 
			// шрифтToolStripMenuItem
			// 
			this->шрифтToolStripMenuItem->Name = L"шрифтToolStripMenuItem";
			this->шрифтToolStripMenuItem->Size = System::Drawing::Size(122, 22);
			this->шрифтToolStripMenuItem->Text = L"Шрифт...";
			this->шрифтToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::шрифтToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->просмотретьСправкуToolStripMenuItem});
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// просмотретьСправкуToolStripMenuItem
			// 
			this->просмотретьСправкуToolStripMenuItem->Name = L"просмотретьСправкуToolStripMenuItem";
			this->просмотретьСправкуToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->просмотретьСправкуToolStripMenuItem->Text = L"О Програме ";
			this->просмотретьСправкуToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::просмотретьСправкуToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->richTextBox1->Location = System::Drawing::Point(0, 46);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(331, 256);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->вырезатьToolStripMenuItem1, 
				this->копироватьToolStripMenuItem1, this->вставитьToolStripMenuItem1, this->удалитьToolStripMenuItem1});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(140, 92);
			// 
			// вырезатьToolStripMenuItem1
			// 
			this->вырезатьToolStripMenuItem1->Name = L"вырезатьToolStripMenuItem1";
			this->вырезатьToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->вырезатьToolStripMenuItem1->Text = L"Вырезать";
			this->вырезатьToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::вырезатьToolStripMenuItem_Click);
			// 
			// копироватьToolStripMenuItem1
			// 
			this->копироватьToolStripMenuItem1->Name = L"копироватьToolStripMenuItem1";
			this->копироватьToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->копироватьToolStripMenuItem1->Text = L"Копировать";
			this->копироватьToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::копироватьToolStripMenuItem_Click);
			// 
			// вставитьToolStripMenuItem1
			// 
			this->вставитьToolStripMenuItem1->Name = L"вставитьToolStripMenuItem1";
			this->вставитьToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->вставитьToolStripMenuItem1->Text = L"Вставить";
			this->вставитьToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::вставитьToolStripMenuItem_Click);
			// 
			// удалитьToolStripMenuItem1
			// 
			this->удалитьToolStripMenuItem1->Name = L"удалитьToolStripMenuItem1";
			this->удалитьToolStripMenuItem1->Size = System::Drawing::Size(139, 22);
			this->удалитьToolStripMenuItem1->Text = L"Удалить";
			this->удалитьToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::удалитьToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Search_Text
			// 
			this->Search_Text->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->Search_Text->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Search_Text->Location = System::Drawing::Point(0, 27);
			this->Search_Text->MinimumSize = System::Drawing::Size(331, 16);
			this->Search_Text->Name = L"Search_Text";
			this->Search_Text->Size = System::Drawing::Size(331, 16);
			this->Search_Text->TabIndex = 2;
			this->Search_Text->TextChanged += gcnew System::EventHandler(this, &Form1::Search_Text_TextChanged);
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 301);
			this->Controls->Add(this->Search_Text);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Joint - Text Editior ";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static System::String^ stdtosys(string str){
			 
			 return gcnew System::String(str.c_str());
			 
			 }

			 static const string SysToStd(System::String^ SysStr){
				 using namespace Runtime::InteropServices;
				 return(const char*)(Marshal::StringToHGlobalAnsi(SysStr)).ToPointer();
			 }

			 

	private: System::Void сОздатьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

  if( richTextBox1->Modified==true ) { 
			 System::Windows::Forms::DialogResult res;
			 res = MessageBox::Show("Сохранить изменения в файле "+((String^)gcnew String(filename.c_str()))+"? ", "Блокнот",MessageBoxButtons::YesNoCancel);
			 switch(res)
			{
			case System::Windows::Forms::DialogResult::Yes:
				 saveFileDialog1->DefaultExt = "*.txt";
      saveFileDialog1->Filter = "txt files (*.txt)|*.txt|rtf files (*.rtf)|*.rtf|doc files (*.doc)|*.doc|All files (*.*)|*.*";;
			if(path == "Безимянный.txt")
			if(saveFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK) {
				path = SysToStd(saveFileDialog1->FileName);
				richTextBox1->SaveFile(stdtosys(path), RichTextBoxStreamType::PlainText);
					MessageBox::Show("Изменения сохранены.");richTextBox1->Clear();
			}
				break;
			case System::Windows::Forms::DialogResult::No:
				richTextBox1->Clear();

			break;
			case System::Windows::Forms::DialogResult::Cancel:
			break;
			}
			 
		 }
		 

			 }
private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 if(openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK) {
				path = SysToStd(openFileDialog1->FileName);
				filename = SysToStd(openFileDialog1->FileName);//обрезать путь к файлу до его имени
				richTextBox1->LoadFile(stdtosys(path), RichTextBoxStreamType::PlainText);
			}
		 }
private: System::Void сохранитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(path == "Безимянный.txt"){
			if(saveFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK) {
				path = SysToStd(saveFileDialog1->FileName);
				
				richTextBox1->SaveFile(stdtosys(path), RichTextBoxStreamType::PlainText);
			}}else richTextBox1->SaveFile(stdtosys(path), RichTextBoxStreamType::PlainText);

		 }
private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
      if( richTextBox1->Modified==true ) { 
			 System::Windows::Forms::DialogResult res;
			 res = MessageBox::Show("Сохранить изменения в файле "+((String^)gcnew String(filename.c_str()))+"? ", "Блокнот",MessageBoxButtons::YesNoCancel);
			 switch(res)
			{
			case System::Windows::Forms::DialogResult::Yes:
				   saveFileDialog1->DefaultExt = "*.txt";
      saveFileDialog1->Filter = "txt files (*.txt)|*.txt|rtf files (*.rtf)|*.rtf|doc files (*.doc)|*.doc|All files (*.*)|*.*";;
			if(path == "Безимянный.txt")MessageBox::Show("Изменения сохранены.");
			if(saveFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK) {
				path = SysToStd(saveFileDialog1->FileName);
				richTextBox1->SaveFile(stdtosys(path), RichTextBoxStreamType::PlainText);
				
				Application::Exit();
			}
				break;
			case System::Windows::Forms::DialogResult::No:
				richTextBox1->Clear();
					Application::Exit();
			break;
			case System::Windows::Forms::DialogResult::Cancel:
			break;
			}
			 }else{Application::Exit();}
		 }
private: System::Void копироватьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Copy(); 
		 }
private: System::Void вырезатьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			richTextBox1->Cut();
		 }
private: System::Void вставитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Paste();
		 }
private: System::Void удалитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->SelectedText=" ";
		 }
private: System::Void отменитьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if ( richTextBox1->CanUndo == true )
      {
		  richTextBox1->Undo();    
		  richTextBox1->ClearUndo();
      }
		 }
private: System::Void выделитьВсеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if ( richTextBox1->SelectionLength == 0 )
      {
         richTextBox1->SelectAll();
      }
      richTextBox1->Copy();
		 }






private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void шрифтToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
 FontDialog^ fontDialog1 = gcnew FontDialog;
			 fontDialog1->ShowColor = true;

      fontDialog1->Font = richTextBox1->Font;
      fontDialog1->Color = richTextBox1->ForeColor;

      if ( fontDialog1->ShowDialog() != System::Windows::Forms::DialogResult::Cancel )
      {
         richTextBox1->Font = fontDialog1->Font;
         richTextBox1->ForeColor = fontDialog1->Color;
      }
		 }
private: System::Void сохранитьКакToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
 SaveFileDialog^ saveFile1 = gcnew SaveFileDialog;

    
      saveFile1->DefaultExt = "*.txt";
      saveFile1->Filter = "txt files (*.txt)|*.txt|rtf files (*.rtf)|*.rtf|doc files (*.doc)|*.doc|All files (*.*)|*.*";;

      // Determine if the user selected a file name from the saveFileDialog.
      if ( saveFile1->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
         saveFile1->FileName->Length > 0 )
      {
         
         richTextBox1->SaveFile( saveFile1->FileName, RichTextBoxStreamType::PlainText );
      }
		 }
private: System::Void правкаToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->переносКурсораНаЦентрToolStripMenuItem->CheckOnClick==false){
				 this->переносКурсораНаЦентрToolStripMenuItem->Checked=true;
				 this->переносКурсораНаЦентрToolStripMenuItem->CheckOnClick=true;
			 }else{
			 this->переносКурсораНаЦентрToolStripMenuItem->Checked=false;
			 this->переносКурсораНаЦентрToolStripMenuItem->CheckOnClick=false;
			 }
		 }
private: System::Void переносКурсораНаЦентрToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(переносКурсораНаЦентрToolStripMenuItem->CheckOnClick==true){
				richTextBox1->SelectionAlignment = HorizontalAlignment::Left;
			}else{
				richTextBox1->SelectionAlignment = HorizontalAlignment::Center;
			}
		 }
private: System::Void найтиToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
			
			 MyForm^ Form2 = gcnew MyForm();
			  Form2->ShowDialog();
			
			 int var=1;
			 if (Search_Text->TextLength == 0)
				 MessageBox::Show("Please Enter data");
			 else
			 {
				 int index = 0;
				 var = 0;
				 String^ temp = richTextBox1->Text;
				 richTextBox1->Text = "";
				 richTextBox1->Text = temp;
				 while (index < richTextBox1->Text->LastIndexOf(Search_Text->Text))
				 {

					 richTextBox1->Find(Search_Text->Text, index, richTextBox1->TextLength, RichTextBoxFinds::None);
					 richTextBox1->SelectionBackColor = Color::Red;
					 index = richTextBox1->Text->IndexOf(Search_Text->Text, index) + 1;
					 var++;
				 }
			 }
			 if (!var)
			 {
				 MessageBox::Show("NO Match Found");
				 Search_Text->Clear();
			 }

		 } 
			 
private: System::Void Search_Text_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			
        /* Search_Text->Visible = false;*/
		 }





	private: System::Void printDocument1_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
	e->Graphics->DrawString(richTextBox1->Text, richTextBox1->Font, Brushes::Black, (float)80, (float)80);

}		






private: System::Void печатьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	printDialog1->ShowDialog();
	if (DialogResult == System::Windows::Forms::DialogResult::OK)
	{
		printDocument1->Print();
	}
		 }
private: System::Void просмотретьСправкуToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  MyForm1^ form1 = gcnew MyForm1;
     
      Button^ button1 = gcnew Button;
      Button^ button2 = gcnew Button;
	  

      button1->Text = "OK";
   
      button1->Location = Point(10,10);

      form1->Text = "О Программе";
      
      form1->HelpButton = true;
	  
     
      form1->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;

      form1->MaximizeBox = false;      
  
      form1->MinimizeBox = false;
    
      
   
      form1->CancelButton = button1;
   
      form1->StartPosition = FormStartPosition::CenterScreen;

  
      form1->Controls->Add( button1 );
   
      form1->ShowDialog();
		 }
private: System::Void файлToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

