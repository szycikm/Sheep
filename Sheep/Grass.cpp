#include "Grass.h"

void Grass::Init()
{
	this->type = 'G';
	this->strength = 0;
	this->initiative = 0;
}

Grass::Grass(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->Init();
}

Grass::Grass(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

Grass* Grass::Clone(World& fromWorld, coordinates_t position)
{
	return new Grass(fromWorld, position);
}