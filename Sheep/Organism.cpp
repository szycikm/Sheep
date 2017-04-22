#include <algorithm>
#include <string>
#include "Organism.h"
#include "World.h"
#include "Names.h"
#include "Output.h"

void Organism::Init(coordinates_t position)
{
	this->position = position;
	this->age = 0;
	this->alive = true;
}

// randomizes 2 to 4 new coordinates respecting the world limits
std::vector<coordinates_t> Organism::RandomizeFields()
{
	std::vector<coordinates_t> randomized;

	if (this->position.x + 1 < fromWorld.GetMaxXY().x)
		randomized.push_back(coordinates_t{ this->position.x + 1, this->position.y });
	if (this->position.x > 0)
		randomized.push_back(coordinates_t{ this->position.x - 1, this->position.y });
	if (this->position.y + 1 < fromWorld.GetMaxXY().y)
		randomized.push_back(coordinates_t{ this->position.x, this->position.y + 1 });
	if (this->position.y > 0)
		randomized.push_back(coordinates_t{ this->position.x, this->position.y - 1 });

	std::random_shuffle(randomized.begin(), randomized.end());
	return randomized;
}

Organism::Organism(World& fromWorld, coordinates_t position) : fromWorld(fromWorld)
{
	this->Init(position);
}

Organism::Organism(World& fromWorld) : fromWorld(fromWorld)
{
	this->Init(coordinates_t{ rand() % fromWorld.GetMaxXY().x, rand() % fromWorld.GetMaxXY().y });
}

bool Organism::TryResistAttack(std::shared_ptr<Organism> attacker)
{
	return false; // standard organisms can't resist attack
}

char Organism::GetType() const
{
	return this->type;
}

char Organism::Draw() const
{
	// if organism is below 5 turns draw it small. Just for fun.
	return this->age < ADULT_AGE ? Names::GetLowercaseSymbol(this->type) : this->type;
}

coordinates_t Organism::GetXY() const
{
	return this->position;
}

int Organism::GetAge() const
{
	return this->age;
}

int Organism::GetStrength() const
{
	return this->strength;
}

int Organism::GetInitiative() const
{
	return this->initiative;
}

void Organism::IncrementAge()
{
	this->age++;
}

void Organism::SetStrength(int strength)
{
	this->strength = strength;
}

bool Organism::isAlive() const
{
	return this->alive;
}

// fly, fly, PIZZA DIE!
void Organism::Die()
{
	this->alive = false; // mark organism as dead
}

std::string Organism::toString()
{
	return this->type + ";" + std::to_string(this->age) + ";" + std::to_string(this->alive) + ";" + std::to_string(this->strength) + ";" + std::to_string(this->initiative) + ";" + std::to_string(this->position.x) + ";" + std::to_string(this->position.y);
}