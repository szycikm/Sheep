#include "World.h"

bool SortList(const Organism* first, const Organism* second)
{
	if (first->GetInitiative() == second->GetInitiative())
		return first->GetAge() > second->GetAge();
	else
		return first->GetInitiative() > second->GetInitiative();
}

void World::DoTurn()
{
	std::sort(organisms.begin(), organisms.end(), SortList);
	for each (Organism* org in organisms)
	{
		std::cout << "akcja " << org->Draw() << " | (" << org->GetX() << "," << org->GetY() << ") | sila=" << org->GetStrength() << " | wiek=" << org->GetAge() << " | inicjatywa=" << org->GetInitiative() << std::endl;
		org->Action();
		org->IncrementAge();
	}
}

void World::AddOrganism(Organism &o)
{
	// TODO add collision support while adding new organisms
	organisms.push_back(&o);// add to organism list
}

void World::PrintWorld()
{
	std::cout << "Zywe organizmy: " << organisms.size() << std::endl;
	for each (Organism* org in organisms)
	{
		Console::GoToXY(org->GetX() + GRID_LEFT_MARGIN, org->GetY());
		std::cout << org->Draw();
	}
}

World::~World()
{
	organisms.clear();
}