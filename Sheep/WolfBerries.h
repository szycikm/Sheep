#pragma once

#include "Plant.h"

class WolfBerries : public Plant
{
private:
	void Init();
public:
	WolfBerries(World& fromWorld, int x, int y, int age, int strength, int initiative);
	WolfBerries(World& fromWorld, int x, int y);
	WolfBerries(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
};