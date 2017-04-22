#pragma once

#include "Animal.h"

class Antelope : public Animal
{
private:
	void Init();
public:
	Antelope(World& fromWorld, coordinates_t position);
	Antelope(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
	bool TryResistAttack(std::shared_ptr<Organism> attacker) override;
};