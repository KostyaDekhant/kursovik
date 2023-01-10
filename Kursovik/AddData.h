#pragma once
#include "Faculty.h"
namespace Kursovik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddData
	/// </summary>
	public ref class AddData : public System::Windows::Forms::Form
	{
	public:
		AddData(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddData()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяToolStripMenuItem;
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	public: int* Row_del_index = new int[1000];
	public:	int* DeletedRows = new int[1000];
	private: static bool flag_for_dash = false;
	public: System::Windows::Forms::ComboBox^ comboBox1;
	public: System::Windows::Forms::ComboBox^ comboBox2;
	public: System::Windows::Forms::ComboBox^ comboBox3;
	public: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Button^ add_groups;
	public: int data_volume = 5;
	//private: int GridSize = 0;
	//private: bool Flag_for_checkbox = false;
	//private: Faculty* fac = new class Faculty[10];
	//private: Directions* direct = new class Directions[20];
	//private: Groups* group = new class Groups[10];
	//private: Students* stud = new class Students[40];

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ add_stud;

	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ save_data_bttn;
	private: System::Windows::Forms::Button^ del_bttn;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox3;
	private: System::Windows::Forms::Button^ years_add_bttn;
	private: System::Windows::Forms::Label^ years_label;
	private: System::Windows::Forms::Button^ directions_add_bttn;
	private: System::Windows::Forms::Label^ dir_label;
	private: System::Windows::Forms::Button^ faculty_add_bttn;
	private: System::Windows::Forms::Label^ new_f_label;
	private: System::Windows::Forms::TextBox^ textBox_faculty;
	private: System::Windows::Forms::TextBox^ textBox_directions;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox_directions;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;











	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->add_groups = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->add_stud = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox_directions = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox_directions = (gcnew System::Windows::Forms::TextBox());
			this->textBox_faculty = (gcnew System::Windows::Forms::TextBox());
			this->years_add_bttn = (gcnew System::Windows::Forms::Button());
			this->years_label = (gcnew System::Windows::Forms::Label());
			this->directions_add_bttn = (gcnew System::Windows::Forms::Button());
			this->dir_label = (gcnew System::Windows::Forms::Label());
			this->faculty_add_bttn = (gcnew System::Windows::Forms::Button());
			this->new_f_label = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->del_bttn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->save_data_bttn = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->файлToolStripMenuItem,
					this->вернутьсяToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1183, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// вернутьсяToolStripMenuItem
			// 
			this->вернутьсяToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->вернутьсяToolStripMenuItem->Name = L"вернутьсяToolStripMenuItem";
			this->вернутьсяToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->вернутьсяToolStripMenuItem->Text = L"Вернуться";
			this->вернутьсяToolStripMenuItem->Click += gcnew System::EventHandler(this, &AddData::вернутьсяToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataGridView1->Location = System::Drawing::Point(25, 101);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(502, 347);
			this->dataGridView1->TabIndex = 1;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(25, 65);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AddData::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(152, 65);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &AddData::comboBox2_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(279, 65);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 3;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &AddData::comboBox3_SelectedIndexChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(406, 65);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 21);
			this->comboBox4->TabIndex = 3;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &AddData::comboBox4_SelectedIndexChanged);
			// 
			// add_groups
			// 
			this->add_groups->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->add_groups->Location = System::Drawing::Point(395, 109);
			this->add_groups->Name = L"add_groups";
			this->add_groups->Size = System::Drawing::Size(114, 20);
			this->add_groups->TabIndex = 4;
			this->add_groups->Text = L"Добавить группы";
			this->add_groups->UseVisualStyleBackColor = true;
			this->add_groups->Click += gcnew System::EventHandler(this, &AddData::add_groups_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(255, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Количество групп";
			// 
			// add_stud
			// 
			this->add_stud->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->add_stud->Location = System::Drawing::Point(168, 19);
			this->add_stud->Name = L"add_stud";
			this->add_stud->Size = System::Drawing::Size(75, 21);
			this->add_stud->TabIndex = 8;
			this->add_stud->Text = L"Добавить";
			this->add_stud->UseVisualStyleBackColor = true;
			this->add_stud->Click += gcnew System::EventHandler(this, &AddData::add_stud_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->maskedTextBox_directions);
			this->groupBox1->Controls->Add(this->textBox_directions);
			this->groupBox1->Controls->Add(this->textBox_faculty);
			this->groupBox1->Controls->Add(this->years_add_bttn);
			this->groupBox1->Controls->Add(this->years_label);
			this->groupBox1->Controls->Add(this->directions_add_bttn);
			this->groupBox1->Controls->Add(this->dir_label);
			this->groupBox1->Controls->Add(this->faculty_add_bttn);
			this->groupBox1->Controls->Add(this->new_f_label);
			this->groupBox1->Controls->Add(this->maskedTextBox3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->add_groups);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(542, 101);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(534, 159);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Создание объектов";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(102, 108);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(21, 20);
			this->maskedTextBox1->TabIndex = 24;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(255, 74);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Количество лет";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(254, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 22;
			// 
			// maskedTextBox_directions
			// 
			this->maskedTextBox_directions->Location = System::Drawing::Point(347, 71);
			this->maskedTextBox_directions->Name = L"maskedTextBox_directions";
			this->maskedTextBox_directions->Size = System::Drawing::Size(21, 20);
			this->maskedTextBox_directions->TabIndex = 21;
			// 
			// textBox_directions
			// 
			this->textBox_directions->Location = System::Drawing::Point(257, 45);
			this->textBox_directions->Name = L"textBox_directions";
			this->textBox_directions->Size = System::Drawing::Size(111, 20);
			this->textBox_directions->TabIndex = 20;
			// 
			// textBox_faculty
			// 
			this->textBox_faculty->Location = System::Drawing::Point(12, 45);
			this->textBox_faculty->Name = L"textBox_faculty";
			this->textBox_faculty->Size = System::Drawing::Size(111, 20);
			this->textBox_faculty->TabIndex = 19;
			// 
			// years_add_bttn
			// 
			this->years_add_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->years_add_bttn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->years_add_bttn->Location = System::Drawing::Point(129, 108);
			this->years_add_bttn->Name = L"years_add_bttn";
			this->years_add_bttn->Size = System::Drawing::Size(114, 20);
			this->years_add_bttn->TabIndex = 18;
			this->years_add_bttn->Text = L"Добавить курсы";
			this->years_add_bttn->UseVisualStyleBackColor = true;
			this->years_add_bttn->Click += gcnew System::EventHandler(this, &AddData::years_add_bttn_Click);
			// 
			// years_label
			// 
			this->years_label->AutoSize = true;
			this->years_label->Location = System::Drawing::Point(19, 113);
			this->years_label->Name = L"years_label";
			this->years_label->Size = System::Drawing::Size(39, 13);
			this->years_label->TabIndex = 17;
			this->years_label->Text = L"Курсы";
			// 
			// directions_add_bttn
			// 
			this->directions_add_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->directions_add_bttn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->directions_add_bttn->Location = System::Drawing::Point(374, 45);
			this->directions_add_bttn->Name = L"directions_add_bttn";
			this->directions_add_bttn->Size = System::Drawing::Size(135, 20);
			this->directions_add_bttn->TabIndex = 16;
			this->directions_add_bttn->Text = L"Добавить направление";
			this->directions_add_bttn->UseVisualStyleBackColor = true;
			this->directions_add_bttn->Click += gcnew System::EventHandler(this, &AddData::directions_add_bttn_Click);
			// 
			// dir_label
			// 
			this->dir_label->AutoSize = true;
			this->dir_label->Location = System::Drawing::Point(254, 23);
			this->dir_label->Name = L"dir_label";
			this->dir_label->Size = System::Drawing::Size(75, 13);
			this->dir_label->TabIndex = 15;
			this->dir_label->Text = L"Направления";
			// 
			// faculty_add_bttn
			// 
			this->faculty_add_bttn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->faculty_add_bttn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->faculty_add_bttn->Location = System::Drawing::Point(129, 45);
			this->faculty_add_bttn->Name = L"faculty_add_bttn";
			this->faculty_add_bttn->Size = System::Drawing::Size(114, 20);
			this->faculty_add_bttn->TabIndex = 14;
			this->faculty_add_bttn->Text = L"Добавить факультет";
			this->faculty_add_bttn->UseVisualStyleBackColor = true;
			this->faculty_add_bttn->Click += gcnew System::EventHandler(this, &AddData::faculty_add_bttn_Click);
			// 
			// new_f_label
			// 
			this->new_f_label->AutoSize = true;
			this->new_f_label->Location = System::Drawing::Point(9, 23);
			this->new_f_label->Name = L"new_f_label";
			this->new_f_label->Size = System::Drawing::Size(63, 13);
			this->new_f_label->TabIndex = 13;
			this->new_f_label->Text = L"Факультет";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(363, 109);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(15, 20);
			this->maskedTextBox3->TabIndex = 12;
			this->maskedTextBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddData::maskedTextBox3_KeyPress);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(143, 20);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(17, 20);
			this->maskedTextBox2->TabIndex = 9;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Количество студентов:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->del_bttn);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->maskedTextBox2);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->save_data_bttn);
			this->groupBox3->Controls->Add(this->add_stud);
			this->groupBox3->Controls->Add(this->checkBox1);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Location = System::Drawing::Point(542, 297);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(249, 151);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Редактировать список";
			// 
			// del_bttn
			// 
			this->del_bttn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->del_bttn->Location = System::Drawing::Point(143, 93);
			this->del_bttn->Name = L"del_bttn";
			this->del_bttn->Size = System::Drawing::Size(100, 21);
			this->del_bttn->TabIndex = 12;
			this->del_bttn->Text = L"Удалить";
			this->del_bttn->UseVisualStyleBackColor = true;
			this->del_bttn->Click += gcnew System::EventHandler(this, &AddData::del_bttn_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::SystemColors::Control;
			this->label5->Location = System::Drawing::Point(6, 77);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Укажите строки:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 94);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddData::textBox1_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 124);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Сохранить данные:";
			// 
			// save_data_bttn
			// 
			this->save_data_bttn->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->save_data_bttn->Location = System::Drawing::Point(143, 119);
			this->save_data_bttn->Name = L"save_data_bttn";
			this->save_data_bttn->Size = System::Drawing::Size(100, 23);
			this->save_data_bttn->TabIndex = 2;
			this->save_data_bttn->Text = L"Сохранить данные";
			this->save_data_bttn->UseVisualStyleBackColor = true;
			this->save_data_bttn->Click += gcnew System::EventHandler(this, &AddData::save_data_bttn_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(143, 54);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &AddData::checkBox1_CheckedChanged);
			this->checkBox1->Click += gcnew System::EventHandler(this, &AddData::checkBox1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Редактирование списка:";
			// 
			// AddData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(1183, 605);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AddData";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddData";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AddData::AddData_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AddData::AddData_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void вернутьсяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddData_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void AddData_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SelectGrid(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void ChangeYear();
	private: System::Void LoadForm();
	public: System::Void ShiftData(int temp_shift);
	public: System::Void AddComboBoxFaculty(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4);
	public: System::Void AddComboBoxDirect(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4);
	public: System::Void AddComboBoxYears(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4);
	public: System::Void AddComboBoxGroups(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4);
	public: System::Void PrintStudents(int index_fac, int index_dir, int index_you, int index_groups, DataGridView^ dataGridView1);
	public: System::Void OpenFileFacult();
	private: System::Void OpenFileDirect(int index_fac);
	private: System::Void OpenFileYears(int index_fac, int index_dir);
	private: System::Void OpenFileGroups(int index_fac, int index_dir, int index_you);
	private: System::Void OpenFileStudents(int index_fac, int index_dir, int index_you, int index_groups);
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddGroup();
	private: System::Void CreateYear(int index_fac, int index_dir, int index_you);
	private: System::Void CreateYearNames(int index_fac, int index_dir);
	private: System::Void CreateFaculty(); //, int dir_count
	private: System::Void CreateDirections();
	private: System::Void CreateGrid();
	private: System::Void CreateFiles(int flag, int index_fac, int index_dir, int index_you, int index_groups);
	private: System::Void PrintClasses();
	public: System::Void rowcountchanged();
	private: System::Void ClearGrid(int size);
	private: System::Void add_groups_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_stud_Click(System::Object^ sender, System::EventArgs^ e);
	public: System::Void set_header_num(DataGridView^ dataGridView1);
	private: System::Boolean check_data_grid();
	public: System::Void del_rows(int count_of_nums, int RowCount_dg);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void save_data_bttn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Boolean check_next_symbol(char symbol, int lensym);
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void del_bttn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Boolean RowWasDeleted(int* DeletedRows, int rowindex, int rowcount);
	private: System::Void clear_variables_for_del(int rowcount);
	private: System::Void sort_array(int count_of_nums);
	private: System::Void simple_sort(int i, int j);
	private: System::Void maskedTextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
	private: System::Void faculty_add_bttn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void directions_add_bttn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void years_add_bttn_Click(System::Object^ sender, System::EventArgs^ e);
	public:  System::Void getFac(Faculty* facult);
};
}
