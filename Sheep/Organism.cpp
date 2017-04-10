#include "Organism.h"

Organism::Organism(World& fromWorld, size_t x, size_t y): fromWorld(fromWorld), x(x), y(y)
{
	age = 0;
}

char Organism::Draw()
{
	return type;
}

size_t Organism::GetX() const
{
	return x;
}

size_t Organism::GetY() const
{
	return y;
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
