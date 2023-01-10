#pragma once
#include <string>

class Students
{
private:
	std::string firstname;
	std::string midname;
	std::string lastname;
	int gpa;
	std::string phone_number;
	//int count_stud = 0;
public:
	Students();
	~Students();
	std::string getfirtname();
	std::string getmidname();
	std::string getlastname();
	int getGPA();
	std::string getPhone_num();
	//int getCountStud();

	void operator=(class Students student);
	void setFIO(std::string lastname, std::string firstname, std::string midname);
	void setGPA(int gpa);
	void setPhone_num(std::string phone_number);
	//void setCountStud(int count_stud);
};