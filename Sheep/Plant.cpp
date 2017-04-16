#include "Plant.h"

void Plant::Collision(Organism & other)
{
	// TODO collision ahead
}

void Plant::Action()
{
	// TODO action action action
}

void Plant::IncrementAge()
{
	Organism::IncrementAge();
	if (age == ADULT_AGE)
	{
		// TODO write something nice here
	}
}