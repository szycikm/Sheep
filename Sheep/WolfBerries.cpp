#include "WolfBerries.h"

void WolfBerries::Init()
{
	this->type = 'B';
	this->strength = 99;
	this->initiative = 0;
}

WolfBerries::WolfBerries(World & fromWorld, int x, int y, int age, int strength, int initiative) : Plant(fromWorld, x, y)
{
	this->type = 'B';
	this->strength = strength;
	this->initiative = initiative;
	this->age = age;
}

WolfBerries::WolfBerries(World& fromWorld, int x, int y) : Plant(fromWorld, x, y)
{
	this->Init();
}

WolfBerries::WolfBerries(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> WolfBerries::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<WolfBerries>(WolfBerries(fromWorld, position.x, position.y));
}