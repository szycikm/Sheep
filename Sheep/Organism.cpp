#include <algorithm>
#include "Organism.h"
#include "World.h"
#include "Names.h"

// randomizes 2 to 4 new coordinates respecting the world limits
std::vector<coordinates_t> Organism::RandomizeFields()
{
	std::vector<coordinates_t> randomized;

	if (this->position.x + 1 < fromWorld.GetMaxXY().x)
		randomized.push_back(coordinates_t{ this->position.x + 1, this->position.y });
	if (this->position.x > 0)
		randomized.push_back(coordinates_t{ this->position.x - 1, this->position.y });
	if (this->position.y + 1 < fromWorld.GetMaxXY().y)
		randomized.push_back(coordinates_t{ this->position.x, this->position.y + 1 });
	if (this->position.y > 0)
		randomized.push_back(coordinates_t{ this->position.x, this->position.y - 1 });

	std::random_shuffle(randomized.begin(), randomized.end());
	return randomized;
}

Organism::Organism(World& fromWorld, coordinates_t position): fromWorld(fromWorld), position(position)
{
	this->age = 0;
}

bool Organism::TryResistAttack(Organism* attacker)
{
	return false; // standard organisms can't resist attack
}

char Organism::GetType() const
{
	return this->type;
}

char Organism::Draw() const
{
	// if organism is below 5 turns draw it small. Just for fun.
	return this->age < ADULT_AGE ? Names::GetLowercaseSymbol(this->type) : this->type;
}

coordinates_t Organism::GetXY() const
{
	return this->position;
}

int Organism::GetAge() const
{
	return this->age;
}

int Organism::GetStrength() const
{
	return this->strength;
}

int Organism::GetInitiative() const
{
	return this->initiative;
}

World& Organism::GetWorld() const
{
	return this->fromWorld;
}

void Organism::IncrementAge()
{
	this->age++;
}

void Organism::SetStrength(int strength)
{
	this->strength = strength;
}