using namespace std;
#include "VectorMyJosephus.h"
#include <iostream>
VectorMyJosephus::VectorMyJosephus(int N, int M) 
{
	this->size = 0;

	this->iterator = 0;

	init(N, M);
}

VectorMyJosephus::VectorMyJosephus()
{

}

VectorMyJosephus::~VectorMyJosephus()
{

}

void VectorMyJosephus::init(int N, int M) // Inserts new person
{
	this->N = N;
	this->M = M;
	for (int i = 0; i < N; i++)
	{
		Person new_person(i);
		circ.push_back(new_person);
		this->size += 1;
	}
}

void VectorMyJosephus::clear()
{
	if (!isEmpty())
	{
		circ.clear();
	}
}

int VectorMyJosephus::currentSize() // Gets size of list
{
	return circ.size();
}

bool VectorMyJosephus::isEmpty() // Checks if the list is empty
{
	if (circ.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int VectorMyJosephus::get_iterator()
{
	return this->iterator;
}

void VectorMyJosephus::printAll() // Prints the list
{
	int length = 0;

	length = currentSize();

	for (int i = 0; i < length; i++)
	{
		circ[i].print();
	}
}

Person VectorMyJosephus::eliminateNext() // Find the person to delete from the list
{
	int pos = 0 + get_iterator();
	if (pos > 0)
	{
		pos -= 1;
	}
	Person elimiation(circ[pos].get_position());
	circ.erase(circ.begin() + pos);
	this->size -= 1;
	return elimiation;
}

int VectorMyJosephus::iterate() // Iterates through the list
{
	int size = this->size;

	for (int i = 0; i < M; i++)
	{
		this->iterator += 1;
		if (this->iterator > size || this->iterator > M)
		{
			this->iterator = 0;
		}
	}
	return this->iterator;
}

void VectorMyJosephus::print_winner()
{
	cout << "The winner is: " << circ.front().get_position() << endl;
}