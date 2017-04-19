#include <conio.h>
#include <iostream>
#include <string>
#include "Human.h"
#include "Output.h"

Human::Human(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->type = 'H';
	this->strength = 5;
	this->initiative = 4;
	this->specialCountdown = 0;
}

Human* Human::Clone(World& fromWorld, coordinates_t position)
{
	return new Human(fromWorld, position);
}

void Human::Action()
{
	Output::GoToXY(0, CONSOLE_HEIGHT);

	if (this->specialCountdown > 0)
	{
		this->specialCountdown--;
		this->strength--;
		Output::log << this->Introduce() << "'s strength is dropping! " << this->specialCountdown << " turns till normal" << this->strength << std::endl;
	}

	std::cout << "Waiting for human input...";
	char c;
	while (true)
	{
		c = _getch();
		switch (c)
		{
		case KEY_UP:
			Move(coordinates_t{ this->position.x, this->position.y - 1 });
			return;
			break;
		case KEY_DOWN:
			Move(coordinates_t{ this->position.x, this->position.y + 1 });
			return;
			break;
		case KEY_RIGHT:
			Move(coordinates_t{ this->position.x + 1, this->position.y });
			return;
			break;
		case KEY_LEFT:
			Move(coordinates_t{ this->position.x - 1, this->position.y });
			return;
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