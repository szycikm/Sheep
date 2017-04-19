#include "WinstonTheWolf.h"

WinstonTheWolf::WinstonTheWolf(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->type = 'W';
	this->strength = 9;
	this->initiative = 5;
}

WinstonTheWolf* WinstonTheWolf::Clone(World& fromWorld, coordinates_t position)
{
	return new WinstonTheWolf(fromWorld, position);
}