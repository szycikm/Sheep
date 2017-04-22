#include "WinstonTheWolf.h"

void WinstonTheWolf::Init()
{
	this->type = 'W';
	this->strength = 9;
	this->initiative = 5;
}

WinstonTheWolf::WinstonTheWolf(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

WinstonTheWolf::WinstonTheWolf(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> WinstonTheWolf::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<WinstonTheWolf>(WinstonTheWolf(fromWorld, position));
}