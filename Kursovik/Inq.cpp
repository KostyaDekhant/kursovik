#include "Inq.h"
#include "StartForm.h"
#include "AddData.h"
#include "Function.h"

Faculty* facult = new class Faculty[15];

System::Void Kursovik::Inq::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (radioButton1->Checked == true)
    {
        if (comboBox1->Text != "")
        {
            comboBox1->Items->Clear();
            comboBox2->Items->Clear();
            comboBox3->Items->Clear();
            comboBox4->Items->Clear();
            comboBox1->Text = "";
            comboBox2->Text = ""; 
            comboBox3->Text = "";
            comboBox4->Text = "";
            comboBox1->Enabled = false;
            comboBox2->Enabled = false;
            comboBox3->Enabled = false;
            comboBox4->Enabled = false;
            dataGridView1->RowCount = 0;
        }
        
        PrintInfoAboutStud();
    }
}

System::Void Kursovik::Inq::Inq_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    StartForm^ form = gcnew StartForm();
    form->Show();
}

System::Void Kursovik::Inq::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (radioButton2->Checked == true)
    {
        AddData^ ad = gcnew AddData();
        ad->AddComboBoxFaculty(comboBox1, comboBox2, comboBox3, comboBox4);
        ad->Close();
        comboBox1->Enabled = true;
    }
}

System::Void Kursovik::Inq::Inq_Load(System::Object^ sender, System::EventArgs^ e)
{
    AddData^ ad = gcnew AddData();
    dataGridView1->ColumnCount = ad->data_volume - 2;
    dataGridView1->Columns[0]->HeaderText = "ÔÈÎ";
    dataGridView1->Columns[1]->HeaderText = "Òåëåôîí";
    dataGridView1->Columns[2]->HeaderText = "Ñðåäíèé áàëë";
    checkBox_dir->Checked = false;
    checkBox_years->Checked = false;
    checkBox_gr->Checked = false;
    
    checkBox_years->Enabled = false;
    checkBox_gr->Enabled = false; 
    
    comboBox1->Enabled = false;
    comboBox2->Enabled = false;
    comboBox3->Enabled = false;
    comboBox4->Enabled = false;

    radioButton1->Checked = true;
    dataGridView1->ReadOnly = true;
    dataGridView1->AllowUserToAddRows = false;
    dataGridView1->AllowUserToDeleteRows = false;
    
    dataGridView1->ForeColor = Color::Black;
    dataGridView1->RowHeadersWidthSizeMode = DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
    ad->Close();
}

System::Void Kursovik::Inq::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if(checkBox_dir->Checked == true)
    { 
        AddData^ ad = gcnew AddData();
        ad->AddComboBoxDirect(comboBox1, comboBox2, comboBox3, comboBox4);
        ad->Close();
    }
    else
    {
        dataGridView1->RowCount = 0;
        PrintInfoAboutStud();
    }
}

System::Void Kursovik::Inq::comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_years->Checked == true)
    {
        AddData^ ad = gcnew AddData();
        ad->AddComboBoxYears(comboBox1, comboBox2, comboBox3, comboBox4);
        ad->Close();
    }
    else
    {
        dataGridView1->RowCount = 0;
        PrintInfoAboutStud();
    }
}

System::Void Kursovik::Inq::comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_gr->Checked == true)
    {
        AddData^ ad = gcnew AddData();
        ad->AddComboBoxGroups(comboBox1, comboBox2, comboBox3, comboBox4);
        ad->Close();
    }
    {
        dataGridView1->RowCount = 0;
        PrintInfoAboutStud();
    }
}

System::Void Kursovik::Inq::comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    dataGridView1->RowCount = 0;
    PrintInfoAboutStud();
}

System::Void Kursovik::Inq::âåðíóòüñÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void Kursovik::Inq::PrintInfoAboutStud()
{
    AddData^ ad = gcnew AddData();
    int flag = 0;
    int facult_ind = 0, dir_ind = 0, year_ind = 0, group_ind = 0;
    ad->getFac(facult);
    int facult_count = 0, dir_count = 0, years_count = 0, groups_count = 0;
    if (radioButton1->Checked == false)
    {
        facult_ind = comboBox1->SelectedIndex;
        facult_count = facult_ind + 1;
        if (checkBox_dir->Checked == true)
        {
            dir_ind = comboBox2->SelectedIndex;
            dir_count = dir_ind + 1;
        }
        else
        {
            flag = 1;
        }
        if (checkBox_years->Checked == true)
        { 
            year_ind = comboBox3->SelectedIndex;
            years_count = year_ind + 1;
        }
        else 
        {
            flag = 2;
        }
        if (checkBox_gr->Checked == true)
        {
            group_ind = comboBox4->SelectedIndex;
            groups_count = group_ind + 1;
        }
        else
        {
            flag = 3;
        }
    }
    else
    {
        facult_count = facult->getCountF();
        flag = 3;
    }
    for (int i = facult_ind; i < facult_count; i++)
    {
        if (flag > 0)
            dir_count = facult[i].getCountInDirF();
        for (int j = dir_ind; j < dir_count; j++)
        {
            if (flag > 1)
                years_count = facult[i].getCountInYearsF(j);
            for (int k = year_ind; k < years_count; k++)
            {
                if (flag > 2)
                    groups_count = facult[i].getCountInGroupsF(j, k);
                for (int l = group_ind; l < groups_count; l++)
                {
                    ad->PrintStudents(i, j, k, l, dataGridView1);
                }
            }
        }
    }
    ad->set_header_num(dataGridView1);
    ad->Close();
   // delete[] facult;
}

System::Void Kursovik::Inq::checkBox_dir_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_dir->Checked == true)
    {
        comboBox2->Enabled = true;
        checkBox_years->Enabled = true;
        comboBox1->SelectedIndex = comboBox1->SelectedIndex+1;
        comboBox1->SelectedIndex = comboBox1->SelectedIndex-1;
    }
    else
    {
        checkBox_years->Enabled = false;
        comboBox2->Enabled = false;
        comboBox2->Text = "";
        comboBox2->Items->Clear();
    }
}

System::Void Kursovik::Inq::checkBox_years_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_years->Checked == true)
    {
        comboBox3->Enabled = true;
        checkBox_gr->Enabled = true;
        comboBox2->SelectedIndex = comboBox2->SelectedIndex+1;
        comboBox2->SelectedIndex = comboBox2->SelectedIndex-1;
    }
    else
    {
        comboBox3->Text = "";
        comboBox3->Items->Clear();
        checkBox_gr->Enabled = false; 
        comboBox3->Enabled = false;
    }
}

System::Void Kursovik::Inq::checkBox_gr_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_gr->Checked == true)
    {
        comboBox4->Enabled = true;
        comboBox3->SelectedIndex = comboBox3->SelectedIndex+1;
        comboBox3->SelectedIndex = comboBox3->SelectedIndex-1;
    }
    else
    {
        comboBox4->Text = "";
        comboBox4->Items->Clear();
        comboBox4->Enabled = false;
    }
}
