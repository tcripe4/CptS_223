#ifndef _PLAYER_H_
#define _PLAYER_H_
#pragma

#include <iostream>
#include <string>
#include <map> 
#include <iterator> 
#include <vector>
#include <cstdlib>
#include <fstream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::vector;

class Player
{
public:
	Player(int X, int Y, int id);

	Player();

	int get_x();
	int get_y();
	int get_ID();
	vector<int> get_position();

	void set_position(int X, int Y);
	void set_ID(int id);

private:
	int x;  // position on game board
	int y;  // position on game board
	int ID;
	vector <int> position = { this->x, this->y };
}; 

#endif

