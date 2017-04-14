#include <locale>
#include "Organism.h"

Organism::Organism(World& fromWorld, size_t x, size_t y): fromWorld(fromWorld), age(0)
{
	coordinates.x = x;
	coordinates.y = y;
}

char Organism::GetType() const
{
	return type;
}

char Organism::Draw() const
{
	// if organism is below 5 turns draw him small. Just for fun.
	return age <= 5 ? std::tolower(type, std::locale()) : type;
}

coordinates_t Organism::GetXY() const
{
	return coordinates;
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
