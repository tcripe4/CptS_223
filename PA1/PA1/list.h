#pragma once
#include "data.h"
#include "node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

class list
{
public:
	list();

	bool insertion_sort(Data &newData);

	Node * get_node();

	int get_max();

	void set_max(int const num_max);

	int get_min();

	void set_min(int const num_min);

	int get_median();

	void set_median(int const num_median);

	void find_max();

	void find_min();

	void find_median();

private:
	Node *pHead;
	int max;
	int min;
	int median;
	int track;
};