#pragma once
#include "Students.h"

class Groups
{
private:
	std::string name_group;
	Students* stud = new class Students[30];
	int year_of_admission;
	//int count_group;
	int count_students;
public:
	Groups();
	~Groups();
	std::string getNameG();
	//int getCountG();
	int getCountStudG();
	void operator=(class Groups group);
	Students getStud(int index_stud);

	void setCountStudG(int count);
	void setStudG(class Students& stud, int index_stud);
	void setCountG(int count);
	void setNameG(std::string name_you);
	//void setVectorG(class Students& student);
};