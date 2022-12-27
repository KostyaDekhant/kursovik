#include "Faculty.h"

Faculty::Faculty()
{

}

void Faculty::setVector(class Directions &direct)
{

	this->dir.push_back(&direct);
}
