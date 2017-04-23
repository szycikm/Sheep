#pragma once

#include "Plant.h"

class Guarana : public Plant
{
private:
	void Init();
public:
	Guarana(World& fromWorld, int x, int y, int age, int strength, int initiative);
	Guarana(World& fromWorld, int x, int y);
	Guarana(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(std::shared_ptr<Organism> attacker) override;
};