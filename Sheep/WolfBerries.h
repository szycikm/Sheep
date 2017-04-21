#pragma once

#include "Plant.h"

class WolfBerries : public Plant
{
public:
	WolfBerries(World& fromWorld, coordinates_t position);
	WolfBerries* Clone(World& fromWorld, coordinates_t position) override;
};