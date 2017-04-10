#include "Organism.h"

Organism::Organism(char type, int strength, int x, int y) : type(type), strength(strength), x(x), y(y)
{
	age = 0;
}

char Organism::Draw()
{
	return type;
}

int Organism::GetX()
{
	return x;
}

int Organism::GetY()
{
	return y;
}

int Organism::GetAge()
{
	return age;
}

int Organism::GetStrength()
{
	return strength;
}

void Organism::IncrementAge()
{
	age++;
}
