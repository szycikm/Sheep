#include <iostream>
#include <algorithm>
#include "World.h"
#include "Output.h"
#include "Animal.h"
#include "Human.h"

bool World::SortOrganisms(const Organism* first, const Organism* second)
{
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

Organism* World::isFieldOccupied(coordinates_t questioner)
{
	for each (Organism* org in this->organisms)
	{
		if (org != nullptr)
		{
			if (org->GetXY().x == questioner.x && org->GetXY().y == questioner.y)
				return org;
		}
	}
	return nullptr;
}

Organism* World::GetOrganismByPosition(coordinates_t position)
{
	for each (Organism* org in this->organisms)
	{
		if (org != nullptr && org->GetXY().x == position.x && org->GetXY().y == position.y)
			return org;
	}
	return nullptr;
}

void World::DoTurn()
{
	std::sort(this->organisms.begin(), this->organisms.end(), SortOrganisms);
	size_t cnt = this->GetOrganismCount(); // organism count can get bigger so it's important to keep it in separate variable
	for (size_t i = 0; i < cnt; i++)
	{
		if (this->organisms[i] != nullptr)
			this->organisms[i]->Action();

		if (this->organisms[i] != nullptr) // again, because this organism might have just stepped into stronger animal
			this->organisms[i]->IncrementAge();
	}

	// clean dead organisms
	for (size_t i = 0; i < this->GetOrganismCount(); i++)
	{
		if (this->organisms[i] == nullptr)
		{
			this->organisms.erase(this->organisms.begin() + i);
			i--; // because we just deleted i element
		}
	}
}

bool World::AddOrganism(Organism *o)
{
	if (o->GetXY().x >= this->maxxy.x || o->GetXY().y >= this->maxxy.y || o->GetXY().x < 0 || o->GetXY().y < 0)
	{
		//Output::log << "Organism coordinates outside of this world" << std::endl;
		return false;
	}
	else if (this->isFieldOccupied(o->GetXY()))
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

void World::RemoveOrganism(Organism* o)
{
	auto it = std::find(this->organisms.begin(), this->organisms.end(), o);
	if (it != this->organisms.end())
		this->organisms.at(it - this->organisms.begin()) = nullptr;
		//organisms.erase(it); // crashes loop
}

size_t World::GetOrganismCount() const
{
	return this->organisms.size();
}

void World::PrintWorld() const
{
	for each (Organism* org in this->organisms)
	{
		Output::GoToXY(org->GetXY().x, org->GetXY().y);
		std::cout << org->Draw();
	}
}

World::~World()
{
	this->organisms.clear();
}