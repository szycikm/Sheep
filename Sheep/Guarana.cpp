#include <string>
#include "Guarana.h"
#include "Output.h"

void Guarana::Init()
{
	this->type = 'U';
	this->strength = 0;
	this->initiative = 0;
}

Guarana::Guarana(World& fromWorld, coordinates_t position) : Plant(fromWorld, position)
{
	this->Init();
}

Guarana::Guarana(World& fromWorld) : Plant(fromWorld)
{
	this->Init();
}

Guarana* Guarana::Clone(World& fromWorld, coordinates_t position)
{
	return new Guarana(fromWorld, position);
}

bool Guarana::TryResistAttack(Organism* attacker)
{
	attacker->SetStrength(attacker->GetStrength() + 3);
	Output::log << attacker->Introduce() << " ate " << this->Introduce() << " and is feeling stronger" << std::endl;
	return false;
}