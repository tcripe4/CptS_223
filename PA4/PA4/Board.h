#ifndef _BOARD_H_
#define _BOARD_H_

#pragma

#include <iostream>
#include <string>
#include <map> 
#include <iterator> 
#include <cstdlib>
#include <fstream>

#include "Player.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::map;
using std::iterator;

class Board
{
public:

	Board(int board);
	~Board();

	bool insert(int playerid, int xposition, int yposition);
	bool remove(int playerid);
	bool find(int playerid);
	int moveTo(int playerid, int xposition, int yposition);
	void printById();

private:
	int boardSize;
	int numPlayers;
	map <int, Player> game;
};

#endif
