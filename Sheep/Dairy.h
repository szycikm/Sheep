#pragma once

#include "Plant.h"

class Dairy : public Plant
{
public:
	Dairy(World& fromWorld, coordinates_t position);
	Dairy* Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};