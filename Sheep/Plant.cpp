#include "Plant.h"
#include "World.h"

void Plant::Action()
{
	// 1/4 chance to do anything
	if (rand() % 4 > 2)
	{
		for each (coordinates_t pos in RandomizeFields())
		{
			if (!this->GetWorld().isFieldOccupied(pos))
			{
				this->GetWorld().AddOrganism(this->Clone(this->GetWorld(), pos));
				return; // end turn after successful sew
			}
		}
	}
}