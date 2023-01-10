#pragma once
#include "Groups.h"

class YearsOfUni
{
private:
	std::string year;
	Groups* group = new class Groups[10];
	int year_of_start;
	int count_groups;
public:
	YearsOfUni();
	~YearsOfUni();
	std::string getNameY();
	int getYearOfStartY();
	void operator=(class YearsOfUni you);
	Groups getGroups(int index_gr);
	int getCountGroupsY();
	std::string getGroupNameY(int index_gr);

	void clearYear();

	void setYearOfStartY(int year);
	void setGroupsY(class Groups gr, int index_gr);
	void setCountGroupsY(int count);
	void setNameY(std::string name_you);
};