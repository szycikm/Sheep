#include "Sheep.h"

Sheep::Sheep(World& fromWorld, size_t x, size_t y) : Animal(fromWorld, x, y)
{
	type = 'O';
	strength = 4;
	initiative = 4;
}