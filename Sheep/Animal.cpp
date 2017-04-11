#include <iostream>
#include <random>
#include "Animal.h"
#include "World.h"

// default animal collision logic
void Animal::Collision(Organism* other)
{
	if (type == other->GetType())
	{
		// TODO have sex
	}
	else
	{
		// stronger or attacker wins. Looser organism is still in memory, but no longer in world
		if (strength >= other->GetStrength())
		{
			std::cout << type << " zjadl " << other->GetType() << std::endl;
			other->fromWorld.RemoveOrganism(other);
		}
		else
		{
			std::cout << other->GetType() << " zjadl " << type << std::endl;
			fromWorld.RemoveOrganism(this);
		}
	}
}

// default animal movement
void Animal::Action()
{
	bool cont = true;
	while (cont)
	{
		switch (rand() % 4)
		{
		case 0:
			if (coordinates.x < fromWorld.GetMaxXY().x)
			{
				coordinates.x++;
				cont = false;
			}
			break;
		case 1:
			if (coordinates.x > 0)
			{
				coordinates.x--;
				cont = false;
			}
			break;
		case 2:
			if (coordinates.y < fromWorld.GetMaxXY().y)
			{
				coordinates.y++;
				cont = false;
			}
			break;
		case 3:
			if (coordinates.y > 0)
			{
				coordinates.y--;
				cont = false;
			}
			break;
		}
	}

	Organism* collider = fromWorld.isFieldOccupied(coordinates);
	if (collider != nullptr && collider != this)
		Collision(collider);
}