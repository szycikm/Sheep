#pragma once
#include "Animal.h"

class Wolf : public Animal
{
private:
	void Init();
public:
	Wolf(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name);
	Wolf(World& fromWorld, int x, int y);
	Wolf(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	std::string toString() override;
};