#pragma once
#include "Player.h"
#include "Monster.h"

class Chamber
{
private:
	int number;			// chamber number
	Chamber* n1;		// previous
	Chamber* n2;		// other
	Chamber* n3;		// next
	Player* player;
	Monster* monster;
	bool catapult;
	bool floor;
	bool arrow;
	
public:
	Chamber(const int chamber);
	~Chamber();

	Chamber* addChamber(Chamber* n);			// Create new chamber.
	void setConnection_1(Chamber* n);		
	void setConnection_2(Chamber* n);			// set connections.
	void setConnection_3(Chamber* n);
	void printInfo();							// Print info about current chamber.
	void printDebug();							// printInfo for all.
	void infoForPlayer();						// Print info for player.
	void monsterMove(Chamber* m, Chamber* p);	// Monster AI;
	bool shoot(int direction);					// shoot.
	Chamber* rewind(); 							// return first chamber on list.
	Chamber* shift(int n); 						// return Nth chamber from current position
	Chamber* move(int direction);				// move player.
	Chamber* check(); 							// check what is in chamber.
	Chamber* throwPlayer(int chamber);			// catapult throw player to chamber.
	Chamber* findChamber(int n);				// find chamber with n number.
	

	
	// SETTERS
	void setPlayer(Player *player){ this->player = player; }
	void setMonster(Monster *monster){ this->monster = monster; }
	void setCatapult(bool exist) { this->catapult = exist;}
	void setArrow(bool exist) { this->arrow = exist; }
	void setFloor(bool exist) { this->floor = exist; }
		
	// GETTERS
	int getNumber(){ return this->number; }
	Player* getPlayer(){ return this->player; }
	Monster* getMonster() { return this->monster; }
	bool getCatapult() { return this->catapult; }
	bool getFloor() { return this->floor; }
	bool getArrow() { return this->arrow; }
	Chamber* getN1() { return this->n1; }
	
};