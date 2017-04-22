#pragma once
#include "Animal.h"

class Fox : public Animal
{
private:
	void Init();
public:
	Fox(World& fromWorld, coordinates_t position);
	Fox(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};