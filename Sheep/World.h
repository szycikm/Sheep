#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Console.h"
#include "Animal.h"
#include "Plant.h"

#define GRID_LEFT_MARGIN 70

class Organism;

class World
{
private:
	std::vector<Organism*> organisms;
public:
	void DoTurn();
	void AddOrganism(Organism &o);
	void PrintWorld();
	~World();
};