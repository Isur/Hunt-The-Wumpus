#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	int arrows;
	int position;
	int moves;
	bool life;
	
public:
	Player(int pos, std::string name);
	~Player();

	std::string getName(){ return this->name; }
	int getArrows(){ return this->arrows; }
	int getPosition(){ return this->position; }
	int getMoves(){ return this->moves; }
	bool getLife() { return this->life; }
	
	void setLife(bool life) { this->life = life; }
	void setPosition(int pos) { this->position = pos; }
		
	void addArrow() { this->arrows++; }
	void addMove() { this->moves++; }
	void useArrow() { this->arrows--; }
	void die() { this->life = false;}
};