#pragma once

#include "Animal.h"

class Antelope : public Animal
{
private:
	void Init();
public:
	Antelope(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name);
	Antelope(World& fromWorld, int x, int y);
	Antelope(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
	bool TryResistAttack(std::shared_ptr<Organism> attacker) override;
	std::string toString() override;
};