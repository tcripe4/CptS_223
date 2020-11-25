
#include "data.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node
{
public:
	//Node();
	Node(Data &NewData);
	Node(const Node &NewNode);

	Data getData();
	Node *getNextPtr() const;

	void setData(Data const &NewData);
	void setNextPtr(Node * newNextPtr);

private:
	Data record;
	Node *pNext;
};