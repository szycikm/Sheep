#pragma once
#include <vector>
#include "Coordinates.h"

#define ADULT_AGE 5

class World;
class Organism
{
private:
	int age;
	World& fromWorld;
	void Init(coordinates_t position);
protected:
	char type;
	int strength, initiative;
	coordinates_t position;
	std::vector<coordinates_t> RandomizeFields();
public:
	Organism(World& fromWorld, coordinates_t position);
	Organism(World& fromWorld);
	virtual Organism* Clone(World& fromWorld, coordinates_t position) = 0;
	virtual bool TryResistAttack(Organism* attacker);
	virtual void Action() = 0;
	coordinates_t GetXY() const;
	char Draw() const;
	char GetType() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	World& GetWorld() const;
	virtual void IncrementAge();
	void SetStrength(int strength);
	virtual std::string Introduce() const = 0;
};