#pragma once

#include "Plant.h"

class Dairy : public Plant
{
private:
	void Init();
public:
	Dairy(World& fromWorld, coordinates_t position);
	Dairy(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};