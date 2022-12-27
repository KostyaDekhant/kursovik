#include "AddData.h"
#include "StartForm.h"
#include "Function.h"
#include "Faculty.h"
//#include "Directions.h"
//#include "YearsOfUni.h"
//#include "Groups.h"
//#include "Students.h"
#include <string>
#include <fstream>
#include <direct.h>

#define MAX_STUD 50
using namespace std;

extern string path = "C:\\Users\\Podor\\Documents\\GitHub\\kursovik\\Kursovik\\Data\\";
int GridSize = 0;
Faculty* fac = new class Faculty[10];
Directions* dir = new class Directions[20];
YearsOfUni* you = new class YearsOfUni[8];
Groups* group = new class Groups[10];
Students* stud = new class Students[40];



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
	dataGridView1->ReadOnly = true;
	checkBox1->Text = "Выключен";
	
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
		ClearGrid(GridSize);
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

System::Void Kursovik::AddData::rowcountchanged()
{
	if (dataGridView1->RowCount != 0)
	{

	}
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

System::Boolean Kursovik::AddData::check_data_grid() 
{
	
	for (int i = 0; i < dataGridView1->RowCount; i++)
	{
		if (dataGridView1[0, i]->Value == nullptr)
		{
			return true;
		}
	}
	return false;
}

System::Void Kursovik::AddData::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	
		
}

bool Flag_for_checkbox = false;

System::Void Kursovik::AddData::checkBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked && !Flag_for_checkbox)
	{
		dataGridView1->ReadOnly = false;
		checkBox1->Text = "Включён";

		add_groups->Enabled = false;
		add_stud->Enabled = false;
	}
	else
	{
		if (check_data_grid())
		{
			checkBox1->Checked = true;
			MessageBox::Show("Не все данные введены!", "Внимание!");
			Flag_for_checkbox = true;
			return;
		}
		dataGridView1->ReadOnly = true;
		Flag_for_checkbox = false;
		checkBox1->Text = "Выключен";

		add_groups->Enabled = true;
		add_stud->Enabled = true;
	}
}

System::Void Kursovik::AddData::save_data_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	
}




System::Boolean Kursovik::AddData::check_next_symbol(char symbol, int lensym)
{
	if (Char::IsDigit(symbol))
	{
		int len_of_num = 0;
		int final_num = 0;
		if (lensym >= 0)
		{
			while (textBox1->Text[lensym] != 44 && textBox1->Text[lensym] != 45)
			{
				final_num += (textBox1->Text[lensym] - '0') * pow(10, len_of_num);
				len_of_num++;
				if (lensym == 0)
					break;
				lensym--;
			}
			int datagv_row_count = dataGridView1->Rows->Count;
			final_num *= 10;
			final_num += (symbol - '0');
			if (final_num > datagv_row_count)
			{
				return true;
			}
		}
	}
	else if (symbol == 44)
	{
		if (flag_for_dash)
			flag_for_dash = false;
	}
	else if (symbol == 45)
	{
		if (!flag_for_dash)
			flag_for_dash = true;
		else
			return true;
	}
	return false;
}

System::Void Kursovik::AddData::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char symbol = e->KeyChar;
	int len = 0;
	if (textBox1->Text->Length > 0)
	{
		int lensym = textBox1->Text->Length - 1;
		if (Char::IsDigit(textBox1->Text[lensym]))
		{
			len = 1;
			if (check_next_symbol(symbol, lensym))
				e->Handled = true;
		}
		else if (textBox1->Text[lensym] == 44 && !flag_for_dash && symbol == 8)
		{
			flag_for_dash = true;
		}
		else if (textBox1->Text[lensym] == 44 && flag_for_dash && symbol == 8)
		{
			flag_for_dash = false;
		}
	}
	if ((symbol <= 47 || symbol >= 58) && symbol != 44 && symbol != 45 && symbol != 8
		|| (textBox1->Text->Length == 0 && (symbol == 48 || symbol == 44 || symbol == 45))
		|| ((symbol == 44 || symbol == 45 || symbol == 48) && !len))
	{
		e->Handled = true;
		return;
	}
}

System::Void Kursovik::AddData::del_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox1->Text[textBox1->Text->Length - 1] == 44 || textBox1->Text[textBox1->Text->Length - 1] == 45)
	{
		textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
	}
	int count_of_nums = 0;
	int len_of_text = textBox1->Text->Length - 1;
	int temp_num = 0;
	int len_of_num = 0;
	bool flag_for_end = false;
	while (len_of_text >= 0)
	{
		if (Char::IsDigit(textBox1->Text[len_of_text]) && !flag_for_end)
		{
			temp_num += (textBox1->Text[len_of_text] - '0') * pow(10, len_of_num);
			len_of_num++;
		}
		else
		{
			Row_del_index[count_of_nums] = temp_num;
			temp_num = 0;
			len_of_num = 0;
			if (textBox1->Text[len_of_text] == 44)
				Row_del_index[count_of_nums + 1] = -1;
			else if (textBox1->Text[len_of_text] == 45)
				Row_del_index[count_of_nums + 1] = -2;
			if(!flag_for_end)
				count_of_nums += 2;
		}
		if (len_of_text == 0 && !flag_for_end)
			flag_for_end = true;
		else
			len_of_text--;
	}
	sort_array(count_of_nums);
	int RowCount_dg = dataGridView1->Rows->Count;
	del_rows(count_of_nums, RowCount_dg);
	
}

System::Boolean Kursovik::AddData::RowWasDeleted(int *DeletedRows, int rowindex, int rowcount)
{
	for (int i = 0; i < rowcount; i++)
	{
		if (rowindex == DeletedRows[i])
			return true;
	}
	return false;
}

