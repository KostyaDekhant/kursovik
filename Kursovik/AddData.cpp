#include "AddData.h"
#include "StartForm.h"
#include "Function.h"
#include <string>
#include <fstream>
#include <direct.h>
#define MAX_STUD 50

using namespace std;

extern string path = "";
int GridSize = 0;
bool Flag_for_checkbox = false;
YearsOfUni you_temp = class YearsOfUni();
int last_year_int;
Faculty* fac = new class Faculty[10];
int sholarship[10];

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
	path = ConvertTostring(Path);
	last_year_int = fac[0].getYearsF(0, 0).getYearOfStartY();
	ChangeYear();
	if(fac->getCountF())
	{
		CreateGrid();
		AddComboBoxFaculty(comboBox1, comboBox2, comboBox3, comboBox4);
	}
	LoadForm();
}

System::Void Kursovik::AddData::SelectGrid(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{ 
	
}

System::Void Kursovik::AddData::ChangeYear()
{
	const time_t tm = time(nullptr);
	char buf[64];
	strftime(buf, std::size(buf), "%d.%m.%Y", localtime(&tm));
	//char start_year[5] = { '2','0','2','1' };
	int month = (buf[3] - '0') * 10 + buf[4] - '0';
	int year = (buf[6] - '0') * 1000 + (buf[7] - '0') * 100 + (buf[8] - '0') * 10 + buf[9] - '0';
	//int last_year_int = 2021;
	int temp_shift = 0;
	for (int i = 0; i < year; i++)
	{
		if (month >= 8 && year == last_year_int+i || month < 8 && year == last_year_int+1+i)
		{
			temp_shift = i;
			break;
		}
	}
	if (temp_shift > 0)
	{
		if (MessageBox::Show("Данные актуальны за " + last_year_int.ToString()
			+ "-" + (last_year_int + 1).ToString() + " годы.\n" +
			"Обновить под " + (last_year_int + temp_shift).ToString()
			+ "-" + (last_year_int + temp_shift + 1).ToString() + " годы?\n", "",
			MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
		{
			ShiftData(temp_shift);
			MessageBox::Show("Готово!");
			last_year_int += temp_shift;
		}
	}
}

System::Void Kursovik::AddData::LoadForm()
{
	if(comboBox4->Text != "")
		add_stud->Enabled = true;
	else
		add_stud->Enabled = false;
	//del_bttn->Enabled = false;
	save_data_bttn->Enabled = false;
	dataGridView1->ForeColor = Color::Black;
	dataGridView1->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
	maskedTextBox2->Mask = "00";
	maskedTextBox3->Mask = "0";
	maskedTextBox_directions->Mask = "00";
	dataGridView1->ReadOnly = true;
	checkBox1->Text = "Выключен";
	OpenSholarFile();
}

System::Void Kursovik::AddData::GetFIO(string FIO, string* last, string* first, string* mid)
{
	string str[3] = {"","",""};
	string temp = "";
	int count_str = 0;
	for (int i = 0; i < FIO.length(); i++)
	{
		temp += FIO[i];
		if (FIO[i+1] == ' ' || i == FIO.length()-2)
		{
			if(i == FIO.length() - 2)
				temp += FIO[i+1];
			str[count_str] = temp;
			temp = "";
			count_str++;
			i++;
		}
	}
	*last = str[0];
	*first = str[1];
	*mid = str[2];
}

System::Void Kursovik::AddData::OpenSholarFile()
{
	path = ConvertTostring(Path);
	ifstream sholar(path + "Sholarship.txt");
	string sholars[4];
	int sholar_count = 0;
	while (getline(sholar, sholars[sholar_count]))
	{
		sholarship[sholar_count] = stoi(sholars[sholar_count]);
		sholar_count++;
	}
}

System::Void Kursovik::AddData::faculty_add_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox_faculty->Text != "")
		CreateFaculty();
	else
	{

		MessageBox::Show("Введите название!");
		return;
	}
	AddComboBoxFaculty(comboBox1, comboBox2, comboBox3, comboBox4);
	MessageBox::Show("Успех!");
}

System::Void Kursovik::AddData::directions_add_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBox_directions->Text != "" && maskedTextBox_directions->MaskFull)
	{
		CreateDirections();
	}
	else
	{
		MessageBox::Show("Введите название и количество лет!");
		return;
	}
	AddComboBoxDirect(comboBox1, comboBox2, comboBox3, comboBox4);
	AddComboBoxYears(comboBox1, comboBox2, comboBox3, comboBox4);
	MessageBox::Show("Успех!");
}

System::Void Kursovik::AddData::years_add_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{

}

Void Kursovik::AddData::getFac(Faculty* facult)
{
	for (int i = 0; i < fac->getCountF(); i++)
	{
		facult[i] = fac[i];
	}
}

