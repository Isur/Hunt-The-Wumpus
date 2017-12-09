#pragma once
#include <iostream>
#include <string>

class Monster
{
private:
	std::string name;
	int position;
	bool life;

public:
	Monster(int pos, std::string name);
	~Monster();

	
	std::string getName(){ return this->name; }
	int getPosition(){ return this->position; }
	bool getLife() { return this->life; }
	
	void setLife(bool life) { this->life = life; }
	void setPosition(int pos) { this->position = pos; }
	
	void die(){ this->life = false;}
};
