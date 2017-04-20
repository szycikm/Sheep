#include "Grass.h"

Grass::Grass(World & fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->type = 'G';
	this->strength = 0;
	this->initiative = 0;
}

Grass* Grass::Clone(World& fromWorld, coordinates_t position)
{
	return new Grass(fromWorld, position);
}