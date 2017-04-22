#pragma once

#include "Plant.h"

class Grass : public Plant
{
private:
	void Init();
public:
	Grass(World& fromWorld, coordinates_t position);
	Grass(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};