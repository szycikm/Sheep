#pragma once
#include "Animal.h"

class Sheep : public Animal
{
private:
	void Init();
public:
	Sheep(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name);
	Sheep(World& fromWorld, int x, int y);
	Sheep(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	std::string toString() override;
};