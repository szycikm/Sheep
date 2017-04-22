#include <conio.h>
#include <iostream>
#include <string>
#include "Human.h"
#include "World.h"
#include "Output.h"

void Human::Init()
{
	this->type = 'H';
	this->strength = 5;
	this->initiative = 4;
	this->specialCountdown = 0;
}

Human::Human(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Human::Human(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Human::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Human>(Human(fromWorld, position));
}

void Human::Action()
{
	Output::GoToXY(0, CONSOLE_HEIGHT);

	if (this->specialCountdown > 0)
	{
		this->specialCountdown--;
		this->strength--;
		Output::log << this->Introduce() << "'s strength is dropping! " << this->specialCountdown << " turns till normal" << std::endl;
	}

	std::cout << "Waiting for human input...";
	char c;
	while (true)
	{
		c = _getch();
		switch (c)
		{
		case KEY_UP:
			if (this->position.y - 1 >= 0)
			{
				Move(coordinates_t{ this->position.x, this->position.y - 1 });
				return;
			}
			break;
		case KEY_DOWN:
			if (this->position.y + 1 < this->GetWorld().GetMaxXY().y)
			{
				Move(coordinates_t{ this->position.x, this->position.y + 1 });
				return;
			}
			break;
		case KEY_RIGHT:
			if (this->position.x + 1 < this->GetWorld().GetMaxXY().x)
			{
				Move(coordinates_t{ this->position.x + 1, this->position.y });
				return;
			}
			break;
		case KEY_LEFT:
			if (this->position.x - 1 >= 0)
			{
				Move(coordinates_t{ this->position.x - 1, this->position.y });
				return;
			}
			break;
		case KEY_SPECIAL:
			if (this->specialCountdown <= 0)
			{
				Output::log << this->Introduce() << " used their special ability!" << std::endl;
				this->specialCountdown = SPECIAL_COUNTDOWN;
				this->strength = SPECIAL_STRENGTH;
				return;
			}
			else
				Output::log << this->Introduce() << "'s special ability is not done recoiling" << std::endl;
			break;
		case KEY_QUIT:
			return;
			break;
		}
	}
}