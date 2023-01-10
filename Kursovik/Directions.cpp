#include "Directions.h"

Directions::Directions()
{
	//this->count_you = 0;
	this->name_dir = "";
	this->year_of_ed = 0;
}

Directions::~Directions()
{

}

std::string Directions::getNameD()
{
	return this->name_dir;
}

int Directions::getYearsOfEdD()
{
	return this->year_of_ed;
}

std::string Directions::getYearsNameD(int index_you)
{
	return this->you[index_you].getNameY();
}

//int Directions::getCountYearsD()
//{
//	return this->count_you;
//}


YearsOfUni Directions::getYearsD(int index_you)
{
	return this->you[index_you];
}


void Directions::operator=(class Directions direct)
{
	this->name_dir = direct.name_dir;
	//this->count_you = direct.count_you;
	this->year_of_ed = direct.year_of_ed;
	int years = this->year_of_ed;
	for (int i = 0; i < years; i++)
	{
		this->you[i] = direct.you[i];
	}
}

void Directions::setYearsOfEdD(int years)
{
	this->year_of_ed = years;
}

void Directions::setYearsOfStartD(int years, int index_you)
{
	this->you[index_you].setYearOfStartY(years);
}

void Directions::setYearsNameD(std::string name, int index_you)
{
	this->you[index_you].setNameY(name);
}


void Directions::setNameD(std::string name_direct)
{
	this->name_dir = name_direct;
}
//
//void Directions::setCountYearsD(int count)
//{
//	this->count_you = count;
//}


void Directions::setYearsD(class YearsOfUni &years, int index_you)
{
	this->you[index_you] = years;

	//this->you[index_you].setCountY(years.getCountY());
	//this->you[index_you].setNameY(years.getNameY());
}