System::Int32 Kursovik::AddData::Scholarship_Calculation(int fac_index, int dir_index, int year_index, int group_index, int stud_index)
{
	
	Students stud = class Students();
	int sholar = 0;
	stud = fac[fac_index].getStudF(dir_index, year_index, group_index, stud_index);
	if (stud.getGPA() >= 90)
	{
		sholar += sholarship[0] * 2;
	}
	else if (stud.getGPA() >= 75)
	{
		sholar += sholarship[0] * 1.5;
	}
	else if (stud.getGPA() >= 50)
	{
		sholar += sholarship[0];
	}
	else if (stud.getSocial() == true)
	{
		sholar += sholarship[1];
	}
	if (stud.getSocial() == true && stud.getGPA() >= 50)
	{
		sholar += sholarship[2];
	}
	if (stud.getSpecial() != 0)
	{
		sholar += stud.getSpecial();
	}
	return sholar;
}

System::Void Kursovik::AddData::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	
}

System::Void Kursovik::AddData::maskedTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	for (int i = 0; i < maskedTextBox1->Text->Length; i++)
	{
		if (maskedTextBox1->Text[i] <= 47 || maskedTextBox1->Text[i] >= 58)
		{
			maskedTextBox1->Text = "";
			return;
		}
	}
}

System::Void Kursovik::AddData::del_fac_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	string fac_name = fac[comboBox1->SelectedIndex].getNameF();
	if (MessageBox::Show("Вы действительно хотите удалить \"" + ConvertToString(fac_name) + "\"?", "",
		MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
	{
		path = ConvertTostring(Path);
		ofstream facultfile(path + "Faculty.txt");
		int count_fac = fac->getCountF();
		for (int i = 0; i < count_fac; i++)
		{
			if (i != comboBox1->SelectedIndex)
			{
				facultfile << fac[i].getNameF();
				if (i != count_fac - 1)
				{
					facultfile << endl;
				}
			}
		}
		for (int i = comboBox1->SelectedIndex; i < count_fac; i++)
		{
			fac[i] = fac[i + 1];
		}
		fac->setCountF(count_fac - 1);
		facultfile.close();
		rename((path + fac_name).c_str(), (path + fac_name + " Временный").c_str());
	}
}

System::Void Kursovik::AddData::del_dir_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	string fac_name = fac[comboBox1->SelectedIndex].getNameF();
	string dir_name = fac[comboBox1->SelectedIndex].getDirNameF(comboBox2->SelectedIndex);
	if (MessageBox::Show("Вы действительно хотите удалить \"" + ConvertToString(dir_name) + "\"?", "",
		MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
	{
		path = ConvertTostring(Path);
		ofstream dirfile(path + fac_name + "\\" + "Direction.txt");
		int count_dir = fac[comboBox1->SelectedIndex].getCountInDirF();
		for (int i = 0; i < count_dir; i++)
		{
			if (i != comboBox2->SelectedIndex)
			{
				dirfile << fac[comboBox1->SelectedIndex].getDirNameF(i) << endl;
				dirfile << fac[comboBox1->SelectedIndex].getDirF(i).getYearsOfEdD();
				if (i != count_dir - 1)
				{
					dirfile << endl;
				}
			}
		}
		for (int i = comboBox2->SelectedIndex; i < count_dir; i++)
		{
			fac[comboBox1->SelectedIndex].setDirF(fac[comboBox1->SelectedIndex].getDirF(i+1), i);
		}
		fac->setCountInDirF(count_dir - 1);
		dirfile.close();
		rename((path + fac_name + "\\" + dir_name).c_str(), (path + fac_name + "\\" + dir_name + " Временный").c_str());
	}
}

System::Void Kursovik::AddData::del_year_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	string fac_name = fac[comboBox1->SelectedIndex].getNameF();
	string dir_name = fac[comboBox1->SelectedIndex].getDirNameF(comboBox2->SelectedIndex);
	string year_name = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).getNameY();
	if (MessageBox::Show("Вы действительно хотите удалить \"" + ConvertToString(year_name) + "\"?", "",
		MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
	{
		path = ConvertTostring(Path);
		ofstream youfile(path + fac_name + "\\" + dir_name + "\\" + "YearsOfUni.txt");
		int count_years = fac[comboBox1->SelectedIndex].getDirF(comboBox2->SelectedIndex).getYearsOfEdD();
		for (int i = 0; i < count_years; i++)
		{
			if (i != comboBox3->SelectedIndex)
			{
				youfile << fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, i).getNameY() << endl;
				youfile << fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, i).getYearOfStartY();
				if (i != count_years - 1)
				{
					youfile << endl;
				}
			}
		}
		for (int i = comboBox3->SelectedIndex; i < count_years; i++)
		{
			fac[comboBox1->SelectedIndex].setYearsF(fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, i+1), comboBox2->SelectedIndex, i);
		}
		fac[comboBox1->SelectedIndex].getDirF(comboBox2->SelectedIndex).setYearsOfEdD(count_years +1);
		youfile.close();
		rename((path + fac_name + "\\" + dir_name + "\\" + year_name).c_str(), (path + fac_name + "\\" + dir_name + "\\" + year_name + " Временный").c_str());
	}
}

