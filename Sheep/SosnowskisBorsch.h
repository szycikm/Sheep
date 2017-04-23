#pragma once

#include "Plant.h"
#include "World.h"

class SosnowskisBorsch : public Plant
{
private:
	void Init();
public:
	SosnowskisBorsch(World& fromWorld, int x, int y, int age, int strength, int initiative);
	SosnowskisBorsch(World& fromWorld, int x, int y);
	SosnowskisBorsch(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};