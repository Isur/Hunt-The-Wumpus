#include <iostream>
#include <windows.h>
#include "Game.h"


int main()
{
	SetConsoleTitle("Hunt The Wumpus");
    
	Game *game = new Game();
	game->game();
	delete game;
	
	std::cout << "\n \t\t THE END \n";
	return 0;
}
