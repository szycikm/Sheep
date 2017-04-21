#pragma once

#include "Plant.h"

class Grass : public Plant
{
private:
	void Init();
public:
	Grass(World& fromWorld, coordinates_t position);
	Grass(World& fromWorld);
	Grass* Clone(World& fromWorld, coordinates_t position) override;
};