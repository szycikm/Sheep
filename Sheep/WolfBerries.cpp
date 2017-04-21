#include <string>
#include "WolfBerries.h"
#include "World.h"
#include "Output.h"

WolfBerries::WolfBerries(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->type = 'B';
	this->strength = 99;
	this->initiative = 0;
}

WolfBerries* WolfBerries::Clone(World& fromWorld, coordinates_t position)
{
	return new WolfBerries(fromWorld, position);
}