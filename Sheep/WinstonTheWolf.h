#pragma once
#include "Animal.h"

class WinstonTheWolf : public Animal
{
public:
	WinstonTheWolf(World& fromWorld, coordinates_t position);
	WinstonTheWolf* Clone(World& fromWorld, coordinates_t position) override;
};