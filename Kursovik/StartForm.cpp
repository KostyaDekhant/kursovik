#define SCREENW 1920
#include "StartForm.h"
#include "AddData.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursovik::StartForm form;
	Application::Run(% form);
}

struct Point {
	int X;
	int Y;
}lastPoint;


System::Void Kursovik::StartForm::exit_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}


System::Void Kursovik::StartForm::minimize_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->WindowState = FormWindowState::Minimized;
}

System::Void Kursovik::StartForm::maximize_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(this->WindowState == FormWindowState::Normal)
		this->WindowState = FormWindowState::Maximized;
	else
		this->WindowState = FormWindowState::Normal;
	panel1->Width = this->Width - 300 - 78;
	panel2->Left = this->Width - 78;
}


System::Void Kursovik::StartForm::panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Kursovik::StartForm::mousemove(sender, e);
}

System::Void Kursovik::StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	
}
static int add_width = 0;

System::Void Kursovik::StartForm::panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (this->WindowState == FormWindowState::Normal && this->Top < 5)
	{
		maximize_bttn->PerformClick();
	}
	add_width = 0;
}

System::Void Kursovik::StartForm::panel1_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	maximize_bttn->PerformClick();
}

System::Void Kursovik::StartForm::StartForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Kursovik::StartForm::mousemove(sender, e);
}



System::Void Kursovik::StartForm::mousemove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		if (this->WindowState == FormWindowState::Maximized)
		{
			this->WindowState = FormWindowState::Normal;
			panel2->Left = this->Width - 78;
			if (lastPoint.X > this->Width - 300 && lastPoint.X < SCREENW - (this->Width - 300))
				add_width = lastPoint.X - 127;
			else if (lastPoint.X > SCREENW - (this->Width - 300))
				add_width = SCREENW - this->Width;

		}
		this->Left += add_width + e->X - lastPoint.X;
		this->Top += e->Y - lastPoint.Y;
	}
}

System::Void Kursovik::StartForm::mousedown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	lastPoint.X = e->X;
	lastPoint.Y = e->Y;
}

System::Void Kursovik::StartForm::StartForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Kursovik::StartForm::mousedown(sender, e);
}

System::Void Kursovik::StartForm::add_data_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddData^ ad = gcnew AddData();
	this->Hide();
	ad->Show();
}

System::Void Kursovik::StartForm::‚˚ıÓ‰ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Kursovik::StartForm::StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Environment::Exit(0);
}

System::Void Kursovik::StartForm::panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	Kursovik::StartForm::mousedown(sender, e);
}
