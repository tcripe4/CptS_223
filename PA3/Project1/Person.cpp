using namespace std;
#include "Person.h"
#include <iostream>
Person::Person(int position)
{
	this->Position = position;
}

Person::~Person()
{

}

void Person::print()
{
	cout << Position << " ";
}

int Person::get_position()
{
	return this->Position;
}