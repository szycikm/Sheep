#pragma once
#include <vector>
#include "Coordinates.h"

#define GRID_LEFT_MARGIN 50

class Organism;

class World
{
private:
	std::vector<Organism*> organisms;
	coordinates_t maxxy;
public:
	World(size_t maxx, size_t maxy);
	coordinates_t GetMaxXY();
	Organism* isFieldOccupied(coordinates_t questioner);
	void DoTurn();
	void AddOrganism(Organism *o);
	void RemoveOrganism(Organism *o);
	void PrintWorld();
	~World();
};