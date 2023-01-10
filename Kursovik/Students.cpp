#include "Students.h"

Students::Students()
{

}

Students::~Students()
{

}

std::string Students::getfirtname()
{
	return this->firstname;
}

std::string Students::getmidname()
{
	return this->midname;
}

std::string Students::getlastname()
{
	return this->lastname;
}

int Students::getGPA()
{
	return this->gpa;
}

std::string Students::getPhone_num()
{
	return this->phone_number;
}

//int Students::getCountStud()
//{
//	//return this->count_stud;
//}



void Students::operator=(Students student)
{
	this->firstname = student.firstname;
	this->midname = student.midname;
	this->lastname = student.lastname;
	this->phone_number = student.phone_number;
	//this->count_stud = student.count_stud;
	this->gpa = student.gpa;
}

void Students::setFIO(std::string lastname, std::string firstname, std::string midname)
{
	this->firstname = firstname;
	this->midname = midname;
	this->lastname = lastname;
}

void Students::setGPA(int gpa)
{
	this->gpa = gpa;
}

void Students::setPhone_num(std::string phone_number)
{
	this->phone_number = phone_number;
}

//void Students::setCountStud(int count_stud)
//{
//	//this->count_stud = count_stud;
//}