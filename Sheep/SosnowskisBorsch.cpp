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

SosnowskisBorsch::SosnowskisBorsch(World & fromWorld, int x, int y, int age, int strength, int initiative) : Plant(fromWorld, x, y)
{
	this->type = 'C';
	this->strength = strength;
	this->initiative = initiative;
	this->age = age;
}

SosnowskisBorsch::SosnowskisBorsch(World& fromWorld, int x, int y) : Plant(fromWorld, x, y)
{
	this->Init();
}

SosnowskisBorsch::SosnowskisBorsch(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> SosnowskisBorsch::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<SosnowskisBorsch>(SosnowskisBorsch(fromWorld, position.x, position.y));
}

void SosnowskisBorsch::Action()
{
	for each (coordinates_t target in this->RandomizeFields())
	{
		auto victim = this->fromWorld.GetOrganismByPosition(target);
		// only kill animals that get too close
		if (victim && std::dynamic_pointer_cast<Animal>(victim) != nullptr)
		{
			Output::log << victim->Introduce() << " got too close to " << this->Introduce() << std::endl;
			victim->Die();
		}
	}
	Plant::Action(); // after it kills everything, it tries to sew, like any normal plant
}