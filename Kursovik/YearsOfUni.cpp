#include "YearsOfUni.h"

YearsOfUni::YearsOfUni()
{
	this->count_groups = 0;
	this->year = "";
	this->year_of_start = 0;
}

YearsOfUni::~YearsOfUni()
{

}


void YearsOfUni::clearYear()
{
	this->count_groups = 0;
	this->year = "";
	this->year_of_start = 0;
}

std::string YearsOfUni::getNameY()
{
	return this->year;
}

int YearsOfUni::getYearOfStartY()
{
	return this->year_of_start;
}

//int YearsOfUni::getCountY()
//{
//	return this->count_groups;
//}

void YearsOfUni::operator=(YearsOfUni you)
{
	this->setNameY(you.getNameY());
	this->year_of_start = you.year_of_start;
	this->count_groups = you.count_groups;
	for (int i = 0; i < you.count_groups; i++)
	{
		this->group[i] = you.group[i];
	}
}

Groups YearsOfUni::getGroups(int index_gr)
{
	return this->group[index_gr];
}

int YearsOfUni::getCountGroupsY()
{
	return this->count_groups;
}

std::string YearsOfUni::getGroupNameY(int index_gr)
{
	return this->group[index_gr].getNameG();
}

void YearsOfUni::setYearOfStartY(int year)
{
	this->year_of_start = year;
}

void YearsOfUni::setGroupsY(class Groups gr, int index_gr)
{
	this->group[index_gr] = gr;
}



void YearsOfUni::setNameY(std::string name_years)
{
	this->year = name_years;
}

void YearsOfUni::setCountGroupsY(int count)
{
	count_groups = count;
}
//
//void YearsOfUni::setVectorY(class Groups& group)
//{
//
//	this->groups.push_back(&group);
//}