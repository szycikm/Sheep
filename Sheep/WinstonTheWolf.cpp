#include "WinstonTheWolf.h"

WinstonTheWolf::WinstonTheWolf(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->SetType('W');
	this->SetStrength(9);
	this->SetInitiative(5);
}

WinstonTheWolf* WinstonTheWolf::Clone(World& fromWorld, coordinates_t position)
{
	return new WinstonTheWolf(fromWorld, position);
}