#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	using Organism::Organism;
	virtual void Action() override;
};