#pragma once

#include "Animal.h"

#define TURTLE_RESIST_STRENGTH 5

class Turtle : public Animal
{
public:
	Turtle(World& fromWorld, coordinates_t position);
	Turtle* Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(Organism* attacker) override;
	void Action() override;
};