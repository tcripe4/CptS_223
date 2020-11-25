#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data
{
public:
	Data(int num1 = 0);
	Data(Data &copyData);
	~Data();

	int const get_num();
private:
	int num;
};