#pragma once
#include "Animal.h"

class Sheep : public Animal
{
private:
	void Init();
public:
	Sheep(World& fromWorld, coordinates_t position);
	Sheep(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};