#include "Monster.h"

Monster::Monster(int pos, std::string name)
{
	this->name = name;
	this->position = pos;
	this->life = true;
}

Monster::~Monster()
{

}