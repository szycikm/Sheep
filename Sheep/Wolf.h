#pragma once
#include "Animal.h"

class Wolf : public Animal
{
private:
	void Init();
public:
	Wolf(World& fromWorld, coordinates_t position);
	Wolf(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};