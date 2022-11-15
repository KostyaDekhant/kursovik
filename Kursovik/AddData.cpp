#include "AddData.h"
#include "StartForm.h"
#include <string>
#include <fstream>
#include "Function.h"

using namespace std;

string path = "C:\\Users\\Podor\\Documents\\GitHub\\kursovik\\Kursovik\\Data\\";

System::Void Kursovik::AddData::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
	
}

System::Void Kursovik::AddData::AddData_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	StartForm^ form = gcnew StartForm();
	form->Show();
}

System::Void Kursovik::AddData::AddData_Load(System::Object^ sender, System::EventArgs^ e)
{
	CheckComboBox1();
	
}



System::Void Kursovik::AddData::SelectGrid(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{ 
	
}

System::Void Kursovik::AddData::CheckComboBox1()
{
	string ftxt = "Faculty.txt";
	ifstream faculty(path+ftxt);
	if (faculty)
	{
		int count_facult = 0;
		string* faculties = new string[10];
		while (getline(faculty, faculties[count_facult]))
		{
			count_facult++;
		}
		faculty.close();
		for (int i = 0; i < count_facult; i++)
		{
			comboBox1->Items->Add(ConvertToString(faculties[i]));
		}
		comboBox1->SelectedIndex = 0;
		CheckComboBox2();
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox2()
{
	string dtxt = "Direction.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\";
	ifstream dir(path + repos + dtxt);
	if (dir)
	{
		int count_dir = 0;
		string* direction = new string[10];
		while (getline(dir, direction[count_dir]))
		{
			count_dir++;
		}
		dir.close();
		for (int i = 0; i < count_dir; i++)
		{
			comboBox2->Items->Add(ConvertToString(direction[i]));
		}
		comboBox2->SelectedIndex = count_dir -1;
		CheckComboBox3();
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox3()
{
	string ytxt = "YearsOfUni.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\";
	ifstream year(path + repos + ytxt);
	if (year)
	{
		int count_year = 0;
		string* years = new string[10];
		while (getline(year, years[count_year]))
		{
			count_year++;
		}
		year.close();
		for (int i = 0; i < count_year; i++)
		{
			comboBox3->Items->Add(ConvertToString(years[i]));
		}
		comboBox3->SelectedIndex = 1;
		CheckComboBox4();
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox4()
{
	string gtxt = "Groups.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\" 
				 + ConvertTostring(comboBox3->Text) + "\\";
	ifstream group(path + repos + gtxt);
	if (group)
	{
		int count_gr = 0;
		string* groups = new string[10];
		while (getline(group, groups[count_gr]))
		{
			count_gr++;
		}
		group.close();
		for (int i = 0; i < count_gr; i++)
		{
			comboBox4->Items->Add(ConvertToString(groups[i]));
		}
		comboBox4->SelectedIndex = 0;
		InfoAboutStusents();
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::InfoAboutStusents()
{
	
}