System::Void Kursovik::AddData::del_gr_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	string fac_name = fac[comboBox1->SelectedIndex].getNameF();
	string dir_name = fac[comboBox1->SelectedIndex].getDirNameF(comboBox2->SelectedIndex);
	string year_name = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).getNameY();
	string gr_name = fac[comboBox1->SelectedIndex].getGroupF(comboBox2->SelectedIndex, comboBox3->SelectedIndex, comboBox4->SelectedIndex).getNameG();
	if (MessageBox::Show("Вы действительно хотите удалить \"" + 
		ConvertToString(gr_name) + "\"?", "",
		MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
	{
		path = ConvertTostring(Path);
		ofstream grfile(path + fac_name + "\\" + dir_name + "\\" + year_name + "\\" + "Groups.txt");
		int count_gr = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).getCountGroupsY();
		for (int i = 0; i < count_gr; i++)
		{
			if (i != comboBox4->SelectedIndex)
			{
				grfile << fac[comboBox1->SelectedIndex].getGroupF(comboBox2->SelectedIndex, comboBox3->SelectedIndex, i).getNameG();
				grfile << endl;
			}
		}
		int count_gr_classes = 19;
		while (fac[comboBox1->SelectedIndex].getGroupF(comboBox2->SelectedIndex, comboBox3->SelectedIndex, count_gr_classes).getNameG() != "")
		{
			count_gr_classes--;
		}
		fac[comboBox1->SelectedIndex].setGroupsF(fac[comboBox1->SelectedIndex].getGroupF(comboBox2->SelectedIndex, comboBox3->SelectedIndex, comboBox4->SelectedIndex), comboBox2->SelectedIndex, comboBox3->SelectedIndex, count_gr_classes);
		for (int i = comboBox4->SelectedIndex; i < count_gr; i++)
		{
			fac[comboBox1->SelectedIndex].setGroupsF(fac[comboBox1->SelectedIndex].getGroupF(comboBox2->SelectedIndex, comboBox3->SelectedIndex, i+1), comboBox2->SelectedIndex, comboBox3->SelectedIndex, i);
		}
		YearsOfUni you = class YearsOfUni();
		you = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex);
		you.setCountGroupsY(count_gr-1);
		fac[comboBox1->SelectedIndex].setYearsF(you,comboBox2->SelectedIndex, comboBox3->SelectedIndex);
		grfile.close();
		rename((path + fac_name + "\\" + dir_name + "\\" + year_name + "\\" + gr_name).c_str(), 
			(path + fac_name + "\\" + dir_name + "\\" + year_name + "\\" + gr_name + " Временный").c_str());
	}
}

System::Void Kursovik::AddData::файлToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ pname;
	if (folderBrowserDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		pname = folderBrowserDialog1->SelectedPath;
		path = ConvertTostring(pname)+"\\";
		Path = pname + "\\";
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();
		comboBox3->Items->Clear();
		comboBox4->Items->Clear();
		ClearGrid(dataGridView1->RowCount);
		OpenFileFacult();
		AddComboBoxFaculty(comboBox1, comboBox2, comboBox3, comboBox4);
		MessageBox::Show("Данные обновлены!");
	}
}

System::Void Kursovik::AddData::CreateFaculty() 
{
	path = ConvertTostring(Path);
	int fac_count_before = fac->getCountF();
	string name = ConvertTostring(textBox_faculty->Text);
	fac[fac_count_before].setNameF(name);
	string repos = fac[fac_count_before].getNameF() + "\\";
	//fac[fac->getCountF()].setCountInDirF(dir_count);
	fac[fac->getCountF()].setCountF(fac_count_before + 1);
	_mkdir((path + name).c_str());
	fstream facultfile(path + "Faculty.txt", ios_base::app);
	facultfile << endl << name;
	facultfile.close();
}

System::Void Kursovik::AddData::CreateDirections()
{
	path = ConvertTostring(Path);
	int fac_index = comboBox1->SelectedIndex;
	string name = ConvertTostring(textBox_directions->Text);
	int years = stoi(ConvertTostring(maskedTextBox_directions->Text));
	Directions dir = class Directions();
	YearsOfUni you = class YearsOfUni();
	dir.setNameD(name);
	dir.setYearsOfEdD(years);
	fac[fac_index].setDirF(dir, fac[fac_index].getCountInDirF());
	fac[fac_index].setCountInDirF(fac[fac_index].getCountInDirF() + 1);
	string repos = fac[fac_index].getNameF() + "\\";
	_mkdir((path + repos + name).c_str());
	ifstream dirfile(path + repos + "Direction.txt");
	if (dirfile)
	{
		fstream dirfile1(path + repos + "Direction.txt", ios_base::app);
		dirfile1 << endl;
		dirfile1.close();
	}
	else
	{
		ofstream dirfile1(path + repos + "Direction.txt");
		dirfile1.close();
	}
	dirfile.close();
	fstream dirfile1(path + repos + "Direction.txt", ios_base::app);
	dirfile1 << name;
	dirfile1 << endl << years;
	repos += dir.getNameD() + "\\";
	ofstream yearfile(path + repos +"YearsOfUni.txt");
	CreateYearNames(fac_index, fac[fac_index].getCountInDirF()-1);
	for (int i = 0; i < years; i++)
	{
		you = fac[fac_index].getYearsF(fac[fac_index].getCountInDirF()-1, i);
		CreateYear(fac_index, fac[fac_index].getCountInDirF()-1, i);
		yearfile << you.getNameY() << endl;
		yearfile << you.getYearOfStartY();
		if (i != years - 1)
		{
			yearfile << endl;
		}

	}
	yearfile.close();
}

