#pragma once

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
	private:
	public: int* Row_del_index = new int[1000];
	public:	int* DeletedRows = new int[1000];
	private: static bool flag_for_dash = false;
	public: System::Windows::Forms::ComboBox^ comboBox1;
	public: System::Windows::Forms::ComboBox^ comboBox2;
	public: System::Windows::Forms::ComboBox^ comboBox3;
	public: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Button^ add_groups;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;

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
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->add_stud = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
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
			this->menuStrip1->Size = System::Drawing::Size(1096, 24);
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
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataGridView1->Location = System::Drawing::Point(25, 101);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(502, 317);
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
			this->add_groups->Location = System::Drawing::Point(129, 26);
			this->add_groups->Name = L"add_groups";
			this->add_groups->Size = System::Drawing::Size(114, 20);
			this->add_groups->TabIndex = 4;
			this->add_groups->Text = L"Добавить группы";
			this->add_groups->UseVisualStyleBackColor = true;
			this->add_groups->Click += gcnew System::EventHandler(this, &AddData::add_groups_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(90, 26);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(33, 20);
			this->maskedTextBox1->TabIndex = 5;
			this->maskedTextBox1->Leave += gcnew System::EventHandler(this, &AddData::maskedTextBox1_Leave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Номера групп";
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
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->add_groups);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(542, 101);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(249, 65);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Создать группы:";
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
			this->groupBox3->Location = System::Drawing::Point(542, 172);
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
			this->ClientSize = System::Drawing::Size(1096, 578);
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
	private: System::Void CheckComboBox1(int index);
	private: System::Void CheckComboBox2(int index2);
	private: System::Void CheckComboBox3(int index3);
	private: System::Void CheckComboBox4(int index4);
	private: System::Void InfoAboutStusents();
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddGroup();
	public: System::Void rowcountchanged();
	private: System::Void ClearGrid(int size);
	private: System::Void add_groups_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maskedTextBox1_Leave(System::Object^ sender, System::EventArgs^ e);
	private: System::Void add_stud_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void set_header_num();
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
	};
}
