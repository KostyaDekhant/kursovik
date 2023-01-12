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
	bool social_scholarship = false;
	int special_scholarship;
public:
	Students();
	~Students();
	std::string getfirtname();
	std::string getmidname();
	std::string getlastname();
	int getGPA();
	std::string getPhone_num();
	int getSpecial();
	bool getSocial();

	void operator=(class Students student);
	void setFIO(std::string lastname, std::string firstname, std::string midname);
	void setGPA(int gpa);
	void setPhone_num(std::string phone_number);
	void setSpecial(int special);
	void setSocial(bool social);
};