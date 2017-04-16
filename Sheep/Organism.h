#pragma once
#include "Coordinates.h"

#define ADULT_AGE 5

class World;
class Organism
{
protected:
	coordinates_t position;
	int age;
	char type;
	int strength, initiative;
	coordinates_t RandomizeNextField(coordinates_t oldPosition);
public:
	World& fromWorld;
	Organism(World& fromWorld, coordinates_t position);
	virtual Organism* Clone(World& fromWorld, coordinates_t position) = 0;
	virtual void Action() = 0;
	char GetType() const;
	char Draw() const;
	coordinates_t GetXY() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	virtual void IncrementAge();
};