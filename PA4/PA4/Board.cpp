#include "Board.h"

Board::Board(int board)
{
	this->boardSize = board;
	this->numPlayers = 0;
}

Board::~Board()
{


}

// will allow you to add a new player to the board. The method should take as input the player ID to be inserted, 
// along with a desired(x, y) position into which it is to be initially placed. For successful insertion, (i)a player with the same ID 
// should not already exist on the board; AND(ii) the specified insertion position on board should be currently unoccupied.
// A third condition would be to ensure the total number of players with this insertion(i.e., n) should not exceed m. If successful, 
// the method should update n and return true. If insertion fails, the code should display an appropriate error message and return
// false without changing anything
bool Board::insert(int playerid, int x, int y)
{
	vector<int> new_pos;
	Player new_player(x, y, playerid);
	new_pos.push_back(x);
	new_pos.push_back(y);

	map <int, Player> ::iterator itr;
	int size = static_cast<int>(game.size());
	for (itr = game.begin(); itr != game.end(); ++itr)
	{
		if (itr->second.get_ID() == playerid)
		{
			cout << "Sorry! Player ID (" << playerid << ") already in use" << endl;
			return 0;
		}
	}
	if ((numPlayers + 1) != boardSize) // check that numPlayers does not exceed board size
	{
		if (x <= boardSize && y <= boardSize) // check if insert position within board
		{
			for (itr = game.begin(); itr != game.end(); ++itr)
			{
				if (x == itr->second.get_x() && y == itr->second.get_y())
				{
					// tests all players, if already taken, kicks player out of function
					cout << "Someone's already in that spot! (" << x << "," << y << ")" << endl;
					return 0;
				}
			}
			game.insert(std::pair<int, Player>(playerid, new_player)); // insert player
			cout << "Player " << playerid << " successfully entered @ (" << x << "," << y << ")" << '\n';
		}
		else
		{
			cout << "Not within the board limits! " << boardSize << " x " << boardSize << endl;
			return 0;
		}
	}
	else
	{
		cout << "Too many players for board size!" << endl;
	}


	numPlayers += 1; // if successful, increase numPlayers by one
	return true;
}

// will allow you to remove a player from the board.The method should take as input the player ID to be removed, and should return true 
// upon successful removal and false otherwise(i.e., player not found).The value of n should also be accordingly updated. Note that upon 
// successful removal, the corresponding cell on the board should become available for newer insertions
bool Board::remove(int playerid)
{
	map<int, Player>::iterator thing = game.find(playerid);
	if (thing != game.end())
	{
		game.erase(thing);
		numPlayers -= 1;
		cout << "Player with key " << playerid << " has been removed." << endl;
		return true;
	}
	else
	{
		cout << "Player (" << playerid << ") does not exist" << endl;
		return false;
	}

}

// is given a player ID and returns true if the player is found and false otherwise
bool Board::find(int playerid)
{
	map<int, Player>::iterator thing;
	thing = game.find(playerid);
	if (thing != game.end())
	{
		cout << "Player " << thing->second.get_ID() << " @ (" << thing->second.get_x() << "," << thing->second.get_y() << ")" << '\n';
		return true;
	}
	else
	{
		cout << "Person does not exist" << endl;
		return false;
	}

}

// takes as input a player ID and a destination (x2, y2) cell position. The method should first locate the player, and move the player
// from its current position, say (x1, y1) to the new position (x2, y2) only if:
//		- (x2, y2) is within the bounds
//		- the movement from (x1, y1) to (x2, y2) is always along the same row or column or same diagonal in any direction (ie. top-left -
//		  - right-bottom or top-right -- left-bottom)
// Additional action is necessary if the destination cell (x2,y2) already has some other player, say Y. Then this function should first 
// remove Y from the board before placing this player(ID) in its new position. Upon a successful move, the method should return true.
// If any player was removed in the process, the method should print a message to indicate which player was removed. If the move fails, 
// the code should display an error message stating the reason of failure and return false.
int Board::moveTo(int ID, int X, int Y)
{
	vector<int> new_pos;
	new_pos.push_back(X);
	new_pos.push_back(Y);

	vector<int> old_pos;
	int old_x = game[ID].get_x();
	int old_y = game[ID].get_y();

	int temp_x = 0;
	int temp_y = 0;

	int compare_y = 0;
	int compare_x = 0;

	bool check = 0;
	if (X <= boardSize && Y <= boardSize)
	{
		if (X == old_x) // checks for same row
		{
			check = 1;
		}
		else if (Y == old_y) // checks for same row
		{
			check = 1;
		}
		else if (Y != old_y && X != old_x)
		{
			if (Y > old_y && X > old_x) // if new coordinates are greater than old coordinates
			{
				compare_y = Y; // sets to highest y int
				compare_x = X;
				compare_y -= old_y; // hight int minus low int
				compare_x -= old_x;

				if (compare_y == compare_x)
				{
					check = 1;
				}
			}
			else if (Y < old_y && X > old_x) // if new Y is less than old Y and new X is greater than old X
			{
				compare_y = old_y; // sets to highest y int
				compare_x = X;
				compare_y -= Y; // hight int minus low int
				compare_x -= old_x;

				if (compare_y == compare_x)
				{
					check = 1;
				}
			}
			else if (Y > old_y && X < old_x) // if new Y is larger than old Y and new X is lower than old X
			{
				compare_y = Y; // sets to highest y int
				compare_x = old_x;
				compare_y -= old_y; // hight int minus low int
				compare_x -= X;

				if (compare_y == compare_x)
				{
					check = 1;
				}
			}
			else // if new X and Y are lower then old X and old Y
			{
				compare_y = old_y; // sets to highest y int
				compare_x = old_x;
				compare_y -= Y; // hight int minus low int
				compare_x -= X;

				if (compare_y == compare_x)
				{
					check = 1;
				}
			}
		}
		if (compare_y != compare_x)
		{
			cout << "Invalid move! Must be up, down or diagonal" << endl;
			check = 0;
		}
	}
	if (check == 1)
	{
		map <int, Player> ::iterator itr;
		for (itr = game.begin(); itr != game.end(); ++itr)
		{
			if (new_pos[0] == itr->second.get_x() && new_pos[1] == itr->second.get_y())
			{
				cout << "The move is valid.... Moving Player " << ID << endl;
				remove(itr->second.get_ID());
				break;
			}
		}
		map<int, Player>::iterator thing;
		thing = game.find(ID);
		thing->second.set_position(X, Y);
	}

	else
	{
		cout << "Not within the board limits!" << endl;
	}
	return check;

}


// prints all the player IDs along with their (x, y) positions, in the increasing order of their IDs. Again, the print should not display 
// any unoccupied positions.
void Board::printById()
{
	cout << "Printing game board..." << endl;
	map <int, Player> ::iterator itr;
	for (itr = game.begin(); itr != game.end(); ++itr)
	{
		if (itr->second.get_ID() > 0)
		{
			cout << "Player " << itr->second.get_ID() << " @ (" << itr->second.get_x() << "," << itr->second.get_y() << ")" << '\n';
		}
	}
	cout << endl;
}
