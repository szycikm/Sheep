#include <iostream>
#include <algorithm>
#include "Output.h"
#include "Animal.h"
#include "World.h"

bool SortList(const Organism* first, const Organism* second)
{
	if (first->GetInitiative() == second->GetInitiative())
		return first->GetAge() > second->GetAge();
	else
		return first->GetInitiative() > second->GetInitiative();
}

World::World(size_t maxx, size_t maxy)
{
	maxxy.x = maxx;
	maxxy.y = maxy;
}

coordinates_t World::GetMaxXY()
{
	return maxxy;
}

Organism* World::isFieldOccupied(coordinates_t questioner)
{
	for each (Organism* org in organisms)
	{
		if (org != nullptr)
		{
			if (org->GetXY().x == questioner.x && org->GetXY().y == questioner.y)
				return org;
		}
	}
	return nullptr;
}

void World::DoTurn()
{
	std::sort(organisms.begin(), organisms.end(), SortList);
	for each (Organism* org in organisms)
	{
		if (org != nullptr)
		{
			std::cout << "akcja " << org->GetType() << " | (" << org->GetXY().x << "," << org->GetXY().y << ") | sila=" << org->GetStrength() << " | wiek=" << org->GetAge() << " | inicjatywa=" << org->GetInitiative() << std::endl; // TODO remove this debug nfo
			org->Action();
			org->IncrementAge();
		}
	}
}

void World::AddOrganism(Organism *o)
{
	// TODO add collision support while adding new organisms
	if (o->GetXY().x > maxxy.x || o->GetXY().y > maxxy.y) return; // organism out of this world -> don't add it
	organisms.push_back(o);// add to organism list
}

void World::RemoveOrganism(Organism* o)
{
	auto it = std::find(organisms.begin(), organisms.end(), o);
	if (it != organisms.end())
		organisms.at(it - organisms.begin()) = nullptr;
		//organisms.erase(it);
}

size_t World::GetOrganismCount()
{
	return organisms.size();
}

void World::PrintWorld()
{
	// remove organisms that were killed in previous turn (they are now nullptrs)
	for (size_t i = 0; i < GetOrganismCount(); i++)
	{
		if (organisms[i] == nullptr)
		{
			organisms.erase(organisms.begin() + i);
			i--; // because we just deleted i element
		}
	}

	// draw vertical thing for style points
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		Output::GoToXY(GRID_LEFT_MARGIN - 1, i);
		std::cout << "|";
	}

	for each (Organism* org in organisms)
	{
		Output::GoToXY(org->GetXY().x + GRID_LEFT_MARGIN, org->GetXY().y);
		std::cout << org->Draw();
	}
}

World::~World()
{
	organisms.clear();
}