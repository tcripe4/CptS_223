#include "node.h"
//Node::Node()
//{
//	record = NULL;
//	pNext = nullptr;
//}

Node::Node(Data &NewData)
{
	this->record = NewData;
	this->pNext = nullptr;
}

Data Node::getData()
{
	return record;
}

Node * Node::getNextPtr() const
{
	return this->pNext;
}

void Node::setData(Data const &NewData)
{
	record = NewData;
}

void Node::setNextPtr(Node * newNextPtr)
{
	this->pNext = newNextPtr;
}

Node::Node(const Node &NewNode)
{
	record = NewNode.record;
	pNext = NewNode.pNext;
}