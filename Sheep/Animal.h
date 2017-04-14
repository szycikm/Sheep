#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	virtual bool Collision(Organism* other);
protected:
	coordinates_t RandomizeNextField(coordinates_t oldCoordinates);
public:
	using Organism::Organism;
	virtual void Action() override;
};