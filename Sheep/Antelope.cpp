#include <string>
#include "Antelope.h"
#include "World.h"
#include "Output.h"

Antelope::Antelope(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->SetType('A');
	this->SetStrength(4);
	this->SetInitiative(4);
}

Antelope* Antelope::Clone(World& fromWorld, coordinates_t position)
{
	return new Antelope(fromWorld, position);
}

void Antelope::Action()
{
	Move(RandomizeField());
	Move(RandomizeField());
}

bool Antelope::TryResistAttack(Organism* attacker)
{
	Animal* that = dynamic_cast<Animal*>(attacker);
	for each (auto newPosition in RandomizeFields())
	{
		if (!this->GetWorld().isFieldOccupied(newPosition))
		{
			Move(newPosition);
			Output::log << this->Introduce() << " got away from " << that->Introduce() << std::endl;
			return true;
		}
	}
	Output::log << this->Introduce() << " tried to get away, but you can't hide from " << that->Introduce() << std::endl;
	return false;
}