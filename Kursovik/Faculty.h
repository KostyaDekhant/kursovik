#pragma once
#include <string>
#include <vector>
#include "Directions.h"
using namespace std;

class Faculty : public Directions
{
private:
	string name_facult;
	vector<Directions*> dir;
	static int count_facult;
public:
	Faculty();
	void setVector(class Directions &direct);
};
