//#include "VectorMyJosephus.h"
//#include<ctime>
//#include<iostream>
//
//int main()
//{
//	int players = 0, jump = 0, average = 0;
//	bool ayy = 1;
//	while (ayy == true)
//	{	
//		cout << "How many people would you like to play?" << endl;
//		cin >> players;
//		cout << endl << "How many jumps until removal?" << endl;
//		cin >> jump;
//		VectorMyJosephus vector(players, jump); // Inserts player
//		clock_t start_vector = clock(); // starts recording the time
//		while (vector.currentSize() > 1)
//		{
//			vector.iterate(); // Iterates
//			vector.eliminateNext(); // Eliminates the player
//			vector.printAll(); // Print the player
//			cout << endl;
//		}
//		clock_t end_vector = clock(); // Stops the time recorder
//		cout << "CPU elapsed time in milliseconds for the vector: "
//			<< ((double)(end_vector - start_vector) / CLOCKS_PER_SEC) * 1000 << endl;
//		cout << "CPU average time in milliseconds for the vector: "
//			<< (((double)(end_vector - start_vector) / CLOCKS_PER_SEC) / players) * 1000 << endl;
//		vector.print_winner();
//		cout << "Players: " << players << endl;
//		cout << "jump: " << jump << endl;
//		cout << "Play again? " << endl;
//		cin >> ayy;
//	}
//
//	system("pause");
//
//	return 0;
//}