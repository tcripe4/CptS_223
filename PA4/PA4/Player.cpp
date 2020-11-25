#include "Player.h"

Player::Player(int X = -1, int Y = -1, int id = -1)
{
	this->x = X;
	this->y = Y;
	this->ID = id;
	this->position[0] = X;
	this->position[1] = Y;
}

Player::Player()
{

}

int Player::get_x()
{
	return this->x;
}

int Player::get_y()
{
	return this->y;
}

int Player::get_ID()
{
	return this->ID;
}

vector<int> Player::get_position()
{
	return position;

}

void Player::set_ID(int id)
{
	this->ID = id;
}

void Player::set_position(int X, int Y)
{
	this->x = X;
	this->y = Y;
}






