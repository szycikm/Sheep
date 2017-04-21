#pragma once

#include "Plant.h"

class Guarana : public Plant
{
private:
	void Init();
public:
	Guarana(World& fromWorld, coordinates_t position);
	Guarana(World& fromWorld);
	Guarana* Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(Organism* attacker) override;
};