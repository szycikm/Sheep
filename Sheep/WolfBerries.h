#pragma once

#include "Plant.h"

class WolfBerries : public Plant
{
private:
	void Init();
public:
	WolfBerries(World& fromWorld, coordinates_t position);
	WolfBerries(World& fromWorld);
	WolfBerries* Clone(World& fromWorld, coordinates_t position) override;
};