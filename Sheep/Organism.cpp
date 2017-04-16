#include <algorithm>
#include "Organism.h"
#include "World.h"
#include "Names.h"

// randomizes new coordinates respecting the world limits


std::vector<coordinates_t> Organism::RandomizeFields()
{
	std::vector<coordinates_t> randomized;

	if (position.x + 1 < fromWorld.GetMaxXY().x)
		randomized.push_back(coordinates_t{ position.x + 1, position.y });
	if (position.x > 0)
		randomized.push_back(coordinates_t{ position.x - 1, position.y });
	if (position.y + 1 < fromWorld.GetMaxXY().y)
		randomized.push_back(coordinates_t{ position.x, position.y + 1 });
	if (position.y > 0)
		randomized.push_back(coordinates_t{ position.x, position.y - 1 });

	std::random_shuffle(randomized.begin(), randomized.end());
	return randomized;
}

Organism::Organism(World& fromWorld, coordinates_t position): fromWorld(fromWorld), position(position), age(0){}

char Organism::GetType() const
{
	return type;
}

char Organism::Draw() const
{
	// if organism is below 5 turns draw it small. Just for fun.
	return age < ADULT_AGE ? Names::GetLowercaseSymbol(type) : type;
}

coordinates_t Organism::GetXY() const
{
	return position;
}

int Organism::GetAge() const
{
	return age;
}

int Organism::GetStrength() const
{
	return strength;
}

int Organism::GetInitiative() const
{
	return initiative;
}

void Organism::IncrementAge()
{
	age++;
}