#include "DeleteData.h"
#include "AddData.h"
#include "Function.h"
#include <math.h>
#include <string>

System::Void Kursovik::DeleteData::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
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

System::Void Kursovik::DeleteData::del_bttn_Click(System::Object^ sender, System::EventArgs^ e)
{
    AddData^ ad = gcnew AddData();
    int datagv_row_count = ad->RowCount_dg;
    int count_of_nums = 0;
    int len_of_text = textBox1->Text->Length-1;
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
            ad->Row_del_index[count_of_nums] = temp_num;
            temp_num = 0;
            len_of_num = 0;
            if (textBox1->Text[len_of_text] == 44)
                ad->Row_del_index[count_of_nums+1] = -1;
            else if (textBox1->Text[len_of_text] == 45)
                ad->Row_del_index[count_of_nums+1] = -2;
            count_of_nums+=2;
        }
        if (len_of_text == 0 && !flag_for_end)
            flag_for_end = true;
        else
            len_of_text--;
    }
}

System::Boolean Kursovik::DeleteData::check_next_symbol(char symbol, int lensym)
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
            AddData^ ad = gcnew AddData();
            int datagv_row_count = ad->RowCount_dg;
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
