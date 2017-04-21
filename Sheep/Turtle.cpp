#include <string>
#include "Turtle.h"
#include "Output.h"

void Turtle::Init()
{
	this->type = 'T';
	this->strength = 2;
	this->initiative = 1;
}

Turtle::Turtle(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->Init();
}

Turtle::Turtle(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

Turtle* Turtle::Clone(World& fromWorld, coordinates_t position)
{
	return new Turtle(fromWorld, position);
}

bool Turtle::TryResistAttack(Organism* attacker)
{
	return attacker->GetStrength() < TURTLE_RESIST_STRENGTH;
}

void Turtle::Action()
{
	// turtle moves with 25% chance
	if (rand() % 4 <= 0)
		Animal::Action();
	else
		Output::log << this->Introduce() << " decided not to move" << std::endl;
}