#pragma once

#include "Plant.h"

class Dairy : public Plant
{
private:
	void Init();
public:
	Dairy(World& fromWorld, int x, int y, int age, int strength, int initiative);
	Dairy(World& fromWorld, int x, int y);
	Dairy(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};