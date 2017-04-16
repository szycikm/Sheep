#include "WinstonTheWolf.h"
#include "Names.h"

WinstonTheWolf::WinstonTheWolf(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	type = 'W';
	strength = 9;
	initiative = 5;
	name = Names::GetRandomName(type);
}

WinstonTheWolf* WinstonTheWolf::Clone(World& fromWorld, coordinates_t position)
{
	return new WinstonTheWolf(fromWorld, position);
}