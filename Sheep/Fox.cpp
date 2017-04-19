#include "Fox.h"
#include "Names.h"
#include "World.h"
#include "Output.h"

Fox::Fox(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->type = 'F';
	this->strength = 3;
	this->initiative = 7;
}

Fox* Fox::Clone(World& fromWorld, coordinates_t position)
{
	return new Fox(fromWorld, position);
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

	Output::log << Names::GetSpeciesName(this->type) << " " << this->name<< " decided to stay in place" << std::endl;
}