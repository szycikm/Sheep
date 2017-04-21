#include "Sheep.h"

void Sheep::Init()
{
	this->type = 'S';
	this->strength = 4;
	this->initiative = 4;
}

Sheep::Sheep(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Sheep::Sheep(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

Sheep* Sheep::Clone(World& fromWorld, coordinates_t position)
{
	return new Sheep(fromWorld, position);
}