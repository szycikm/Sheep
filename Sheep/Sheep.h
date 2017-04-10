#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World& fromWorld, size_t x, size_t y);
};