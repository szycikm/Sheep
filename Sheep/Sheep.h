#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World& fromWorld, coordinates_t position);
	Sheep* Clone(World& fromWorld, coordinates_t position) override;
};