#include <string>
using namespace System;
using namespace std;

string ConvertTostring(String^ s) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	string os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}


String^ ConvertToString(string& os) {
	String^ s = gcnew String(os.c_str());

	return s;
}