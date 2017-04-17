#pragma once

#include "Animal.h"

class Antelope : public Animal
{
public:
	Antelope(World& fromWorld, coordinates_t position);
	Antelope* Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
	bool TryResistAttack(Organism* attacker) override;
};