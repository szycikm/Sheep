#include "Wolf.h"

void Wolf::Init()
{
	this->type = 'W';
	this->strength = 9;
	this->initiative = 5;
}

Wolf::Wolf(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Wolf::Wolf(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Wolf::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Wolf>(Wolf(fromWorld, position));
}