System::Void Kursovik::AddData::CreateYear(int index_fac, int index_dir, int index_you)
{
	YearsOfUni you = class YearsOfUni();
	you = fac[index_fac].getYearsF(index_dir, index_you);
	string repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + "\\";
	string year = you.getNameY();
	_mkdir((path + repos + year).c_str());
}

System::Void Kursovik::AddData::CreateYearNames(int index_fac, int index_dir)
{
	int years_count = fac[index_fac].getCountInYearsF(index_dir);
	YearsOfUni you = class YearsOfUni();
	for (int i = 1; i <= years_count; i++)
	{
		you.clearYear();
		you.setNameY(ConvertTostring(i.ToString()) + " курс");
		you.setYearOfStartY(last_year_int - i + 1);
		fac[index_fac].setYearsF(you, index_dir, i-1);
	}
}

System::Void Kursovik::AddData::ShiftData(int temp_shift)
{
	path = ConvertTostring(Path);
	int faculty_count = fac->getCountF();
	for (int i = 0; i < faculty_count; i++)
	{
		int dir_count = fac[i].getCountInDirF();
		for (int j = 0; j < dir_count; j++)
		{
			int years_count = fac[i].getCountInYearsF(j);
			string repos = fac[i].getNameF() + "\\" + fac[i].getDirNameF(j) + "\\";
			string last_name = "";
			ofstream yearsfile(path + repos + "YearsOfUni.txt");
			int years_count_in_dir = fac[i].getDirF(j).getYearsOfEdD();
			for (int i = 0; i < years_count_in_dir; i++)
			{
				yearsfile << ConvertTostring((i + 1).ToString()) + " курс" << endl;
				yearsfile << last_year_int + temp_shift - i;
				if (i != years_count_in_dir - 1)
					yearsfile << endl;
			}


			for (int k = 0; k < temp_shift; k++)
			{
				you_temp.clearYear();
				you_temp = fac[i].getYearsF(j, years_count - 1 - k);
				last_name = you_temp.getNameY();

				you_temp.setNameY(ConvertTostring((years_count - k).ToString()) + " временный");
				fac[i].setYearsF(you_temp, j, 14 - k);

				rename((path + repos + last_name).c_str(), (path + repos + you_temp.getNameY()).c_str());
			}
			for (int k = 0; k < years_count-temp_shift; k++)
			{
				fac[i].setYearsF(fac[i].getYearsF(j, years_count - 1 - temp_shift - k), j, years_count - 1 - k);
				last_name = ConvertTostring(Convert::ToString(years_count - k)) + " курс";
				rename((path + repos + fac[i].getYearsF(j, years_count - 1 - k).getNameY()).c_str(), (path + repos + last_name).c_str());
				you_temp = fac[i].getYearsF(j, years_count - 1 - k);
				you_temp.setNameY(ConvertTostring(Convert::ToString(years_count - k)) + " курс");
				fac[i].setYearsF(you_temp, j, years_count - 1 - k);
			}
			for (int k = 0; k < temp_shift; k++)
			{
				you_temp.clearYear();
				you_temp.setNameY(ConvertTostring(Convert::ToString(k + 1)) + " курс");
				
				fac[i].setYearsF(you_temp, j, k);
				CreateYear(i, j, k);
			}
		}
	}
}

System::Void Kursovik::AddData::AddComboBoxFaculty(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4)
{
	combobox1->Items->Clear();
	int count_fac = fac->getCountF();
	if (!count_fac)
	{
		combobox1->Text = "";
		combobox2->Text = "";
		combobox3->Text = "";
		combobox4->Text = "";
		ClearGrid(GridSize);
		return;
	}
	for (int i = 0; i < count_fac; i++)
	{
		combobox1->Items->Add(ConvertToString(fac[i].getNameF()));
	}
	combobox1->SelectedIndex = 0;

}

System::Void Kursovik::AddData::AddComboBoxDirect(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4)
{
	combobox2->Items->Clear();
	int count_dir = fac[combobox1->SelectedIndex].getCountInDirF();
	if (!count_dir)
	{
		combobox2->Text = "";
		combobox2->Items->Clear();
		combobox3->Text = "";
		combobox3->Items->Clear();
		combobox4->Text = "";
		combobox4->Items->Clear();
		ClearGrid(GridSize);
		return;
	}
	for (int i = 0; i < count_dir; i++)
	{
		combobox2->Items->Add(ConvertToString(fac[combobox1->SelectedIndex].getDirNameF(i)));
	}
	combobox2->SelectedIndex = 0;
}

