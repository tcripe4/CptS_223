//#include "ListMyJosephus.h"
//#include<ctime>
//#include<iostream>
//
//int main()
//{
//	int players = 0, jump = 0;
//	bool ayy = 1;
//	while (ayy == true)
//	{
//		cout << "How many people would you like to play?" << endl;
//		cin >> players;
//		cout << endl << "How many jumps until removal?" << endl;
//		cin >> jump;
//		ListMyJosephus list(players, jump);
//		clock_t start = clock();
//		while (list.currentSize() > 1)
//		{
//			list.iterate();
//			list.eliminateNext();
//			list.printAll();
//			cout << endl;
//		}
//		clock_t end = clock();
//		cout << "CPU elapsed time in milliseconds for the list: "
//			<< ((double)(end - start) / CLOCKS_PER_SEC) * 1000 << endl;
//		cout << "CPU average time in milliseconds for the list: "
//			<< (((double)(end - start) / CLOCKS_PER_SEC) / players) * 1000 << endl;
//		list.print_winner();
//		cout << "Players: " << players << endl;
//		cout << "Jump: " << jump << endl;
//		cout << "Play again? " << endl;
//		cin >> ayy;
//	}
//
//	system("pause");
//
//	return 0;
//}