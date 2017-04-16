#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	using Organism::Organism;
	void Collision(Organism &other);
	void Action() override;
	void IncrementAge() override;
};