System::Void Kursovik::AddData::AddComboBoxYears(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3, ComboBox^ combobox4)
{
	combobox3->Items->Clear();
	Directions direct = class Directions();
	direct = fac[combobox1->SelectedIndex].getDirF(combobox2->SelectedIndex);
	int count_years = direct.getYearsOfEdD();
	if (!count_years)
	{
		combobox3->Text = "";
		combobox3->Items->Clear();
		combobox4->Text = "";
		combobox4->Items->Clear();
		ClearGrid(GridSize);
		return;
	}
	for (int i = 0; i < count_years; i++)
	{
		combobox3->Items->Add(ConvertToString(direct.getYearsNameD(i)));
	}
	combobox3->SelectedIndex = 0;
}

System::Void Kursovik::AddData::AddComboBoxGroups(ComboBox^ combobox1, ComboBox^ combobox2, ComboBox^ combobox3,ComboBox^ combobox4)
{
	YearsOfUni you = class YearsOfUni();
	combobox4->Items->Clear();
	you = fac[combobox1->SelectedIndex].getYearsF(combobox2->SelectedIndex, combobox3->SelectedIndex);
	int count_groups = you.getCountGroupsY();
	if (!count_groups)
	{
		combobox4->Text = "";
		ClearGrid(GridSize);
		return;
	}
	if (count_groups == 9)
	{
		add_groups->Enabled = false;
	}
	else
		add_groups->Enabled = true;
	for (int i = 0; i < count_groups; i++)
	{
		combobox4->Items->Add(ConvertToString(you.getGroupNameY(i)));
	}
	combobox4->SelectedIndex = 0;
}

System::Void Kursovik::AddData::CreateGrid()
{
	dataGridView1->ColumnCount = data_volume-3;
	dataGridView1->Columns[0]->HeaderText = "ФИО";
	dataGridView1->Columns[1]->HeaderText = "Телефон";
	dataGridView1->Columns[2]->HeaderText = "Средний \nбалл";
	dataGridView1->Columns[2]->Width = 20;
	dataGridView1->Columns[3]->HeaderText = "Доп. \nстипендия";
	DataGridViewCheckBoxColumn^ cbc = gcnew DataGridViewCheckBoxColumn();
	cbc->HeaderText = "Соц. стипендия";
	dataGridView1->Columns->Insert(4, cbc);
}

System::Void Kursovik::AddData::CreateFiles(int flag, int index_fac, int index_dir, 
	int index_you, int index_groups)
{
	path = ConvertTostring(Path);
	string filetxt = "";
	string repos = "";
	YearsOfUni you = class YearsOfUni();
	if (flag > 3)
	{
		you = fac[index_fac].getYearsF(index_dir, index_you);
	}
	if (flag == 1)
	{
		filetxt = "Faculty.txt";
	}
	else if (flag == 2)
	{
		filetxt = "Direction.txt";
		repos = fac[index_fac].getNameF() + "\\";
	}
	else if (flag == 3)
	{
		filetxt = "YearsOfUni.txt";
		repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + "\\";
	}
	else if (flag == 4)
	{
		filetxt = "Groups.txt";
		repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + +"\\"
			+ you.getNameY() + "\\";
	}
	else if (flag == 5)
	{
		filetxt = "Students.txt";
		repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + +"\\"
			+ you.getNameY() + "\\" + you.getGroupNameY(index_groups) + "\\";
	}
	else
	{
		return;
	}
	ofstream file(path + repos + filetxt);
	file.close();
}

System::Void Kursovik::AddData::SaveStudFile(int index_fac, int index_dir, int index_you, int index_groups)
{ 
	path = ConvertTostring(Path);
	YearsOfUni you = class YearsOfUni();
	you = fac[index_fac].getYearsF(index_dir, index_you);
	Students stud = class Students();
	int row_count = dataGridView1->RowCount;
	Groups gr = class Groups();
	gr = fac[index_fac].getGroupF(index_dir, index_you, index_groups);
	gr.setCountStudG(row_count);
	fac[index_fac].setGroupsF(gr, index_dir, index_you, index_groups);
	for (int i = 0; i < row_count; i++)
	{
		string FIO = ConvertTostring(dataGridView1->Rows[i]->Cells[0]->Value->ToString());

		string first = "";
		string last = "";
		string mid = "";
		GetFIO(FIO, &last, &first, &mid);
		stud.setFIO(last, first, mid);
		stud.setPhone_num(ConvertTostring(dataGridView1->Rows[i]->Cells[1]->Value->ToString()));
		stud.setGPA(stoi(ConvertTostring((dataGridView1->Rows[i]->Cells[2]->Value->ToString()))));
		stud.setSpecial(stoi(ConvertTostring((dataGridView1->Rows[i]->Cells[3]->Value->ToString()))));
		if(Convert::ToBoolean(dataGridView1->Rows[i]->Cells[4]->Value))
			stud.setSocial(true);
		else
			stud.setSocial(false);
		fac[index_fac].setStudF(stud, index_dir, index_you, index_groups,i);
	}
	string filetxt = "Students.txt";
	string repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + +"\\"
		+ you.getNameY() + "\\" + you.getGroupNameY(index_groups) + "\\";
	ofstream studentfile(path + repos + filetxt);
	int stud_count = row_count;
	for (int i = 0; i < stud_count; i++)
	{
		stud = fac[index_fac].getStudF(index_dir, index_you, index_groups, i);
		studentfile << stud.getlastname() << endl;
		studentfile << stud.getfirtname() << endl;
		studentfile << stud.getmidname() << endl;
		studentfile << stud.getPhone_num() << endl;
		studentfile << stud.getGPA() << endl;
		studentfile << stud.getSpecial() << endl;
		if (stud.getSocial())
		{
			studentfile << "1";
		}
		else
		{
			studentfile << "0";
		}
		if(i != stud_count-1)
			studentfile << endl;
	}
	studentfile.close();
}

