#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Kursovik::StartForm form;
	Application::Run(% form);
}

const int WM_NCLBUTTONDOWN = 0xA1;
const int HT_CAPTION = 0x2;


System::Void Kursovik::StartForm::exit_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Kursovik::StartForm::panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	
}
