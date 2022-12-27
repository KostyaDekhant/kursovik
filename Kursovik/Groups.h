#pragma once
#include <string>
#include <vector>
#include "Students.h"
using namespace std;

class Groups : public Students
{
private:
	string name_group;
	vector<Students*> stud;
	int year_of_admission;
	static int count_group;
	
public:
	Groups();
};