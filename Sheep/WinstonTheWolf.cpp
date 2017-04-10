#include "WinstonTheWolf.h"

WinstonTheWolf::WinstonTheWolf(World& fromWorld, size_t x, size_t y) : Animal(fromWorld, x, y)
{
	type = 'W';
	strength = 9;
	initiative = 5;
}