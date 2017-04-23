#include "Plant.h"
#include "World.h"
#include "Names.h"

void Plant::Action()
{
	// 1/4 chance to do anything
	if (rand() % 4 > 2)
	{
		for each (coordinates_t pos in RandomizeFields())
		{
			if (!this->fromWorld.GetOrganismByPosition(pos))
			{
				this->fromWorld.AddOrganism(this->Clone(this->fromWorld, pos));
				return; // end turn after successful sew
			}
		}
	}
}

std::string Plant::Introduce() const
{
	return std::string(Names::GetSpeciesName(this->type));
}

std::string Plant::toString()
{
	return Organism::toString() + ";;";
}