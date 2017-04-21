#include <string>
#include "SosnowskisBorsch.h"
#include "Animal.h"
#include "Output.h"

void SosnowskisBorsch::Init()
{
	this->type = 'C';
	this->strength = 10;
	this->initiative = 0;
}

SosnowskisBorsch::SosnowskisBorsch(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->Init();
}

SosnowskisBorsch::SosnowskisBorsch(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

SosnowskisBorsch* SosnowskisBorsch::Clone(World & fromWorld, coordinates_t position)
{
	return new SosnowskisBorsch(fromWorld, position);
}

void SosnowskisBorsch::Action()
{
	for each (coordinates_t target in this->RandomizeFields())
	{
		Organism* victim = this->GetWorld().GetOrganismByPosition(target);
		// only kill animals that get too close
		if (victim != nullptr && dynamic_cast<Animal*>(victim) != nullptr)
		{
			Output::log << victim->Introduce() << " got too close to " << this->Introduce() << std::endl;
			this->GetWorld().RemoveOrganism(victim);
		}
	}
	Plant::Action(); // after it kills everything, it tries to sew, like any normal plant
}