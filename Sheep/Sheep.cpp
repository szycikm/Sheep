#include "Sheep.h"

void Sheep::Init()
{
	this->type = 'S';
	this->strength = 4;
	this->initiative = 4;
}

Sheep::Sheep(World & fromWorld, int x, int y, int age, int strength, int initiative, std::string name) : Animal(fromWorld, x, y)
{
	this->type = 'S';
	this->strength = strength;
	this->initiative = initiative;
	this->name = name;
	this->age = age;
}

Sheep::Sheep(World& fromWorld, int x, int y) : Animal(fromWorld, x, y)
{
	this->Init();
}

Sheep::Sheep(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Sheep::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Sheep>(Sheep(fromWorld, position.x, position.y));
}

std::string Sheep::toString()
{
	return Animal::toString() + ";";
}