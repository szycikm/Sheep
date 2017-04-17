#pragma once
#include <vector>
#include "Coordinates.h"

#define ADULT_AGE 5

class World;
class Organism
{
private:
	char type;
	int age;
	int strength, initiative;
	World& fromWorld;
protected:
	coordinates_t position;
	std::vector<coordinates_t> RandomizeFields();
public:
	Organism(World& fromWorld, coordinates_t position);
	virtual Organism* Clone(World& fromWorld, coordinates_t position) = 0;
	virtual bool TryResistAttack(Organism* attacker) = 0;
	virtual void Action() = 0;
	coordinates_t GetXY() const;
	char Draw() const;
	char GetType() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	World& GetWorld() const;
	void SetType(int type);
	void SetStrength(int initiative);
	void SetInitiative(int strength);
	virtual void IncrementAge();
};