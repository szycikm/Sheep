#include "WolfBerries.h"

void WolfBerries::Init()
{
	this->type = 'B';
	this->strength = 99;
	this->initiative = 0;
}

WolfBerries::WolfBerries(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->Init();
}

WolfBerries::WolfBerries(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> WolfBerries::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<WolfBerries>(WolfBerries(fromWorld, position));
}