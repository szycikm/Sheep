#pragma once

#include "Plant.h"

class Grass : public Plant
{
private:
	void Init();
public:
	Grass(World& fromWorld, int x, int y, int age, int strength, int initiative);
	Grass(World& fromWorld, int x, int y);
	Grass(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};