#include "Sheep.h"

Sheep::Sheep(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->SetType('S');
	this->SetStrength(4);
	this->SetInitiative(4);
}

Sheep* Sheep::Clone(World& fromWorld, coordinates_t position)
{
	return new Sheep(fromWorld, position);
}