#pragma once
#include <iostream>	 
#include <string>		// names
#include <conio.h>  	// _getch
#include <time.h>		// random
#include <stdlib.h> 	// exit
#include "Player.h"	
#include "Monster.h"
#include "Chamber.h"
class Game
{
private:
	bool playing;
	int catapults;
	int noFloor;
	int arrows;
	int newPlayerPosition;
	int newMonsterPosition;
	std::string playerName;
	
	// METHODS
	void drawMenu();
	void drawInstructions();
	void drawAboutAuthor();
	void drawAboutGame();
	void newGame();					// random numbers + creating character
	void prepareChambers();			// create player, monster, chamber list
	void actualGame(Chamber* chamber, Monster* monster, Player* player);
	void theEnd(bool win, Player* player, Monster* monster, Chamber* chamber);
	void freeMemory(Chamber* chamber, Player* player, Monster* monster);
	
public:
	Game();
	~Game();

	void game();
	
};