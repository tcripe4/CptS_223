#include "ListMyJosephus.h"
#include<ctime>
#include<iostream>

int main()
{
	int players = 0, jump = 0, average = 0;
	bool ayy = 1;
	while (ayy == true)
	{
		cout << "How many people would you like to play?" << endl;
		cin >> players;
		cout << endl << "How many jumps until removal?" << endl;
		cin >> jump;
		ListMyJosephus list(players, jump); // Inserts player
		clock_t start_list = clock(); // starts recording the time
		while (list.currentSize() > 1)
		{
			list.iterate(); // Iterates
			list.eliminateNext(); // Eliminates the player
			list.printAll(); // Print the player
			cout << endl;
		}
		clock_t end_list = clock(); // Stops the time recorder
		cout << "CPU elapsed time in milliseconds for the vector: "
			<< ((double)(end_list - start_list) / CLOCKS_PER_SEC) * 1000 << endl;
		cout << "CPU average time in milliseconds for the vector: "
			<< (((double)(end_list - start_list) / CLOCKS_PER_SEC) / players) * 1000 << endl;
		list.print_winner();
		cout << "Players: " << players << endl;
		cout << "jump: " << jump << endl;
		cout << "Play again? " << endl;
		cin >> ayy;
	}

	system("pause");

	return 0;
}