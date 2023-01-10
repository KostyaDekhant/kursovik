#include "AddFaculty.h"
#include "AddData.h"

System::Void Kursovik::AddFaculty::AddFaculty_Load(System::Object^ sender, System::EventArgs^ e)
{
	maskedTextBox_faculty->Mask = "00";
}

System::Void Kursovik::AddFaculty::faculty_create_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddData^ ad = gcnew AddData();
	
}
