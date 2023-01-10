#include "Groups.h"

Groups::Groups()
{

}

Groups::~Groups()
{

}


std::string Groups::getNameG()
{
	return this->name_group;
}

//int Groups::getCountG()
//{
//	//return this->count_group;
//}

int Groups::getCountStudG()
{
	return this->count_students;
}

Students Groups::getStud(int index_stud)
{
	return this->stud[index_stud];
}


void Groups::operator=(Groups group)
{
	this->name_group = group.name_group;
	this->count_students = group.count_students;
	for (int i = 0; i < count_students; i++)
	{
		this->stud[i] = group.stud[i];
	}
	//this->count_group = group.count_group;
}

void Groups::setCountStudG(int count)
{
	this->count_students = count;
}

void Groups::setNameG(std::string name_gr)
{
	this->name_group = name_gr;
}

void Groups::setCountG(int count)
{
	//count_group = count;
}


void Groups::setStudG(class Students& stud, int index_stud)
{
	this->stud[index_stud] = stud;
}
//
//void Groups::setVectorG(class Students& student)
//{
//
//	this->stud.push_back(&student);
//}