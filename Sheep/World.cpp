#include <iostream>
#include <algorithm>
#include <string>
#include "World.h"
#include "Output.h"
#include "Animal.h"
#include "Human.h"

bool World::SortOrganisms(const std::shared_ptr<Organism> first, const std::shared_ptr<Organism> second)
{
	if (!first || !second) return false; // if either organism is nullptr we should exit
	if (first->GetInitiative() == second->GetInitiative())
		return first->GetAge() > second->GetAge();
	else
		return first->GetInitiative() > second->GetInitiative();
}

World::World(size_t maxx, size_t maxy)
{
	this->maxxy.x = maxx;
	this->maxxy.y = maxy;
}

coordinates_t World::GetMaxXY() const
{
	return this->maxxy;
}

std::shared_ptr<Organism> World::GetOrganismByPosition(coordinates_t position)
{
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		if (this->organisms[i]->isAlive() && this->organisms[i]->GetXY().x == position.x && this->organisms[i]->GetXY().y == position.y)
			return this->organisms[i];
	}
	return nullptr;
}

void World::DoTurn()
{
	std::sort(this->organisms.begin(), this->organisms.end(), SortOrganisms);
	size_t cnt = this->GetOrganismCount(); // organism count can get bigger so it's important to keep it in separate variable
	for (size_t i = 0; i < cnt; i++)
	{
		if (this->organisms[i]->isAlive())
			this->organisms[i]->Action();

		if (this->organisms[i]->isAlive()) // again, because this organism might have just stepped into stronger animal
			this->organisms[i]->IncrementAge();
	}

	// clean dead organisms
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		if (!this->organisms[i]->isAlive())
		{
			this->organisms[i] = nullptr; // set ptr to null (it might delete object that's no longer needed)
			this->organisms.erase(this->organisms.begin() + i); // also erase pointer from vector
			i--; // because we just deleted i element
		}
	}
}

bool World::AddOrganism(std::shared_ptr<Organism> o)
{
	if (o->GetXY().x >= this->maxxy.x || o->GetXY().y >= this->maxxy.y || o->GetXY().x < 0 || o->GetXY().y < 0)
	{
		//Output::log << "Organism coordinates outside of this world" << std::endl;
		return false;
	}
	else if (this->GetOrganismByPosition(o->GetXY()))
	{
		//Output::log << "Field already occupied" << std::endl;
		return false;
	}
	else
	{
		this->organisms.push_back(o);
		return true;
	}
}

size_t World::GetOrganismCount() const
{
	return this->organisms.size();
}

void World::PrintWorld() const
{
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		Output::GoToXY(this->organisms[i]->GetXY().x, this->organisms[i]->GetXY().y);
		std::cout << this->organisms[i]->Draw();
	}
}

std::string World::toString()
{
	std::string everything = std::to_string(this->maxxy.x) + "\n" + std::to_string(this->maxxy.y) + "\n";
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		everything += this->organisms[i]->toString() + "\n";
	}
	return everything;
}

World::~World()
{
	// unset every pointer to delete objects
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		this->organisms[i] = nullptr;
	}
	this->organisms.clear();
	Output::log << "destruktor œwiatów" << std::endl;
}