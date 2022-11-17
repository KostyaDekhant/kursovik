#include "AddData.h"
#include "StartForm.h"
#include <string>
#include <fstream>
#include "Function.h"
#include <direct.h>

#define MAX_STUD 50
using namespace std;

extern string path = "C:\\Users\\Podor\\Documents\\GitHub\\kursovik\\Kursovik\\Data\\";
int GridSize = 0;

System::Void Kursovik::AddData::вернутьсяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	CheckComboBox1(0);
	dataGridView1->ForeColor = Color::Black;
	dataGridView1->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
	maskedTextBox1->Mask = "00-00";
	maskedTextBox2->Mask = "00";
}

System::Void Kursovik::AddData::SelectGrid(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{ 
	
}

System::Void Kursovik::AddData::CheckComboBox1(int index)
{
	string ftxt = "Faculty.txt";
	ifstream faculty(path+ftxt);
	if (faculty)
	{
		if (comboBox1->Text == "")
		{
			int count_facult = 0;
			string* faculties = new string[10];
			while (getline(faculty, faculties[count_facult]))
			{
				count_facult++;
			}
			for (int i = 0; i < count_facult; i++)
			{
				comboBox1->Items->Add(ConvertToString(faculties[i]));
			}
		}
		faculty.close();
		comboBox1->SelectedIndex = index;
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox2(int index)
{
	string dtxt = "Direction.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\";
	ifstream dir(path + repos + dtxt);
	if (dir)
	{
		comboBox2->Items->Clear();
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
		comboBox2->SelectedIndex = index;
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox3(int index)
{
	string ytxt = "YearsOfUni.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\";
	ifstream year(path + repos + ytxt);
	if (year)
	{
		comboBox3->Items->Clear();
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
		comboBox3->SelectedIndex = index;
	}
	else
	{
		MessageBox::Show("NO");
	}
}

System::Void Kursovik::AddData::CheckComboBox4(int index)
{
	string gtxt = "Groups.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\" 
				 + ConvertTostring(comboBox3->Text) + "\\";
	ifstream group(path + repos + gtxt);
	if (group)
	{
		comboBox4->Items->Clear();
		comboBox4->Text = "";
		int count_gr = 0;
		string* groups = new string[10];
		while (getline(group, groups[count_gr]))
		{
			count_gr++;
		}
		group.close();
		if (groups[0] != "0" && groups[0] != "")
		{
			for (int i = 0; i < count_gr; i++)
			{
				comboBox4->Items->Add(ConvertToString(groups[i]));
			}
			comboBox4->SelectedIndex = index;
		}
		else
		{
			MessageBox::Show("Информация о группах для данного курса отсутствует!");
			if(dataGridView1->Rows->Count > 1)
				if (dataGridView1->Rows[0]->Cells[0]->Value->ToString() != "")
				{
					ClearGrid(GridSize);
				}
		}
	}
	else
	{
		MessageBox::Show("Информация о группах для данного курса отсутствует!");
	}
}

System::Void Kursovik::AddData::InfoAboutStusents()
{
	string stxt = "Students.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\"
		+ ConvertTostring(comboBox3->Text) + "\\" + ConvertTostring(comboBox4->Text) + "\\";
	ifstream stud(path + repos + stxt);
	int data_volume = 3;
	if (stud)
	{
		int count_st = 0;
		string* studs = new string[MAX_STUD* data_volume];
		while (getline(stud, studs[count_st]))
		{
			count_st++;
		}
		stud.close();
		if (studs[0] != "0")
		{
			GridSize = count_st / data_volume;
			dataGridView1->RowCount = count_st / data_volume;
			dataGridView1->ColumnCount = data_volume;
			for (int i = 0; i < count_st; i+= data_volume) 
			{
				dataGridView1->Columns[0]->HeaderText = "ФИО";
				dataGridView1->Columns[1]->HeaderText = "Телефон";
				dataGridView1->Columns[2]->HeaderText = "Средний балл";
				dataGridView1->Rows[i/ data_volume]->Cells[0]->Value = ConvertToString(studs[i]);
				dataGridView1->Rows[i/ data_volume]->Cells[1]->Value = ConvertToString(studs[i+1]);
				dataGridView1->Rows[i/ data_volume]->Cells[2]->Value = ConvertToString(studs[i+2]);
			}
			set_header_num();
		}
		else
		{
			MessageBox::Show("Информация о студентах отсутсвует!");
			if (dataGridView1->Rows[0]->Cells[0]->Value->ToString() != "")
			{
				ClearGrid(GridSize);
			}
		}
	}
	else
	{
		MessageBox::Show("Информация о студентах отсутсвует!");
	}
}



System::Void Kursovik::AddData::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	CheckComboBox2(0);
}

System::Void Kursovik::AddData::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	CheckComboBox3(0);
}

System::Void Kursovik::AddData::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	CheckComboBox4(0);
}

System::Void Kursovik::AddData::comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	InfoAboutStusents();
}

System::Void Kursovik::AddData::AddGroup()
{
	
}

System::Void Kursovik::AddData::ClearGrid(int size)
{
	for (int i = 0; i < size; i++)
	{
		dataGridView1->Rows->RemoveAt(0);
	}
	GridSize = 0;

}

System::Void Kursovik::AddData::add_groups_Click(System::Object^ sender, System::EventArgs^ e)
{
	
}

System::Void Kursovik::AddData::maskedTextBox1_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (maskedTextBox1->MaskFull)
	{
		setlocale(LC_ALL, "rus");
		string gtxt = "Groups.txt";
		string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\"
			+ ConvertTostring(comboBox3->Text) + "\\";
		int begin = stoi(ConvertTostring(maskedTextBox1->Text->Substring(0, 2)));
		int end = stoi(ConvertTostring(maskedTextBox1->Text->Substring(3, 2)));
		string str = ConvertTostring(comboBox2->Text);
		string str2 = "";
		str2 += str[0];
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '-')
			{
				str2 += toupper(str[i+1]);
			}
		}
		str2 += "-";
