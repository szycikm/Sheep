#include "Organism.h"

Organism::Organism(char type, int x, int y) : type(type), x(x), y(y)
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