System::Void Kursovik::AddData::PrintStudents(int index_fac, int index_dir, int index_you, 
	int index_groups, DataGridView^ dataGridView1, Inq^ inq)
{
	if (inq == nullptr)
	{
		Inq^ inq1 = gcnew Inq();
		inq = inq1;
	}
	Students stud = class Students();
	Groups gr = class Groups();
	gr = fac[index_fac].getGroupF(index_dir, index_you, index_groups);
	int count_stud_before = dataGridView1->RowCount;
	int count_stud = gr.getCountStudG();
	int rows_added = count_stud_before;
	for (int i = count_stud_before; i < count_stud_before+count_stud; i++)
	{
		if (inq->CheckTextBoxes(index_fac, index_dir, index_you, index_groups, i - count_stud_before))
		{
			dataGridView1->RowCount += 1;
			stud = fac[index_fac].getStudF(index_dir, index_you, index_groups, i - count_stud_before);
			dataGridView1->Rows[rows_added]->Cells[0]->Value = ConvertToString(stud.getlastname() + " " +
				stud.getfirtname() + " " + stud.getmidname());
			dataGridView1->Rows[rows_added]->Cells[1]->Value = ConvertToString(stud.getPhone_num());
			dataGridView1->Rows[rows_added]->Cells[2]->Value = Convert::ToString(stud.getGPA());
			if (dataGridView1->ColumnCount == 5)
			{
				dataGridView1->Rows[rows_added]->Cells[3]->Value = Convert::ToString(stud.getSpecial());
				dataGridView1->Rows[rows_added]->Cells[4]->Value = Convert::ToString(stud.getSocial());
			}
			else
			{
				dataGridView1->Rows[rows_added]->Cells[3]->Value = 
					Scholarship_Calculation(index_fac, index_dir, index_you, index_groups, i - count_stud_before);
			}
			rows_added++;
		}
	}
}

System::Void Kursovik::AddData::OpenFileFacult()
{
	path = ConvertTostring(Path);
	string ftxt = "Faculty.txt";
	ifstream faculty(path+ftxt);
	int count_facult = 0;
	if (faculty)
	{
		string faculties = "";
		while (getline(faculty, faculties))
		{
			fac[count_facult].setNameF(faculties);
			count_facult++;
		}
		fac->setCountF(count_facult);
		faculty.close();
		int count_fac = fac->getCountF();
		for (int i = 0; i < count_fac; i++)
		{
			OpenFileDirect(i);
		}
	}
	else
	{
		CreateFiles(1, 0, 0, 0, 0);
	}
}

System::Void Kursovik::AddData::OpenFileDirect(int index)
{
	path = ConvertTostring(Path);
	Directions direct = class Directions();
	string dtxt = "Direction.txt";
	int count_dir = 0;
	int count_info = 0;
	string repos = fac[index].getNameF() + "\\";
	ifstream dir(path + repos + dtxt);
	if (dir)
	{
		string direction[2] = {"", ""};
		while (getline(dir, direction[count_info]))
		{
			count_info++;
			if (count_info == 2)
			{
				direct.setNameD(direction[0]);
				direct.setYearsOfEdD(stoi(direction[1]));
				fac[index].setDirF(direct, count_dir);
				count_info = 0;
				count_dir++;
			}
			
		}
		fac[index].setCountInDirF(count_dir);
		dir.close();
		for (int i = 0; i < count_dir; i++)
		{
			OpenFileYears(index, i);
		}
	}
	else
	{
		CreateFiles(2, index, 0, 0, 0);
	}
}

