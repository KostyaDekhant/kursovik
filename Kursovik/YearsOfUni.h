#pragma once
#include <string>
#include "Groups.h"
using namespace std;

class YearsOfUni : public Groups
{
private:
	vector<Groups*> you;
	int year;
public:
	YearsOfUni();
};