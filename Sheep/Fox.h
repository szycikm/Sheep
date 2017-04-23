#pragma once
#include "Animal.h"

class Fox : public Animal
{
private:
	void Init();
public:
	Fox(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name);
	Fox(World& fromWorld, int x, int y);
	Fox(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
	std::string toString() override;
};