System::Void Kursovik::AddData::clear_variables_for_del(int rowcount)
{
	for (int i = 0; i < rowcount; i++)
	{
		DeletedRows[i] = 0;
		Row_del_index[i] = 0;
	}
}

System::Void Kursovik::AddData::sort_array(int count_of_nums)
{
	int temp_num = 0;
	int temp_num1 = 0;
	int temp_sym = 0;
	for (int i = count_of_nums; i >= 2; i-=2)
	{
		for (int j = i - 2; j >= 0; j -= 2)
		{
			if (i - 3 > 0)
			{
				if (Row_del_index[j - 1] == -2) //i-3
				{
					simple_sort(j, j - 2);
					if (Row_del_index[i] > Row_del_index[j - 2])
					{
						temp_num = Row_del_index[i];
						temp_sym = Row_del_index[i - 1];
						Row_del_index[i] = Row_del_index[j];
						Row_del_index[i - 1] = Row_del_index[j - 1];
						Row_del_index[j] = Row_del_index[j - 2];
						Row_del_index[j - 1] = temp_sym;
						Row_del_index[j - 2] = temp_num;
						MessageBox::Show("1");
					}
					j -= 2;

				}
				else if (Row_del_index[i - 1] == -2 && Row_del_index[j - 3] != -2)
				{
					simple_sort(i, j);
					if (Row_del_index[i-2] > Row_del_index[j - 2])
					{
						temp_num = Row_del_index[j - 2];
						temp_sym = Row_del_index[j - 1];
						Row_del_index[j - 2] = Row_del_index[i - 2];
						Row_del_index[j - 1] = Row_del_index[i - 1];
						Row_del_index[i - 2] = Row_del_index[i];
						Row_del_index[i - 1] = temp_sym;
						Row_del_index[i] = temp_num;
						MessageBox::Show("2");
					}
					j -= 2;
				}
				else if (Row_del_index[i - 1] == -2 && Row_del_index[j - 3] == -2)
				{
					simple_sort(i, i - 2);
					simple_sort(j - 2, j - 4);
					if (Row_del_index[j] > Row_del_index[j - 4])
					{
						temp_num = Row_del_index[j - 2];
						temp_sym = Row_del_index[j - 3];
						temp_num1 = Row_del_index[j - 4];
						Row_del_index[j - 2] = Row_del_index[i];
						Row_del_index[j - 3] = Row_del_index[i - 1];
						Row_del_index[j - 4] = Row_del_index[j];
						Row_del_index[j] = temp_num1;
						Row_del_index[i - 1] = temp_sym;
						Row_del_index[i] = temp_num;
						MessageBox::Show("3");
					}
					j -= 4;
				}
				else if (Row_del_index[i - 1] != -2 && (Row_del_index[j - 1] != -2))
				{
					simple_sort(i, j);
					MessageBox::Show("4");
				}
				else 
					simple_sort(i, j);
					
			}
			else if (Row_del_index[i - 1] != -2)
			{
				MessageBox::Show("5");
				simple_sort(i, j);
			}
				
		}
		//std::string str = "";
		//for (int k = 0; k <= count_of_nums; k++)
		//{
		//	if (Row_del_index[k] > 0)
		//		str = ConvertTostring(Row_del_index[k].ToString()) + str;
		//	else if (Row_del_index[k] == -1)
		//		str = "," + str;
		//	else if (Row_del_index[k] == -2)
		//		str = "-" + str;
		//	//MessageBox::Show(Row_del_index[k].ToString());
		//	str = ConvertTostring(Row_del_index[k].ToString()) + " " + str;
		//}
		//MessageBox::Show(ConvertToString(str));
	}
}

System::Void Kursovik::AddData::simple_sort(int i, int j)
{
	if (Row_del_index[i] > Row_del_index[j])
	{
		int temp_num = Row_del_index[i];
		Row_del_index[i] = Row_del_index[j];
		Row_del_index[j] = temp_num;
	}
}


System::Void Kursovik::AddData::del_rows(int count_of_nums, int RowCount_dg)
{
	int flag_for_comma = 0;
	int count_of_del_rows = 0;
	for (int i = 0; i <= count_of_nums; i+=2)
	{
		flag_for_comma = 0;
		if (i <= count_of_nums)
		{
			if (Row_del_index[i + 1] == -1)
			{
				flag_for_comma = 1;
			}
			else if (Row_del_index[i + 1] == -2)
			{
				for (int j = Row_del_index[i+2]; j <= Row_del_index[i]; j++)
				{
					if (!RowWasDeleted(DeletedRows, j, RowCount_dg))
					{
						dataGridView1->Rows->RemoveAt(Row_del_index[i+2] - 1);
						DeletedRows[count_of_del_rows] = j;
						count_of_del_rows++;
					}
				}
				i += 2;
			}
			else if (Row_del_index[i + 1] != -2 && Row_del_index[i + 1] != -1)
			{
				flag_for_comma = 1;
			}
		}
		else
			flag_for_comma = 1;
		if (flag_for_comma)
		{
			if (!RowWasDeleted(DeletedRows, Row_del_index[i], RowCount_dg))
			{
				dataGridView1->Rows->RemoveAt(Row_del_index[i] - 1);
				DeletedRows[count_of_del_rows] = Row_del_index[i];
				count_of_del_rows++;
			}
			else
			{
				//MessageBox::Show("Такая строка уже была удалена!");
			}
		}
	}
	textBox1->Text = "";
	clear_variables_for_del(RowCount_dg);
	//set_header_num();
}

