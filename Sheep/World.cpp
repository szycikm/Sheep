#include <iostream>
#include <algorithm>
#include "Console.h"
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
		std::cout << "akcja " << org->GetType() << " | (" << org->GetXY().x << "," << org->GetXY().y << ") | sila=" << org->GetStrength() << " | wiek=" << org->GetAge() << " | inicjatywa=" << org->GetInitiative() << std::endl;
		org->Action();
		org->IncrementAge();
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

void World::PrintWorld()
{
	for (size_t i = 0; i < organisms.size(); i++)
	{
		if (organisms[i] == nullptr)
			organisms.erase(organisms.begin() + i);
	}
	std::cout << "Zywe organizmy: " << organisms.size() << std::endl;
	for each (Organism* org in organisms)
	{
		Console::GoToXY(org->GetXY().x + GRID_LEFT_MARGIN, org->GetXY().y);
		std::cout << org->GetType();
	}
}

World::~World()
{
	organisms.clear();
}