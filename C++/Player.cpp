#include "Player.h"

Player::Player(int pos, std::string name)
{
	this->position = pos;
	this->name = name;
	this->life = true;
	this->arrows = 5;
	this->moves = 0;
}
Player::~Player()
{

}