;		for (int i = begin; i <= end; i++)
		{
			int flag = 1;
			string group_tmp = str2 + ConvertTostring(i.ToString());
			string tmp;
			ifstream group(path + repos + gtxt);
			int count_cycle = 0;
			while (getline(group, tmp))
			{
				if (tmp == "0")
				{
					flag = 2;
				}
				if (tmp == group_tmp)
				{
					flag = 0;
				}
				count_cycle++;
			}
			if(count_cycle == 0)
				flag = 2;
			group.close();
			if (flag)
			{
				if (flag == 2)
				{
					ofstream group(path + repos + gtxt);
					group.close();
				}
				fstream group(path + repos + gtxt, ios_base::app);
				if (flag == 1)
					group << endl << group_tmp;
				if (flag == 2)
					group << group_tmp;
				_mkdir((path + repos + group_tmp).c_str());
				ofstream stud(path + repos + group_tmp + "\\" + "Students.txt");
				stud.close();
				group.close();
			}
		}
		CheckComboBox4(0);
	}
	else
	{
		MessageBox::Show("ээээ");
	}
}

System::Void Kursovik::AddData::add_stud_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (maskedTextBox2->MaskFull)
	{
		int count_stud = stoi(ConvertTostring(maskedTextBox2->Text->Substring(0, 2)));
		for (int i = 0; i < count_stud; i++)
		{
			dataGridView1->Rows->Add();
		}
	}
	set_header_num();
}

System::Void Kursovik::AddData::set_header_num()
{
	int size_grid = dataGridView1->RowCount;
	for (int i = 0; i < size_grid; i++)
	{
		dataGridView1->Rows[i]->HeaderCell->Value = (i+1).ToString();
	}
}


