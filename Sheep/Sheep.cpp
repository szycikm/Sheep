#include "Sheep.h"

Sheep::Sheep(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->type = 'S';
	this->strength = 4;
	this->initiative = 4;
}

Sheep* Sheep::Clone(World& fromWorld, coordinates_t position)
{
	return new Sheep(fromWorld, position);
}