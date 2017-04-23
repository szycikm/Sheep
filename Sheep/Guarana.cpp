#include <string>
#include "Guarana.h"
#include "Output.h"

void Guarana::Init()
{
	this->type = 'U';
	this->strength = 0;
	this->initiative = 0;
}

Guarana::Guarana(World & fromWorld, int x, int y, int age, int strength, int initiative) : Plant(fromWorld, x, y)
{
	this->type = 'U';
	this->strength = strength;
	this->initiative = initiative;
	this->age = age;
}

Guarana::Guarana(World& fromWorld, int x, int y) : Plant(fromWorld, x, y)
{
	this->Init();
}

Guarana::Guarana(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

std::shared_ptr<Organism> Guarana::Clone(World& fromWorld, coordinates_t position)
{
	return std::make_shared<Guarana>(Guarana(fromWorld, position.x, position.y));
}

bool Guarana::TryResistAttack(std::shared_ptr<Organism> attacker)
{
	attacker->SetStrength(attacker->GetStrength() + 3);
	Output::log << attacker->Introduce() << " ate " << this->Introduce() << " and is feeling stronger" << std::endl;
	return false;
}