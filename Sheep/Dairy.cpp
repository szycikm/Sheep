#include "Dairy.h"

Dairy::Dairy(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->type = 'D';
	this->strength = 0;
	this->initiative = 0;
}

Dairy* Dairy::Clone(World & fromWorld, coordinates_t position)
{
	return new Dairy(fromWorld, position);
}

void Dairy::Action()
{
	for (size_t i = 0; i < 3; i++)
	{
		Plant::Action();
	}
}