#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	void Collision(Organism* other) override;
public:
	using Organism::Organism;
	void Action() override;
};