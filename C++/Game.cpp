#include "Game.h"

Game::Game()
{
	this->playing = true;
}
Game::~Game()
{
	
}
void Game::game()
{
	int selectOption = NULL;
	while(selectOption != 5)
	{
		drawMenu();
		selectOption = _getch() - '0';
		switch(selectOption)
		{
			case 1:
				newGame();
				break;
			case 2:
				drawInstructions();
				break;
			case 3:
				drawAboutAuthor();
				break;
			case 4:
				drawAboutGame();
				break;
			case 5:
				playing = false;
				exit(0);
				break;
			default:
				break;
		}	
	}
}

void Game::drawMenu()
{
	system("CLS");
	std::cout << "\t\t __________________________________  \n";
	std::cout << "\t\t|          Hunt The Wumpus         | \n";
	std::cout << "\t\t|                MENU              | \n";
	std::cout << "\t\t|----------------------------------| \n";
	std::cout << "\t\t|1.            New Game            | \n";
	std::cout << "\t\t|2.          Instructions          | \n";
	std::cout << "\t\t|3.          About Author          | \n";
	std::cout << "\t\t|4.           About Game           | \n";
	std::cout << "\t\t|5.              Exit              | \n";
	std::cout << "\t\t|__________________________________| \n";
}

void Game::drawInstructions()
{
	system("CLS");
	std::cout << "\t\t __________________________________  \n";
	std::cout << "\t\t|          Hunt The Wumpus         | \n";
	std::cout << "\t\t|            INSTRUCTIONS          | \n";
	std::cout << "\t\t|----------------------------------| \n";
	std::cout << "\t\t|Move-type 'm'+direction: 1,2 or 3 | \n";
	std::cout << "\t\t|Example: m2                       | \n";
	std::cout << "\t\t|Shoot-type 's'+direction: 1,2 or 3| \n";
	std::cout << "\t\t|Example: s3                       | \n";
	std::cout << "\t\t|Debug - type 'd'                  | \n";
	std::cout << "\t\t|Reset - type 'r'                  | \n";
	std::cout << "\t\t|Exit - type 'e'                   | \n";
	std::cout << "\t\t|                                  | \n";
	std::cout << "\t\t|EVERYTHING IS ALLOCATE RANDOMLY   | \n";
	std::cout << "\t\t|__________________________________| \n";
	std::cout << "\t\tPress any key to back to menu.";
	_getch();
}

void Game::drawAboutAuthor()
{
	system("CLS");
	std::cout << "\t\t __________________________________  \n";
	std::cout << "\t\t|          Hunt The Wumpus         | \n";
	std::cout << "\t\t|            ABOUT AUTHOR          | \n";
	std::cout << "\t\t|----------------------------------| \n";
	std::cout << "\t\t|  POLITECHNIKA SLASKA             | \n";
	std::cout << "\t\t|  Wydzial Matematyki Stosowanej   | \n";
	std::cout << "\t\t|  Informatyka Semestr III         | \n";
	std::cout << "\t\t|                                  | \n";
	std::cout << "\t\t|  ARTUR BEDNARCZYK                | \n";
	std::cout << "\t\t|  Grupa A.                        | \n";
	std::cout << "\t\t|__________________________________| \n";
	std::cout << "\t\tPress any key to back to menu.";
	_getch();
}

void Game::drawAboutGame()
{
	system("CLS");
	std::cout << "\t\t __________________________________  \n";
	std::cout << "\t\t|          Hunt The Wumpus         | \n";
	std::cout << "\t\t|            ABOUT GAME            | \n";
	std::cout << "\t\t|----------------------------------| \n";
	std::cout << "\t\t|  Wumpus is moving when shoot.    | \n";
	std::cout << "\t\t|  Catapult throw player to random.| \n";
	std::cout << "\t\t|  No floor = player die.          | \n";
	std::cout << "\t\t|  Monster does not care about     | \n";
	std::cout << "\t\t|  floor or catapults.             | \n";
	std::cout << "\t\t|  Shoot range = one chamber.      | \n";
	std::cout << "\t\t|__________________________________| \n";
	std::cout << "\t\tPress any key to back to menu.";
	_getch();
}

void Game::newGame()
{
	srand((unsigned int)time(NULL));
	noFloor = rand()%3;
	arrows = rand()%3;
	catapults = rand()%3;
	
	newPlayerPosition = rand()%20+1;
	do
	{
		newMonsterPosition = rand()%20+1;
	}while(newMonsterPosition == newPlayerPosition);
	
	system("CLS");
	std::cout << "\t\t __________________________________  \n";
	std::cout << "\t\t|Welcome strange. You came to      | \n";
	std::cout << "\t\t|dangerous place... Tell us your   | \n";
	std::cout << "\t\t|name.                             | \n";
	std::cout << "\t\t Type your name: ";
	std::cin >> playerName;
	std::cout << "\t\t Nice to meet you " << playerName << ". \n";
	std::cout << "\t\t|I hope that we will see each other| \n";
	std::cout << "\t\t|again.                            | \n";
	std::cout << "\t\t|Here you have 5 arrows. In cave   | \n";
	std::cout << "\t\t|maybe you will find more of them. | \n";
	std::cout << "\t\t|If you wanna leave this place     | \n";
	std::cout << "\t\t|alive you have to kill Wumpus.    | \n";
	std::cout << "\t\t|You will feel him.                | \n";
	std::cout << "\t\t|                                  | \n";
	std::cout << "\t\t| You have 5 arrows.               | \n";
	std::cout << "\t\t|You can find 0-2 arrows           | \n";
	std::cout << "\t\t|There are 20 chambers in cave     | \n";
	std::cout << "\t\t|0-2 contain catapults, which throw| \n";
	std::cout << "\t\t|you in random place.              | \n";
	std::cout << "\t\t|0-2 don't contain floor...        | \n";
	std::cout << "\t\t|you will die if go in.            | \n";
	std::cout << "\t\t|You will know if danger is nearby.| \n";
	std::cout << "\t\t|__________________________________| \n";
	std::cout << "\t\tClick any button to continue...";
	_getch();
	
	prepareChambers();
}

