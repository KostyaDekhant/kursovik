#pragma once
#include <string>
#include "YearsOfUni.h"
using namespace std;

class Directions : public YearsOfUni
{
private:
	string name_dir;
	vector<YearsOfUni*> you;
	static int count_dir;
public:
	Directions();
};
