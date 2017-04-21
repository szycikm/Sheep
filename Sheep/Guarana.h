#pragma once

#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World& fromWorld, coordinates_t position);
	Guarana* Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(Organism* attacker) override;
};