#include "Faculty.h"

Faculty::Faculty()
{
	count_dir = 0;
	name_facult = "";
}

Faculty::~Faculty()
{

}

int Faculty::count_facult = 0;

void Faculty::operator=(Faculty facult)
{
	this->name_facult = facult.name_facult;
	this->count_facult = facult.count_facult;
	this->count_dir = facult.count_dir;
	for (int i = 0; i < facult.count_dir; i++)
	{
		this->dir[i] = facult.dir[i];
	}
}

std::string Faculty::getNameF()
{
	return this->name_facult;
}

int Faculty::getCountF()
{
	return this->count_facult;
}

int Faculty::getCountInDirF()
{
	return this->count_dir;
}

int Faculty::getCountInGroupsF(int index_dir, int index_you)
{
	YearsOfUni you = class 	YearsOfUni();
	you = this->getYearsF(index_dir, index_you);
	return you.getCountGroupsY();
}


std::string Faculty::getDirNameF(int index_dir)
{
	return this->dir[index_dir].getNameD();
}

Directions Faculty::getDirF(int index_dir)
{
	return this->dir[index_dir];
}

YearsOfUni Faculty::getYearsF(int index_dir, int index_you)
{
	return this->dir[index_dir].getYearsD(index_you);
}

Groups Faculty::getGroupF(int index_dir, int index_you, int index_gr)
{
	YearsOfUni years = class YearsOfUni();
	years = this->dir[index_dir].getYearsD(index_you);
	return years.getGroups(index_gr);
}

Students Faculty::getStudF(int index_dir, int index_you, int index_gr, int index_stud) 
{
	Groups group = class Groups();
	group = this->getGroupF(index_dir, index_you, index_gr);
	return group.getStud(index_stud);
}

int Faculty::getCountInYearsF(int index_dir)
{
	return this->dir[index_dir].getYearsOfEdD();
}

void Faculty::setDirF(class Directions& direct, int index_dir)
{
	this->dir[index_dir] = direct;
}

void Faculty::setYearsF(class YearsOfUni& you, int index_dir, int index_you)
{
	Directions dir = class Directions();
	dir = this->getDirF(index_dir);
	dir.setYearsD(you, index_you);
	this->setDirF(dir, index_dir);
}
void Faculty::setGroupsF(class Groups& gr, int index_dir, int index_you, int index_gr)
{
	YearsOfUni you = class YearsOfUni();
	you = this->getYearsF(index_dir, index_you);
	you.setGroupsY(gr, index_gr);
	this->setYearsF(you, index_dir, index_you);
}
void Faculty::setStudF(class Students& stud, int index_dir, int index_you, int index_gr, int index_stud)
{
	Groups gr = class Groups();
	gr = this->getGroupF(index_dir, index_you, index_gr);
	gr.setStudG(stud, index_stud);
	this->setGroupsF(gr, index_dir, index_you, index_gr);
}

void Faculty::setCountInDirF(int count_dir)
{
	this->count_dir = count_dir;
}

void Faculty::setNameF(std::string name_facult)
{
	this->name_facult = name_facult;
}

void Faculty::setCountF(int count)
{
	count_facult = count;
}

//void Faculty::setVectorF(class Directions &direct)
//{
//
//	this->dir.push_back(&direct);
//}
