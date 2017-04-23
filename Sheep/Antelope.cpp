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

Antelope::Antelope(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name) : Animal(fromWorld, x, y)
{
	this->type = 'A';
	this->strength = strength;
	this->initiative = initiative;
	this->name = name;
	this->age = age;
}

Antelope::Antelope(World& fromWorld, int x, int y) : Animal(fromWorld, x, y)
{
	this->Init();
}

Antelope::Antelope(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Antelope::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Antelope>(Antelope(fromWorld, position.x, position.y));
}

void Antelope::Action()
{
	for (size_t i = 0; i < 2; i++)
	{
		if(this->isAlive())
			this->Move(this->RandomizeField());
	}
}

bool Antelope::TryResistAttack(std::shared_ptr<Organism> attacker)
{
	for each (auto newPosition in this->RandomizeFields())
	{
		if (!this->fromWorld.GetOrganismByPosition(newPosition))
		{
			this->Move(newPosition);
			Output::log << this->Introduce() << " got away from " << attacker->Introduce() << std::endl;
			return true;
		}
	}
	Output::log << this->Introduce() << " tried to get away, but you can't hide from " << attacker->Introduce() << std::endl;
	return false;
}

std::string Antelope::toString()
{
	return Animal::toString() + ";";
}