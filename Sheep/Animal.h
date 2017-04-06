#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	int initiative;
public:
	using Organism::Organism;
	void Collision(Organism &other);
	void Action() override;
};