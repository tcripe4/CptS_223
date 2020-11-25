#pragma once
#include "list.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Wrapper
{
public:
	Wrapper();

	void RunApp();

	void DisplayMenu();

	void import(ifstream &infile, list file);


private:
	ifstream infile1;
	list file1;
	list file2;
};