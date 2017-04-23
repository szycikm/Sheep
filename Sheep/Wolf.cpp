#include "Wolf.h"

void Wolf::Init()
{
	this->type = 'W';
	this->strength = 9;
	this->initiative = 5;
}

Wolf::Wolf(World& fromWorld, int x, int y, int age, int strength, int initiative, std::string name) : Animal(fromWorld, x, y)
{
	this->type = 'W';
	this->strength = strength;
	this->initiative = initiative;
	this->name = name;
	this->age = age;
}

Wolf::Wolf(World& fromWorld, int x, int y) : Animal(fromWorld, x, y)
{
	this->Init();
}

Wolf::Wolf(World& fromWorld) : Animal(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Wolf::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Wolf>(Wolf(fromWorld, position.x, position.y));
}

std::string Wolf::toString()
{
	return Animal::toString() + ";";
}
