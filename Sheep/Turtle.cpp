#include <string>
#include "Turtle.h"
#include "Output.h"

void Turtle::Init()
{
	this->type = 'T';
	this->strength = 2;
	this->initiative = 1;
}

Turtle::Turtle(World & fromWorld, int x, int y, int age, int strength, int initiative, std::string name) : Animal(fromWorld, x, y)
{
	this->type = 'T';
	this->strength = strength;
	this->initiative = initiative;
	this->name = name;
	this->age = age;
}

Turtle::Turtle(World& fromWorld, int x, int y) : Animal(fromWorld, x, y)
{
	this->Init();
}

Turtle::Turtle(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Turtle::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Turtle>(Turtle(fromWorld, position.x, position.y));
}

bool Turtle::TryResistAttack(std::shared_ptr<Organism> attacker)
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

std::string Turtle::toString()
{
	return Animal::toString() + ";";
}