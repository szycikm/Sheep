#include "Sheep.h"
#include "Names.h"

Sheep::Sheep(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	type = 'S';
	strength = 4;
	initiative = 4;
	name = Names::GetRandomName(type);
}

Sheep* Sheep::Clone(World& fromWorld, coordinates_t position)
{
	return new Sheep(fromWorld, position);
}