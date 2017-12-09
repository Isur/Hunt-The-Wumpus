#include "Chamber.h"

Chamber::Chamber(const int chamber)
	:number{ chamber }
{
	this->n1 = nullptr;
	this->n2 = nullptr;
	this->n3 = nullptr;
	this->player = nullptr;
	this->monster = nullptr;
	catapult = false;
	floor = true;
	arrow = false;
}

Chamber::~Chamber()
{
	
}

Chamber* Chamber::addChamber(Chamber* n)
{
	this->n3 = n;
	n->n1 = this;
	return n;
}

void Chamber::setConnection_1(Chamber *n)
{
	this->n1 = n;
}
void Chamber::setConnection_2(Chamber *n)
{
	this->n2 = n;
}
void Chamber::setConnection_3(Chamber *n)
{
	this->n3 = n;
}

Chamber* Chamber::rewind()
{
	if(this->n1->getNumber() != 1) return this->n1->rewind();
	return this->n1;
}

Chamber* Chamber::shift(int n)
{
	if(n > 0)
	{
		if(this->n3 != nullptr) return this->n3->shift(n-1);	
		else return this;
	}
	else if(n < 0)
	{
		if(this->n1 != nullptr) return this->n1->shift(n+1);	
		else return this;
	}
	return this;
}

void Chamber::printDebug()
{
	for(int i = 0; i < 20; i++)
	{
		this->shift(i)->printInfo();
		if(this->shift(i)->getPlayer() != nullptr) std::cout << "Player: " << this->shift(i)->getPlayer()->getName() << " has " << this->shift(i)->getPlayer()->getArrows() << " arrows and his life is " << this->shift(i)->getPlayer()->getLife();
		if(this->shift(i)->getMonster() != nullptr) std::cout << "Monster: " << this->shift(i)->getMonster()->getName() << " and his life is " << this->shift(i)->getMonster()->getLife();
	}
}

void Chamber::printInfo()
{
	std::cout << "\n Chamber " << this->number << " contains: ";
	if(this->n1 != nullptr) std::cout << "\t -> " << n1->getNumber();
	if(this->n2 != nullptr) std::cout << "\t -> " << n2->getNumber();
	if(this->n3 != nullptr) std::cout << "\t -> " << n3->getNumber();
	std::cout << "\t";
	if(this->player != nullptr) std::cout << "| " << player->getName() << " |";
	if(this->monster != nullptr) std::cout << "| " << monster->getName() << " |";
	if(this->catapult == true) std::cout << "| CATAPULT |";
	if(this->floor == false) std::cout << "| NO FLOOR |";
	if(this->arrow == true) std::cout << "| ARROW |";
}

bool Chamber::shoot(int direction)
{
	if(player->getArrows() == 0)
	{
		std::cout << "\n You don't have arrows. Find or die.";
	}
	else
	{
		if(direction == 1) 
		{
			player->useArrow();
			if(this->n1->getMonster()!=nullptr) 
			{	
				return true;
			}
		}
		else if(direction == 2)
		{
			player->useArrow();
			if(this->n2->getMonster()!=nullptr)
			{
				return true;
			}
		}
		else if(direction == 3)
		{			
			player->useArrow();
			if(this->n3->getMonster()!=nullptr)
			{			
				return true;
			}
		}
		else 
		{
			std::cout << "\n Wrong choice... Try again.";
		}
	}
	
	return false;
}

Chamber* Chamber::move(int direction)
{
	
	if(direction == 1)
	{
		player->addMove();
		this->n1->setPlayer(player);
		player->setPosition(this->n1->getNumber());
		this->setPlayer(nullptr);		
		return n1;
	}
	else if(direction == 2)
	{
		player->addMove();
		this->n2->setPlayer(player);
		player->setPosition(this->n2->getNumber());
		this->setPlayer(nullptr);
		return n2;
	}
	else if(direction == 3)
	{
		player->addMove();
		this->n3->setPlayer(player);
		player->setPosition(this->n3->getNumber());
		this->setPlayer(nullptr);
		return n3;
	}
	return this;
}

Chamber* Chamber::findChamber(int n)
{
	if(this->getNumber() == n) return this;
	else return this->n1->findChamber(n);
	return this;
}

