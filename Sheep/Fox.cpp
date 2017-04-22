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

Fox::Fox(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Fox::Fox(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Fox::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Fox>(Fox(fromWorld, position));
}

void Fox::Action()
{
	// sneaky fox checks all directions and decides where to move (if at all)
	for each (coordinates_t coords in RandomizeFields())
	{
		auto collider = this->GetWorld().isFieldOccupied(coords);
		// move to empty field, or attack weaker organism
		if (collider == nullptr || (collider != nullptr && collider->GetStrength() <= this->GetStrength()))
		{
			this->Move(coords);
			return;
		}
	}

	Output::log << this->Introduce() << " decided to stay in place" << std::endl;
}