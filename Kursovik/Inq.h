#pragma once

namespace Kursovik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Inq
	/// </summary>
	public ref class Inq : public System::Windows::Forms::Form
	{
	public:
		Inq(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Inq()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox_F;
	private: System::Windows::Forms::CheckBox^ checkBox_I;
	private: System::Windows::Forms::CheckBox^ checkBox_O;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
	private: System::Windows::Forms::CheckBox^ checkBox_rpa;
	private: System::Windows::Forms::CheckBox^ checkBox_social;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::CheckBox^ checkBox_dir;
	private: System::Windows::Forms::CheckBox^ checkBox_years;
	private: System::Windows::Forms::CheckBox^ checkBox_gr;




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox_F = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_I = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_O = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->checkBox_rpa = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_social = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox_dir = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_years = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_gr = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(650, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Inq::���������ToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(12, 200);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(610, 376);
			this->dataGridView1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"����� �� ��������������";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"�������";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(72, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(137, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(72, 111);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(137, 20);
			this->textBox3->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"���";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 118);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"��������";
			// 
			// checkBox_F
			// 
			this->checkBox_F->AutoSize = true;
			this->checkBox_F->Location = System::Drawing::Point(224, 59);
			this->checkBox_F->Name = L"checkBox_F";
			this->checkBox_F->Size = System::Drawing::Size(15, 14);
			this->checkBox_F->TabIndex = 9;
			this->checkBox_F->UseVisualStyleBackColor = true;
			// 
			// checkBox_I
			// 
			this->checkBox_I->AutoSize = true;
			this->checkBox_I->Location = System::Drawing::Point(224, 85);
			this->checkBox_I->Name = L"checkBox_I";
			this->checkBox_I->Size = System::Drawing::Size(15, 14);
			this->checkBox_I->TabIndex = 10;
			this->checkBox_I->UseVisualStyleBackColor = true;
			// 
			// checkBox_O
			// 
			this->checkBox_O->AutoSize = true;
			this->checkBox_O->Location = System::Drawing::Point(224, 111);
			this->checkBox_O->Name = L"checkBox_O";
			this->checkBox_O->Size = System::Drawing::Size(15, 14);
			this->checkBox_O->TabIndex = 11;
			this->checkBox_O->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(266, 66);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"������� ����";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(349, 58);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(33, 20);
			this->maskedTextBox1->TabIndex = 13;
			// 
			// checkBox_rpa
			// 
			this->checkBox_rpa->AutoSize = true;
			this->checkBox_rpa->Location = System::Drawing::Point(400, 58);
			this->checkBox_rpa->Name = L"checkBox_rpa";
			this->checkBox_rpa->Size = System::Drawing::Size(15, 14);
			this->checkBox_rpa->TabIndex = 14;
			this->checkBox_rpa->UseVisualStyleBackColor = true;
			// 
			// checkBox_social
			// 
			this->checkBox_social->AutoSize = true;
			this->checkBox_social->Location = System::Drawing::Point(265, 88);
			this->checkBox_social->Name = L"checkBox_social";
			this->checkBox_social->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox_social->Size = System::Drawing::Size(149, 17);
			this->checkBox_social->TabIndex = 15;
			this->checkBox_social->Text = L"  ���������� ���������";
			this->checkBox_social->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(118, 173);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 16;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Inq::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(245, 173);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 17;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Inq::comboBox2_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(373, 173);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 18;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Inq::comboBox3_SelectedIndexChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(501, 173);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 21);
			this->comboBox4->TabIndex = 19;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Inq::comboBox4_SelectedIndexChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(12, 151);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(108, 17);
			this->radioButton1->TabIndex = 20;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"��� ����������";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Inq::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(12, 174);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(100, 17);
			this->radioButton2->TabIndex = 21;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"�� ����������";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Inq::radioButton2_CheckedChanged);
			// 
			// checkBox_dir
			// 
			this->checkBox_dir->AutoSize = true;
			this->checkBox_dir->Location = System::Drawing::Point(296, 152);
			this->checkBox_dir->Name = L"checkBox_dir";
			this->checkBox_dir->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox_dir->Size = System::Drawing::Size(70, 17);
			this->checkBox_dir->TabIndex = 22;
			this->checkBox_dir->Text = L"�������";
			this->checkBox_dir->UseVisualStyleBackColor = true;
			this->checkBox_dir->CheckedChanged += gcnew System::EventHandler(this, &Inq::checkBox_dir_CheckedChanged);
			// 
			// checkBox_years
			// 
			this->checkBox_years->AutoSize = true;
			this->checkBox_years->Location = System::Drawing::Point(424, 152);
			this->checkBox_years->Name = L"checkBox_years";
			this->checkBox_years->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox_years->Size = System::Drawing::Size(70, 17);
			this->checkBox_years->TabIndex = 23;
			this->checkBox_years->Text = L"�������";
			this->checkBox_years->UseVisualStyleBackColor = true;
			this->checkBox_years->CheckedChanged += gcnew System::EventHandler(this, &Inq::checkBox_years_CheckedChanged);
			// 
			// checkBox_gr
			// 
			this->checkBox_gr->AutoSize = true;
			this->checkBox_gr->Location = System::Drawing::Point(552, 150);
			this->checkBox_gr->Name = L"checkBox_gr";
			this->checkBox_gr->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->checkBox_gr->Size = System::Drawing::Size(70, 17);
			this->checkBox_gr->TabIndex = 24;
			this->checkBox_gr->Text = L"�������";
			this->checkBox_gr->UseVisualStyleBackColor = true;
			this->checkBox_gr->CheckedChanged += gcnew System::EventHandler(this, &Inq::checkBox_gr_CheckedChanged);
			// 
			// Inq
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(650, 607);
			this->Controls->Add(this->checkBox_gr);
			this->Controls->Add(this->checkBox_years);
			this->Controls->Add(this->checkBox_dir);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox_social);
			this->Controls->Add(this->checkBox_rpa);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox_O);
			this->Controls->Add(this->checkBox_I);
			this->Controls->Add(this->checkBox_F);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Inq";
			this->Text = L"Inq";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Inq::Inq_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Inq::Inq_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Inq_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Inq_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void PrintInfoAboutStud();
	private: System::Void checkBox_dir_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_years_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox_gr_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
