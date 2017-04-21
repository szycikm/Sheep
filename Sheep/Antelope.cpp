#include <string>
#include "Antelope.h"
#include "World.h"
#include "Output.h"

void Antelope::Init()
{
	this->type = 'A';
	this->strength = 4;
	this->initiative = 4;
}

Antelope::Antelope(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Antelope::Antelope(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

Antelope* Antelope::Clone(World& fromWorld, coordinates_t position)
{
	return new Antelope(fromWorld, position);
}

void Antelope::Action()
{
	this->Move(this->RandomizeField());
	this->Move(this->RandomizeField());
}

bool Antelope::TryResistAttack(Organism* attacker)
{
	for each (auto newPosition in this->RandomizeFields())
	{
		if (!this->GetWorld().isFieldOccupied(newPosition))
		{
			this->Move(newPosition);
			Output::log << this->Introduce() << " got away from " << attacker->Introduce() << std::endl;
			return true;
		}
	}
	Output::log << this->Introduce() << " tried to get away, but you can't hide from " << attacker->Introduce() << std::endl;
	return false;
}