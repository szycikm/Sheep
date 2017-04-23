#include "Grass.h"

void Grass::Init()
{
	this->type = 'G';
	this->strength = 0;
	this->initiative = 0;
}

Grass::Grass(World & fromWorld, int x, int y, int age, int strength, int initiative) : Plant(fromWorld, x, y)
{
	this->type = 'G';
	this->strength = strength;
	this->initiative = initiative;
	this->age = age;
}

Grass::Grass(World& fromWorld, int x, int y) : Plant(fromWorld, x, y)
{
	this->Init();
}

Grass::Grass(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Grass::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Grass>(Grass(fromWorld, position.x, position.y));
}