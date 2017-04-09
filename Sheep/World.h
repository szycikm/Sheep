#pragma once
#include <iostream>
#include <list>
#include "Organism.h"

class World
{
private:
	size_t w, h;
	Organism ***organisms;
public:
	World(size_t w, size_t h);
	void DoTurn();
	bool AddOrganism(Organism &o);
	~World();
	friend std::ostream& operator<<(std::ostream& stream, World& world);
};