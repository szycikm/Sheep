#pragma once

#include "Plant.h"

class Grass : public Plant
{
public:
	Grass(World& fromWorld, coordinates_t position);
	Grass* Clone(World& fromWorld, coordinates_t position) override;
};