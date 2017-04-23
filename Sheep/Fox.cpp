#include <string>
#include "Fox.h"
#include "World.h"
#include "Output.h"

void Fox::Init()
{
	this->type = 'F';
	this->strength = 3;
	this->initiative = 7;
}

Fox::Fox(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name) : Animal(fromWorld, x, y)
{
	this->type = 'F';
	this->strength = strength;
	this->initiative = initiative;
	this->name = name;
	this->age = age;
}

Fox::Fox(World& fromWorld, int x, int y) : Animal(fromWorld, x, y)
{
	this->Init();
}

Fox::Fox(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Fox::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Fox>(Fox(fromWorld, position.x, position.y));
}

void Fox::Action()
{
	// sneaky fox checks all directions and decides where to move (if at all)
	for each (coordinates_t coords in RandomizeFields())
	{
		auto collider = this->fromWorld.GetOrganismByPosition(coords);
		// move to empty field, or attack weaker organism. sneaky
		if (!collider || (collider && collider->GetStrength() <= this->GetStrength()))
		{
			this->Move(coords);
			return;
		}
	}

	Output::log << this->Introduce() << " decided to stay in place" << std::endl;
}

std::string Fox::toString()
{
	return Animal::toString() + ";";
}