#pragma once
#include "Animal.h"

class WinstonTheWolf : public Animal
{
private:
	void Init();
public:
	WinstonTheWolf(World& fromWorld, coordinates_t position);
	WinstonTheWolf(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};