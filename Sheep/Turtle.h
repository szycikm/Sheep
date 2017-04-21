#pragma once

#include "Animal.h"

#define TURTLE_RESIST_STRENGTH 5

class Turtle : public Animal
{
private:
	void Init();
public:
	Turtle(World& fromWorld, coordinates_t position);
	Turtle(World& fromWorld);
	Turtle* Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(Organism* attacker) override;
	void Action() override;
};