#pragma once
#include <vector>
#include <memory>
#include "Coordinates.h"

#define ADULT_AGE 5

class World;
class Organism : public std::enable_shared_from_this<Organism>
{
private:
	int age;
	void Init(coordinates_t position);
	bool alive;
protected:
	char type;
	World& fromWorld;
	int strength, initiative;
	coordinates_t position;
	std::vector<coordinates_t> RandomizeFields();
public:
	Organism(World& fromWorld, coordinates_t position);
	Organism(World& fromWorld);
	virtual std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) = 0;
	virtual bool TryResistAttack(std::shared_ptr<Organism> attacker);
	virtual void Action() = 0;
	coordinates_t GetXY() const;
	char Draw() const;
	char GetType() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	virtual void IncrementAge();
	void SetStrength(int strength);
	virtual std::string Introduce() const = 0;
	bool isAlive() const;
	void Die();
};