System::Void Kursovik::AddData::OpenFileYears(int index_fac, int index_dir)
{
	path = ConvertTostring(Path);
	string ytxt = "YearsOfUni.txt";
	YearsOfUni you = class YearsOfUni();
	Directions direc = class Directions();
	direc = fac[index_fac].getDirF(index_dir);
	string repos = fac[index_fac].getNameF() + "\\" + direc.getNameD() + "\\";
	ifstream year(path + repos + ytxt);
	int volume_of_data = 2;
	int info_count = 0;
	if (year)
	{
		int count_year = 0;
		info_count = 0;
		string years[2] = { "", ""};
		while (getline(year, years[info_count]))
		{
			info_count++;
			if (info_count == volume_of_data)
			{
				direc.setYearsNameD(years[0], count_year);
				direc.setYearsOfStartD(stoi(years[1]), count_year);
				count_year++;
				info_count = 0;
			}
		}
		year.close();
		direc.setYearsOfEdD(count_year);
		fac[index_fac].setDirF(direc, index_dir);
		for (int i = 0; i < count_year; i++)
		{
			OpenFileGroups(index_fac, index_dir, i);
		}
	}
	else
	{
		CreateFiles(3, index_fac, index_dir, 0, 0);
	}
}

System::Void Kursovik::AddData::OpenFileGroups(int index_fac, int index_dir, int index_you)
{
	path = ConvertTostring(Path);
	string gtxt = "Groups.txt";
	Directions dir = class Directions();
	Groups gr = class Groups();
	dir = fac[index_fac].getDirF(index_dir);
	YearsOfUni you = class YearsOfUni();
	you = fac[index_fac].getYearsF(index_dir, index_you);
	string repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + + "\\"
				 + you.getNameY() + "\\";
	ifstream group(path + repos + gtxt);
	if (group)
	{
		int count_gr = 0;
		string groups = "";
		while (getline(group, groups))
		{
			gr.setNameG(groups);
			you.setGroupsY(gr, count_gr); 
			count_gr++;
		}
		you.setCountGroupsY(count_gr);
		group.close();
		dir.setYearsD(you, index_you);
		fac[index_fac].setDirF(dir, index_dir);
		int count_groups = fac[index_fac].getCountInGroupsF(index_dir, index_you);
		if (gr.getNameG() == "0" || gr.getNameG() == "")
		{
			if(dataGridView1->Rows->Count > 1)
				if (dataGridView1->Rows[0]->Cells[0]->Value->ToString() != "")
				{
					ClearGrid(GridSize);
				}
		}
		else
		{
			for (int i = 0; i < count_groups; i++)
			{
				OpenFileStudents(index_fac, index_dir, index_you, i);
			}
		}
	}
	else
	{
		CreateFiles(4, index_fac, index_dir, index_you, 0);
	}
}

System::Void Kursovik::AddData::OpenFileStudents(int index_fac, int index_dir, int index_you, int index_groups)
{
	path = ConvertTostring(Path);
	string stxt = "Students.txt";
	Students student = class Students();
	YearsOfUni you = class YearsOfUni();
	you = fac[index_fac].getYearsF(index_dir, index_you);
	string repos = fac[index_fac].getNameF() + "\\" + fac[index_fac].getDirNameF(index_dir) + +"\\"
		+ you.getNameY() + "\\" + you.getGroupNameY(index_groups) + "\\";
	ifstream stude(path + repos + stxt);
	if (stude)
	{
		int count_info = 0;
		int count_st = 0;
		string* studs = new string[data_volume];
		while (getline(stude, studs[count_info]))
		{
			count_info++;
			if (count_info == data_volume) 
			{
				for (int i = 0; i < count_info; i++)
				{
					if (studs[i][studs[i].length() - 1] == ' ')
						studs[i].erase(studs[i].size() - 1);
				}
				student.setFIO(studs[0], studs[1], studs[2]);
				student.setPhone_num(studs[3]);
				student.setGPA(stoi(studs[4]));
				student.setSpecial(stoi(studs[5]));
				student.setSocial(stoi(studs[6]));
				Groups gr = class Groups();
				gr = fac[index_fac].getGroupF(index_dir, index_you, index_groups);
				gr.setCountStudG(count_st+1);
				gr.setStudG(student, count_st);
				fac[index_fac].setGroupsF(gr, index_dir, index_you, index_groups);
				count_info = 0;
				count_st++;
			}
		}
		stude.close();
		Groups gr = class Groups();
		gr = fac[index_fac].getGroupF(index_dir, index_you, index_groups);
		gr.setCountStudG(count_st);
		fac[index_fac].setGroupsF(gr, index_dir, index_you, index_groups);
	}
	else
	{
		CreateFiles(5, index_fac, index_dir, index_you, index_groups);
		ClearGrid(GridSize);
	}
}

System::Void Kursovik::AddData::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	label8->Text = comboBox1->Text;
	AddComboBoxDirect(comboBox1, comboBox2, comboBox3, comboBox4);
}

System::Void Kursovik::AddData::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	label9->Text = comboBox2->Text;
	AddComboBoxYears(comboBox1, comboBox2, comboBox3, comboBox4);
}

System::Void Kursovik::AddData::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	label10->Text = comboBox3->Text;
	AddComboBoxGroups(comboBox1, comboBox2, comboBox3, comboBox4);
}

