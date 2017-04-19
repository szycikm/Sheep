#pragma once
#include <vector>
#include "Coordinates.h"

class Organism;

class World
{
private:
	std::vector<Organism*> organisms;
	coordinates_t maxxy;
public:
	World(size_t maxx, size_t maxy);
	coordinates_t GetMaxXY() const;
	Organism* isFieldOccupied(coordinates_t questioner);
	void DoTurn();
	bool AddOrganism(Organism *o);
	void RemoveOrganism(Organism *o);
	size_t GetOrganismCount() const;
	void PrintWorld() const;
	~World();
};