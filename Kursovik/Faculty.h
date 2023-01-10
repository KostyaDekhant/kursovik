#pragma once
#include "Directions.h"

class Faculty
{
private:
	std::string name_facult;
	Directions* dir = new class Directions[20];
	static int count_facult;
	int count_dir;
public:
	Faculty();
	~Faculty();

	void operator=(class Faculty facult);
	std::string getNameF();
	int getCountF();
	std::string getDirNameF(int index_dir);
	int getCountInDirF();
	int getCountInYearsF(int index_dir);
	int getCountInGroupsF(int index_dir, int index_you);
	Directions getDirF(int index_dir);
	YearsOfUni getYearsF(int index_dir, int index_you);
	Groups getGroupF(int index_dir, int index_you, int index_gr);
	Students getStudF(int index_dir, int index_you, int index_gr, int index_stud);

	void setCountInDirF(int count_dir);
	void setDirF(class Directions& direct, int index_dir);
	void setYearsF(class YearsOfUni& you, int index_dir, int index_you);
	void setGroupsF(class Groups& gr, int index_dir, int index_you, int index_gr);
	void setStudF(class Students& stud, int index_dir, int index_you, int index_gr, int index_stud);
	static void setCountF(int count);
	void setNameF(std::string name_facult);
	
};
