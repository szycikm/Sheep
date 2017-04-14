#pragma once
#include "Coordinates.h"

class World;
class Organism
{
protected:
	coordinates_t coordinates;
	int age;
	char type;
	int strength, initiative;
public:
	World& fromWorld;
	Organism(World& fromWorld, size_t x, size_t y);
	virtual void Action() = 0;
	char GetType() const;
	char Draw() const;
	coordinates_t GetXY() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	void IncrementAge();
};