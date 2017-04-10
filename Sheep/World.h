#pragma once
#include <iostream>
#include <list>
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"

class World
{
private:
	size_t w, h;
	Organism ***organisms;
	std::list<Organism*> sortedOrganisms;
public:
	World(size_t w, size_t h);
	bool SortList(const Organism& first, const Organism& second);
	void DoTurn();
	bool AddOrganism(Organism &o);
	~World();
	friend std::ostream& operator<<(std::ostream& stream, World& world);
};