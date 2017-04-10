#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	using Organism::Organism;
	void Collision(Organism& other) override;
	void Action() override;
};