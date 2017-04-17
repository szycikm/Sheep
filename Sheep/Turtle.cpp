#include "Turtle.h"
#include "Output.h"
#include "Names.h"

Turtle::Turtle(World& fromWorld, coordinates_t position) : Animal(fromWorld, position)
{
	this->SetType('T');
	this->SetStrength(2);
	this->SetInitiative(1);
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
		Output::log << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " decided not to move" << std::endl;
}