Chamber* Chamber::throwPlayer(int chamber)
{
	this->player->setPosition(chamber);
	this->findChamber(chamber)->setPlayer(player);
	this->setPlayer(nullptr);
	return this->findChamber(chamber);
}

Chamber* Chamber::check()
{
	if(this->getArrow() == true)
	{
		this->setArrow(false);
		player->addArrow();
		std::cout << "\n You find an arrow! Now you have " << player->getArrows() << " arrow(s)!";
		return this;
	}
	else if(this->getFloor() == false)
	{
		std::cout << "\n There is no floor... you die.";
		player->die();
		return this;
	}
	else if(this->getCatapult() == true)
	{
		int randomChamber = rand()%20+1;
		std::cout << "\n Catapult here! It will throw you to chamber " << randomChamber << "!";
		return this->throwPlayer(randomChamber);	
	}
	else if(this->getMonster() != nullptr)
	{
		std::cout << "\n You found " << monster->getName() << ". You die.";
		player->die();
		return this;
	}
	else
	{
		std::cout << "\n This room is empty.";
		return this;
	}
}

void Chamber::infoForPlayer()
{
	std::cout << "\n You are in chamber " << this->getNumber() <<". You can move [m][1,2,3] or shoot [s][1,2,3].";
	std::cout << "\n You have " << this->player->getArrows() << " arrows.";
	std::cout << "\n Chambers connected: " << this->n1->getNumber() << " | " << this->n2->getNumber() << " | " << this->n3->getNumber();
	if(this->n1->getMonster() != nullptr) std::cout << "\n Something stinks here...";
	if(this->n1->getCatapult() == true) std::cout << "\n Something big is nearby...";
	if(this->n1->getFloor() == false) std::cout << "\n You feel draft...";
	if(this->n2->getMonster() != nullptr) std::cout << "\n Something stinks here...";
	if(this->n2->getCatapult() == true) std::cout << "\n Something big is nearby...";
	if(this->n2->getFloor() == false) std::cout << "\n You feel draft...";
	if(this->n3->getMonster() != nullptr) std::cout << "\n Something stinks here...";
	if(this->n3->getCatapult() == true) std::cout << "\n Something big is nearby...";
	if(this->n3->getFloor() == false) std::cout << "\n You feel draft...";
	
	
}

void Chamber::monsterMove(Chamber* m, Chamber* p)
{
	if(m->n1->getNumber() == p->n1->getNumber() || m->n1->getNumber() == p->n2->getNumber() || m->n1->getNumber() == p->n3->getNumber())
	{
		m->monster->setPosition(m->n1->getNumber());
		m->n1->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else if(m->n2->getNumber() == p->n1->getNumber() || m->n2->getNumber() == p->n2->getNumber() ||	m->n2->getNumber() == p->n3->getNumber())
	{
		m->monster->setPosition(m->n2->getNumber());
		m->n2->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else if(m->n3->getNumber() == p->n1->getNumber() ||	m->n3->getNumber() == p->n2->getNumber() ||	m->n3->getNumber() == p->n3->getNumber())
	{
		m->monster->setPosition(m->n3->getNumber());
		m->n3->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else if(m->n1->getNumber() == p->getNumber())
	{
		m->monster->setPosition(p->getNumber());
		m->n1->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else if(m->n2->getNumber() == p->getNumber())
	{
		m->monster->setPosition(p->getNumber());
		m->n2->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else if(m->n3->getNumber() == p->getNumber())
	{
		m->monster->setPosition(p->getNumber());
		m->n3->setMonster(m->getMonster());
		m->setMonster(nullptr);
	}
	else
	{
		switch(rand()%3+1)
		{
		case 1:
			m->monster->setPosition(m->n1->getNumber());
			m->n1->setMonster(m->getMonster());
			m->setMonster(nullptr);
			break;
		case 2:
			m->monster->setPosition(m->n2->getNumber());
			m->n2->setMonster(m->getMonster());
			m->setMonster(nullptr);
			break;
		case 3:
			m->monster->setPosition(m->n3->getNumber());
			m->n3->setMonster(m->getMonster());
			m->setMonster(nullptr);
			break;
		default:
			break;
		}
	}
}