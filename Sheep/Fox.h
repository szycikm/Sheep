#pragma once
#include "Animal.h"

class Fox : public Animal
{
public:
	Fox(World& fromWorld, coordinates_t position);
	Fox* Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};