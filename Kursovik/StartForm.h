#pragma once

namespace Kursovik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïğàâêàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::Button^ add_data;

	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::Button^ maximize_bttn;

	private: System::Windows::Forms::Button^ minimize_bttn;



	private: System::Windows::Forms::Button^ exit_bttn;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ make_inq;
	private: System::Windows::Forms::Button^ report;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğàâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->add_data = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->maximize_bttn = (gcnew System::Windows::Forms::Button());
			this->minimize_bttn = (gcnew System::Windows::Forms::Button());
			this->exit_bttn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->make_inq = (gcnew System::Windows::Forms::Button());
			this->report = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->AutoSize = false;
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ôàéëToolStripMenuItem,
					this->ïğàâêàToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MaximumSize = System::Drawing::Size(300, 24);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(300, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// ïğàâêàToolStripMenuItem
			// 
			this->ïğàâêàToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->ïğàâêàToolStripMenuItem->Name = L"ïğàâêàToolStripMenuItem";
			this->ïğàâêàToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->ïğàâêàToolStripMenuItem->Text = L"Ïğàâêà";
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::âûõîäToolStripMenuItem_Click);
			// 
			// add_data
			// 
			this->add_data->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->add_data->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->add_data->ForeColor = System::Drawing::Color::White;
			this->add_data->Location = System::Drawing::Point(29, 51);
			this->add_data->Name = L"add_data";
			this->add_data->Size = System::Drawing::Size(142, 63);
			this->add_data->TabIndex = 1;
			this->add_data->Text = L"Äîáàâèòü äàííûå";
			this->add_data->UseVisualStyleBackColor = false;
			this->add_data->Click += gcnew System::EventHandler(this, &StartForm::add_data_Click);
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// maximize_bttn
			// 
			this->maximize_bttn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->maximize_bttn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"maximize_bttn.BackgroundImage")));
			this->maximize_bttn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->maximize_bttn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->maximize_bttn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->maximize_bttn->Location = System::Drawing::Point(26, 1);
			this->maximize_bttn->Name = L"maximize_bttn";
			this->maximize_bttn->Size = System::Drawing::Size(27, 23);
			this->maximize_bttn->TabIndex = 2;
			this->maximize_bttn->UseVisualStyleBackColor = false;
			this->maximize_bttn->Click += gcnew System::EventHandler(this, &StartForm::maximize_bttn_Click);
			// 
			// minimize_bttn
			// 
			this->minimize_bttn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->minimize_bttn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize_bttn.BackgroundImage")));
			this->minimize_bttn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->minimize_bttn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimize_bttn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->minimize_bttn->Location = System::Drawing::Point(0, 1);
			this->minimize_bttn->Name = L"minimize_bttn";
			this->minimize_bttn->Size = System::Drawing::Size(26, 23);
			this->minimize_bttn->TabIndex = 3;
			this->minimize_bttn->UseVisualStyleBackColor = false;
			this->minimize_bttn->Click += gcnew System::EventHandler(this, &StartForm::minimize_bttn_Click);
			// 
			// exit_bttn
			// 
			this->exit_bttn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->exit_bttn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exit_bttn.BackgroundImage")));
			this->exit_bttn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->exit_bttn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_bttn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->exit_bttn->Location = System::Drawing::Point(53, 1);
			this->exit_bttn->Name = L"exit_bttn";
			this->exit_bttn->Size = System::Drawing::Size(25, 23);
			this->exit_bttn->TabIndex = 4;
			this->exit_bttn->UseVisualStyleBackColor = false;
			this->exit_bttn->Click += gcnew System::EventHandler(this, &StartForm::exit_bttn_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panel1->Location = System::Drawing::Point(300, 0);
			this->panel1->MaximumSize = System::Drawing::Size(1620, 24);
			this->panel1->MinimumSize = System::Drawing::Size(1, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(476, 24);
			this->panel1->TabIndex = 5;
			this->panel1->DoubleClick += gcnew System::EventHandler(this, &StartForm::panel1_DoubleClick);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::panel1_MouseUp);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panel2->Controls->Add(this->exit_bttn);
			this->panel2->Controls->Add(this->maximize_bttn);
			this->panel2->Controls->Add(this->minimize_bttn);
			this->panel2->Location = System::Drawing::Point(776, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(78, 24);
			this->panel2->TabIndex = 6;
			// 
			// make_inq
			// 
			this->make_inq->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->make_inq->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->make_inq->ForeColor = System::Drawing::Color::White;
			this->make_inq->Location = System::Drawing::Point(29, 120);
			this->make_inq->Name = L"make_inq";
			this->make_inq->Size = System::Drawing::Size(142, 63);
			this->make_inq->TabIndex = 1;
			this->make_inq->Text = L"Çàïğîñ";
			this->make_inq->UseVisualStyleBackColor = false;
			// 
			// report
			// 
			this->report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->report->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->report->ForeColor = System::Drawing::Color::White;
			this->report->Location = System::Drawing::Point(29, 189);
			this->report->Name = L"report";
			this->report->Size = System::Drawing::Size(142, 63);
			this->report->TabIndex = 1;
			this->report->Text = L"Îò÷¸ò";
			this->report->UseVisualStyleBackColor = false;
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->ClientSize = System::Drawing::Size(854, 481);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->report);
			this->Controls->Add(this->make_inq);
			this->Controls->Add(this->add_data);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1920, 1050);
			this->Name = L"StartForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartForm::StartForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::StartForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &StartForm::StartForm_MouseMove);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void exit_bttn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void minimize_bttn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void maximize_bttn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e);
private: System::Void panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void panel1_DoubleClick(System::Object^ sender, System::EventArgs^ e);
private: System::Void StartForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void mousemove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void mousedown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void StartForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void add_data_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
