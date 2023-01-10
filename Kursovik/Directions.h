#pragma once
#include "YearsOfUni.h"

class Directions 
{
private:
	std::string name_dir;
	YearsOfUni* you = new class YearsOfUni[15];
	int year_of_ed = 0;
	//int count_you;
public:
	Directions();
	~Directions();
	std::string getNameD();
	int getYearsOfEdD();
	std::string getYearsNameD(int index_you);
	//int getCountYearsD();
	void operator=(class Directions direct);
	YearsOfUni getYearsD(int index_you);

	void setYearsOfEdD(int years);
	void setYearsOfStartD(int years, int index_you);
	void setYearsNameD(std::string name, int index_you);
	void setYearsD(class YearsOfUni &years, int index_you);
	//void setCountYearsD(int count);
	void setNameD(std::string name_dir);
};
