#include "Students.h"

Students::Students()
{
	firstname = "";
	lastname = "";
	midname = "";
	gpa = 0;
	social_scholarship = false;
	special_scholarship = 0;
	phone_number = "";
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
int Students::getSpecial()
{
	return special_scholarship;
}
bool Students::getSocial()
{
	return social_scholarship;
}
void Students::operator=(Students student)
{
	this->firstname = student.firstname;
	this->midname = student.midname;
	this->lastname = student.lastname;
	this->phone_number = student.phone_number;
	this->social_scholarship = student.social_scholarship;
	this->special_scholarship = student.special_scholarship;
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

void Students::setSpecial(int special)
{
	this->special_scholarship = special;
}

void Students::setSocial(bool social)
{
	this->social_scholarship = social;
}
