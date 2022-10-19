#pragma once
#include <string>
using namespace System;
using namespace std;

string ConvertTostring(System::String^ s);		// converting System::string ^ to std::string
String^ ConvertToString(string& os);		// converting std::string to System::string ^