System::Void Kursovik::AddData::comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	label11->Text = comboBox4->Text;
	dataGridView1->RowCount = 0;
	PrintStudents(comboBox1->SelectedIndex, comboBox2->SelectedIndex, 
		comboBox3->SelectedIndex, comboBox4->SelectedIndex, dataGridView1, nullptr);
	set_header_num(dataGridView1);
}

System::Void Kursovik::AddData::AddGroup()
{
	
}

System::Void Kursovik::AddData::PrintClasses()
{
	for (int i = 0; i < fac->getCountF(); i++)
	{
		for (int j = 0; j < fac[i].getCountInDirF(); j++)
		{
			Directions di = class Directions();
			di = fac[i].getDirF(j);
			int years_of_ed = di.getYearsOfEdD();
			string str = "";
			for (int l = 0; l < years_of_ed; l++)
			{
				str += di.getYearsNameD(l) + " ";
				
			}
			MessageBox::Show(ConvertToString(fac[i].getNameF() + " " + 
				fac[i].getDirNameF(j) + " " + str + " ") + years_of_ed.ToString());
		}
	}
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
	path = ConvertTostring(Path);
	setlocale(LC_ALL, "rus");
	string gtxt = "Groups.txt";
	string repos = ConvertTostring(comboBox1->Text) + "\\" + ConvertTostring(comboBox2->Text) + "\\"
		+ ConvertTostring(comboBox3->Text) + "\\";
	int groups_count_inp = 0;
	if(maskedTextBox3->Text != "")
		groups_count_inp = stoi(ConvertTostring(maskedTextBox3->Text));
	if (groups_count_inp == 0)
	{
		return;
	}
	string str2 = "";
	if (checkBox2->Checked == true && textBox2->Text != "")
	{
		str2 = ConvertTostring(textBox2->Text) + "-";
	}
	else
	{
		if (checkBox2->Checked == true)
		{
			MessageBox::Show("Название не было введено!");
			checkBox2->Checked = false;
		}
		string str = ConvertTostring(comboBox2->Text);
		str2 += str[0];
		for (int i = 1; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '-' && (str[i + 1] != ' ' && str[i + 1] != '-'))
			{
				if (str[i + 1] != ' ' && str[i + 1] != '-' && str[i + 2] != ' ' && str[i + 2])
					str2 += toupper(str[i + 1]);
			}
		}
		str2 += "-";
	}
	int flag = 1;
	int groups_count_class = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).getCountGroupsY();
	int start_ed = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).
		getYearOfStartY() % 10;
	string group_tmp = "";
	if (start_ed == 0)
	{
		str2 += "0";
	}
	for (int i = 1; i <= groups_count_inp; i++)
	{
		flag = 1;
		int num_gr = i + groups_count_class;
		group_tmp = str2 + ConvertTostring((start_ed * 10 + num_gr).ToString());
		fstream groupsfile(path + repos + gtxt, ios_base::app);
		groupsfile << group_tmp << endl;
		groupsfile.close();
		_mkdir((path + repos + group_tmp).c_str());
		ofstream studentsfile(path + repos + group_tmp + "\\" + "Students.txt");
		studentsfile.close();
	}
	fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).
		setCountGroupsY(groups_count_inp + groups_count_class);
	OpenFileGroups(comboBox1->SelectedIndex, comboBox2->SelectedIndex, comboBox3->SelectedIndex);
	AddComboBoxGroups(comboBox1, comboBox2, comboBox3, comboBox4);
	maskedTextBox3->Text = "";
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
	set_header_num(dataGridView1);
}

System::Void Kursovik::AddData::set_header_num(DataGridView^ dataGridView1)
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

System::Void Kursovik::AddData::checkBox1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBox1->Checked && !Flag_for_checkbox)
	{
		dataGridView1->ReadOnly = false;
		checkBox1->Text = "Включён";

		add_groups->Enabled = false;
		add_stud->Enabled = false;
		save_data_bttn->Enabled = false;
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
		save_data_bttn->Enabled = true;
		add_groups->Enabled = true;
		add_stud->Enabled = true;
	}
}

System::Void Kursovik::AddData::save_data_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveStudFile(comboBox1->SelectedIndex, comboBox2->SelectedIndex, comboBox3->SelectedIndex, comboBox4->SelectedIndex);
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

System::Void Kursovik::AddData::simple_sort(int i, int j)
{
	if (Row_del_index[i] > Row_del_index[j])
	{
		int temp_num = Row_del_index[i];
		Row_del_index[i] = Row_del_index[j];
		Row_del_index[j] = temp_num;
	}
}

System::Void Kursovik::AddData::maskedTextBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	char symbol = e->KeyChar;
	int groups_count_class = fac[comboBox1->SelectedIndex].getYearsF(comboBox2->SelectedIndex, comboBox3->SelectedIndex).getCountGroupsY();
	if ((groups_count_class + (symbol - '0')) > 9)
	{
		MessageBox::Show("групп не может быть больше 10!");
		maskedTextBox3->Text = Convert::ToString(9 - groups_count_class);
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
		}
	}
	textBox1->Text = "";
	clear_variables_for_del(RowCount_dg);
}

