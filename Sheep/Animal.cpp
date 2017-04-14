#include <iostream>
#include <random>
#include <string>
#include "Animal.h"
#include "Output.h"
#include "World.h"

// default animal collision logic. Returns if animal should be moved or not
bool Animal::Collision(Organism* other)
{
	if (other == nullptr)
	{
		// nothing stands on this field -> just move there
		return true;
	}
	else if (type == other->GetType())
	{
		// animal of the same type stands on this field -> just have sex and don't move there
		auto newCoordinates = coordinates;
		newCoordinates.x++;
		/*if (fromWorld.isFieldOccupied(newCoordinates)
		{
			auto newCoordinates = RandomizeNextField(coordinates);
		}*/
		return false;
	}
	else
	{
		// stronger (or attacker) wins and takes looser's field
		if (strength >= other->GetStrength())
		{
			std::cout << this->GetType() << " ate " << other->GetType() << std::endl;
			Output::AppendLog(std::string(1, this->GetType()) + " ate " + std::string(1, other->GetType()));
			other->fromWorld.RemoveOrganism(other);
		}
		else
		{
			std::cout << other->GetType() << " ate " << this->GetType() << std::endl;
			Output::AppendLog(std::string(1, other->GetType()) + " ate " + std::string(1, this->GetType()));
			fromWorld.RemoveOrganism(this);
		}
		return true;
	}
}

// randomizes new coordinates respecting the world limits
coordinates_t Animal::RandomizeNextField(coordinates_t oldCoordinates)
{
	auto nextCoordinates = coordinates;
	auto cont = true;
	while (cont)
	{
		switch (rand() % 4)
		{
		case 0:
			if (nextCoordinates.x < fromWorld.GetMaxXY().x)
			{
				nextCoordinates.x++;
				cont = false;
			}
			break;
		case 1:
			if (nextCoordinates.x > 0)
			{
				nextCoordinates.x--;
				cont = false;
			}
			break;
		case 2:
			if (nextCoordinates.y < fromWorld.GetMaxXY().y)
			{
				nextCoordinates.y++;
				cont = false;
			}
			break;
		case 3:
			if (nextCoordinates.y > 0)
			{
				nextCoordinates.y--;
				cont = false;
			}
			break;
		}
	}
	return nextCoordinates;
}

// default animal movement
void Animal::Action()
{
	auto nextCoordinates = RandomizeNextField(coordinates);
	auto collider = fromWorld.isFieldOccupied(nextCoordinates);
	if (Collision(collider))
		coordinates = nextCoordinates;
}