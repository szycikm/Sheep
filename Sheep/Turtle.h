#pragma once

#include "Animal.h"

#define TURTLE_RESIST_STRENGTH 5

class Turtle : public Animal
{
private:
	void Init();
public:
	Turtle(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name);
	Turtle(World& fromWorld, int x, int y);
	Turtle(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	bool TryResistAttack(std::shared_ptr<Organism> attacker) override;
	void Action() override;
	std::string toString() override;
};