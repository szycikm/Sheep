#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Names.h"

// randomizes new coordinates respecting the world limits
coordinates_t Organism::RandomizeNextField(coordinates_t oldPosition)
{
	auto nextPosition = oldPosition;
	auto cont = true;
	while (cont)
	{
		switch (rand() % 4)
		{
		case 0:
			if (nextPosition.x +1 < fromWorld.GetMaxXY().x)
			{
				nextPosition.x++;
				cont = false;
			}
			break;
		case 1:
			if (nextPosition.x > 0)
			{
				nextPosition.x--;
				cont = false;
			}
			break;
		case 2:
			if (nextPosition.y +1 < fromWorld.GetMaxXY().y)
			{
				nextPosition.y++;
				cont = false;
			}
			break;
		case 3:
			if (nextPosition.y > 0)
			{
				nextPosition.y--;
				cont = false;
			}
			break;
		}
	}
	return nextPosition;
}

Organism::Organism(World& fromWorld, coordinates_t position): fromWorld(fromWorld), position(position), age(0){}

char Organism::GetType() const
{
	return type;
}

char Organism::Draw() const
{
	// if organism is below 5 turns draw it small. Just for fun.
	return age <= ADULT_AGE ? Names::GetLowercaseSymbol(type) : type;
}

coordinates_t Organism::GetXY() const
{
	return position;
}

int Organism::GetAge() const
{
	return age;
}

int Organism::GetStrength() const
{
	return strength;
}

int Organism::GetInitiative() const
{
	return initiative;
}

void Organism::IncrementAge()
{
	age++;
}