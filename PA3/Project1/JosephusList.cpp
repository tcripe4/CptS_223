#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus()
{

}

ListMyJosephus::ListMyJosephus(int N, int M)
{
	this->size = 0;

	this->iterator = 0;

	init(N, M);
}

ListMyJosephus::~ListMyJosephus()
{

}

void ListMyJosephus::init(int N, int M) // Inserts new person
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

void ListMyJosephus::clear()
{
	if (!isEmpty())
	{
		circ.clear();
	}
}

int ListMyJosephus::currentSize() // Gets size of list
{
	return circ.size();
}

bool ListMyJosephus::isEmpty() // Checks if the list is empty
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

int ListMyJosephus::get_iterator()
{
	return this->iterator;
}

void ListMyJosephus::printAll() // Prints the list
{
	list<Person>::iterator it = circ.begin();

	for (; it != circ.end(); it++)
	{
		cout << it->get_position() << " ";
	}
}

Person ListMyJosephus::eliminateNext() // Find the person to delete from the list
{
	int pos = 0 + get_iterator();
	if (pos > 0)
	{
		pos -= 1;
	}
	Person elimiation(pos);
	list<Person>::iterator itr = circ.begin();
	advance(itr, pos);
	circ.erase(itr);
	this->size -= 1;
	return elimiation;
}

int ListMyJosephus::iterate() // Iterates through the list
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

void ListMyJosephus::print_winner()
{
	cout << "The winner is: " << circ.front().get_position() << endl;
}