void Game::prepareChambers()
{
	system("CLS");
	srand((unsigned int)time(NULL));
	int random;
	// CREATING LIST OF CHAMBERS
	Chamber *chamber = new Chamber(1);
	// Create full cave with setting connections
	for(int i = 2; i <= 20; i++)
	{
		chamber = chamber->addChamber(new Chamber(i));
	}
	chamber = chamber->rewind();
	// connect first and last element
	chamber->shift(0)->setConnection_1(chamber->shift(19));
	chamber->shift(19)->setConnection_3(chamber->shift(0));
	chamber->shift(0)->setConnection_2(chamber->shift(9));
	chamber->shift(19)->setConnection_2(chamber->shift(10));
	// mid connections	
	for(int i = 1; i < 19; i++)
	{
		if(i > 0)chamber->shift(i)->setConnection_2(chamber->shift(19-i));
	}
	chamber->shift(9)->setConnection_2(chamber->shift(0));
	chamber->shift(10)->setConnection_2(chamber->shift(19));
	
	Player *player = new Player(newPlayerPosition, playerName);
	Monster *monster = new Monster(newMonsterPosition, "Wumpus");
	
	
	chamber->findChamber(newPlayerPosition)->setPlayer(player);
	chamber->findChamber(newMonsterPosition)->setMonster(monster);
	for(int i = 0; i < catapults; i++)
	{
		random = rand()%20;
		if(chamber->shift(random)->getPlayer() == nullptr &&
		chamber->shift(random)->getMonster() == nullptr &&
		chamber->shift(random)->getCatapult() == false &&
		chamber->shift(random)->getFloor() == true &&
		chamber->shift(random)->getArrow() == false)
		{
			chamber->shift(random)->setCatapult(true);
		}
		else i--;
	}
	for(int i = 0; i < noFloor; i++)
	{
		random = rand()%20;
		if(chamber->shift(random)->getPlayer() == nullptr &&
		chamber->shift(random)->getMonster() == nullptr &&
		chamber->shift(random)->getCatapult() == false &&
		chamber->shift(random)->getFloor() == true &&
		chamber->shift(random)->getArrow() == false)
		{
			chamber->shift(random)->setFloor(false);
		}
		else i--;
	}
	for(int i = 0; i < arrows; i++)
	{
		random = rand()%20;
		if(chamber->shift(random)->getPlayer() == nullptr &&
		chamber->shift(random)->getMonster() == nullptr &&
		chamber->shift(random)->getCatapult() == false &&
		chamber->shift(random)->getFloor() == true &&
		chamber->shift(random)->getArrow() == false)
		{
			chamber->shift(random)->setArrow(true);
		}
		else i--;
	}
	actualGame(chamber, monster, player);
}

void Game::actualGame(Chamber* chamber, Monster* monster, Player* player)
{
	std::string select;
	chamber = chamber->findChamber(player->getPosition());
	
	while(1)
	{
		system("cls");
		chamber = chamber->check();
		if(player->getLife() == false && monster->getLife() == true)
		{
			theEnd(false, player, monster, chamber);
		}
		if(monster->getLife() == false && player->getLife() == true)
		{
			theEnd(true, player, monster, chamber);
		}
		
		
		chamber->infoForPlayer();
		std::cout << std::endl;
		std::cin >> select;
		if(select.length() == 2)
		{
			if(select[0] == 'm')
			{
				chamber = chamber->move(select[1]-'0');
			}
			else if(select[0] == 's')
			{
				if((select[1]-'0' <= 3 && select[1]-'0' >= 1))
				{
					if(chamber->shoot(select[1]-'0') == true)
					{
						monster->die();
						std::cout << "\n You killed monster named " << monster->getName() << ". You won!";
					}
					else if(player->getArrows() > 0)
					{
						std::cout << "\n Nothing happend... But monster could hear you...";
						chamber->monsterMove(chamber->findChamber(monster->getPosition()), chamber);
					}
					_getch();
				}				
			}	
		}
		else if(select.length() == 1)
		{
			if(select[0] == 'd')
			{
				system("cls");
				chamber->findChamber(1)->printDebug();
				std::cout << "\n Click something to continue...";
				_getch();
			}
			else if(select[0] == 'e')
			{
				freeMemory(chamber, player, monster);
				game();
			}
			else if(select[0] == 'r')
			{
				freeMemory(chamber, player, monster);
				newGame();
			}
		}		
	}
}

void Game::theEnd(bool win, Player* player, Monster* monster, Chamber* chamber)
{
	if(win == true)
	{
		std::cout << "\n CONGRATZZZZ! YOU WON THE GAME!";
	}else
	{
		std::cout << "\n I am sorry... You lost.";
	}
	std::cout << "\n You did " << player->getMoves() << " moves.\n You fought with " << monster->getName() << ".\n You end in chamber " << chamber->getNumber();
	freeMemory(chamber, player, monster);
	_getch();
	game();
}

void Game::freeMemory(Chamber* chamber, Player* player, Monster* monster)
{
	delete player;
	delete monster;
	chamber = chamber->rewind();
	for(int i = 1; i < 20; i++)
	{
		delete chamber->shift(i);		
	}
	delete chamber;
}