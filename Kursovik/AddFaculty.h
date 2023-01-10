#pragma once

namespace Kursovik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddFaculty
	/// </summary>
	public ref class AddFaculty : public System::Windows::Forms::Form
	{
	public:
		AddFaculty(void)
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
		~AddFaculty()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::TextBox^ textBox_faculty;
	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox_faculty;
	private: System::Windows::Forms::Label^ faculty_name_label;
	private: System::Windows::Forms::Label^ dir_count_label;
	private: System::Windows::Forms::Button^ faculty_create_bttn;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вернутьсяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox_faculty = (gcnew System::Windows::Forms::TextBox());
			this->maskedTextBox_faculty = (gcnew System::Windows::Forms::MaskedTextBox());
			this->faculty_name_label = (gcnew System::Windows::Forms::Label());
			this->dir_count_label = (gcnew System::Windows::Forms::Label());
			this->faculty_create_bttn = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem2 });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(88, 26);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(87, 22);
			this->toolStripMenuItem2->Text = L"-+";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->вернутьсяToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(289, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вернутьсяToolStripMenuItem
			// 
			this->вернутьсяToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->вернутьсяToolStripMenuItem->Name = L"вернутьсяToolStripMenuItem";
			this->вернутьсяToolStripMenuItem->Size = System::Drawing::Size(75, 20);
			this->вернутьсяToolStripMenuItem->Text = L"Вернуться";
			// 
			// textBox_faculty
			// 
			this->textBox_faculty->Location = System::Drawing::Point(161, 75);
			this->textBox_faculty->Name = L"textBox_faculty";
			this->textBox_faculty->Size = System::Drawing::Size(100, 20);
			this->textBox_faculty->TabIndex = 2;
			// 
			// maskedTextBox_faculty
			// 
			this->maskedTextBox_faculty->Location = System::Drawing::Point(161, 113);
			this->maskedTextBox_faculty->Mask = L" ";
			this->maskedTextBox_faculty->Name = L"maskedTextBox_faculty";
			this->maskedTextBox_faculty->Size = System::Drawing::Size(23, 20);
			this->maskedTextBox_faculty->TabIndex = 3;
			// 
			// faculty_name_label
			// 
			this->faculty_name_label->AutoSize = true;
			this->faculty_name_label->ForeColor = System::Drawing::SystemColors::Control;
			this->faculty_name_label->Location = System::Drawing::Point(12, 75);
			this->faculty_name_label->Name = L"faculty_name_label";
			this->faculty_name_label->Size = System::Drawing::Size(119, 13);
			this->faculty_name_label->TabIndex = 4;
			this->faculty_name_label->Text = L"Название факультета";
			// 
			// dir_count_label
			// 
			this->dir_count_label->AutoSize = true;
			this->dir_count_label->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dir_count_label->Location = System::Drawing::Point(12, 116);
			this->dir_count_label->Name = L"dir_count_label";
			this->dir_count_label->Size = System::Drawing::Size(135, 13);
			this->dir_count_label->TabIndex = 5;
			this->dir_count_label->Text = L"Количество направлений";
			// 
			// faculty_create_bttn
			// 
			this->faculty_create_bttn->Location = System::Drawing::Point(109, 159);
			this->faculty_create_bttn->Name = L"faculty_create_bttn";
			this->faculty_create_bttn->Size = System::Drawing::Size(75, 23);
			this->faculty_create_bttn->TabIndex = 6;
			this->faculty_create_bttn->Text = L"Создать";
			this->faculty_create_bttn->UseVisualStyleBackColor = true;
			this->faculty_create_bttn->Click += gcnew System::EventHandler(this, &AddFaculty::faculty_create_bttn_Click);
			// 
			// AddFaculty
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(32)));
			this->ClientSize = System::Drawing::Size(289, 216);
			this->Controls->Add(this->faculty_create_bttn);
			this->Controls->Add(this->dir_count_label);
			this->Controls->Add(this->faculty_name_label);
			this->Controls->Add(this->maskedTextBox_faculty);
			this->Controls->Add(this->textBox_faculty);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AddFaculty";
			this->Text = L"AddFaculty";
			this->Load += gcnew System::EventHandler(this, &AddFaculty::AddFaculty_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddFaculty_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void faculty_create_bttn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
