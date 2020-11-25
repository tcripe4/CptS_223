#include "wrapper.h"

void Wrapper::RunApp()
{
	string name = "";
	cout << "What is the file name?" << endl; // gets user input for any file
	cin >> name;
	infile1.open(name);
	import(infile1, file1);
}

Wrapper::Wrapper()
{

}

void Wrapper::DisplayMenu()
{

}

void Wrapper::import(ifstream &infile, list file)
{
	int num = 0;
	if (infile1.is_open())
	{
		cout << "Reading file... Performing computations" << endl;
		auto start = std::chrono::high_resolution_clock::now(); // starts the clock. I had to get help from the internet for this
		while (!infile1.eof())
		{
			infile >> num;
			Data read(num); // puts the integer into a data object
			file.insertion_sort(read); // the object then gets put into a linked list
		}
		cout << "File has been read and sorted" << endl;
		auto finish = std::chrono::high_resolution_clock::now(); //these 2 lines also
		std::chrono::duration<double> elapsed = finish - start; // ---------------
		cout << "Milliseconds to read and sort the file: " << (elapsed.count() * 1000) << endl;
		cout << "Finding the max, median, and min." << endl;
		file.find_max(); // finds the max
		file.find_min(); // finds min
		file.find_median(); // finds median
	}
}