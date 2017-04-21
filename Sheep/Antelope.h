#pragma once

#include "Animal.h"

class Antelope : public Animal
{
private:
	void Init();
public:
	Antelope(World& fromWorld, coordinates_t position);
	Antelope(World& fromWorld);
	Antelope* Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
	bool TryResistAttack(Organism* attacker) override;
};