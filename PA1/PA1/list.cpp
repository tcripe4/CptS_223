#include "list.h"

list::list()
{
	this->pHead = nullptr;
	this->max = 0;
	this->median = 0;
	this->min = 1000;
	this->track = 0;
}

bool list::insertion_sort(Data &newData)
{
	Node *pMem = nullptr;

	pMem = new Node(newData); // The newly read data

	Node *pTemp(pHead); // For iterating through the list without changing pHead

	Node *pPrev = nullptr; // Keeping track of previous node

	bool success = false;

	if (pHead == nullptr) // Checks is anything is in the list 
	{
		this->pHead = pMem;
	}
	else
	{

		while (newData.get_num() > pTemp->getData().get_num() && pTemp->getNextPtr() != nullptr) // iterating through list
		{
			pPrev = pTemp;
			pTemp = pTemp->getNextPtr();
		}

		if (pTemp->getNextPtr() == nullptr && newData.get_num() > pTemp->getData().get_num()) // inserting at end
		{
			pTemp->setNextPtr(pMem);
		}

		else if (pPrev != nullptr) // inserting at middle
		{
			pPrev->setNextPtr(pMem);
			pMem->setNextPtr(pTemp);
		}

		else // inserting at front
		{
			pMem->setNextPtr(pHead);
			pHead = pMem;
		}
	}
	return success;
}

Node * list::get_node()
{
	return this->pHead;
}

int list::get_max()
{
	return this->max;;
}

void list::set_max(int const num_max)
{
	max = num_max;
}

int list::get_min()
{
	return this->min;
}

void list::set_min(int const num_min)
{
	min = num_min;
}

int list::get_median()
{
	return this->median;
}

void list::set_median(int const num_median)
{
	median = num_median;
}

void list::find_max()
{
	Node *pMem(pHead);
	auto start = std::chrono::high_resolution_clock::now(); // time
	while (pMem != nullptr)
	{
		if (pMem->getData().get_num() > min)
		{
			set_max(pMem->getData().get_num()); // goes to the end of the list
		}
		pMem = pMem->getNextPtr();
	}
	auto finish = std::chrono::high_resolution_clock::now();
	cout << "The max is: " << get_max() << endl;
	std::chrono::duration<double> elapsed = finish - start;
	cout << "Milliseconds to find max: " << (elapsed.count() * 1000) <<  endl;
}

void list::find_min()
{
	Node *pMem(pHead);
	auto start = std::chrono::high_resolution_clock::now();
	set_min(pHead->getData().get_num()); // Gets the first nodes integer
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	cout << "The minimum is: " << get_min() << endl;
	cout << "Milliseconds to find min: " << (elapsed.count() * 1000) << endl;
}

void list::find_median()
{
	Node *pMedian(pHead);
	int median = 1;
	auto start = std::chrono::high_resolution_clock::now();
	while (pMedian->getNextPtr() != nullptr)
	{
		pMedian = pMedian->getNextPtr(); // Goes to the end of the list
		median += 1; // counts the nodes
	}
	pMedian = pHead;
	median = median / 2; // Divides the number of nodes by 2
	median -= 1;

	for (int i = 0; i <= median; i++)
	{
		pMedian = pMedian->getNextPtr(); // Goes to middle node
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	set_median(pMedian->getData().get_num());
	cout << "The median is: " << get_median() << endl;
	cout << "Milliseconds to find median: " << (elapsed.count() * 1000) << endl;
}