#pragma once
#include <memory>
#include <vector>
#include "Coordinates.h"

class Organism;

class World
{
private:
	std::vector<std::shared_ptr<Organism>> organisms;
	coordinates_t maxxy;
	static bool SortOrganisms(const std::shared_ptr<Organism> first, const std::shared_ptr<Organism> second);
public:
	World(size_t maxx, size_t maxy);
	coordinates_t GetMaxXY() const;
	std::shared_ptr<Organism> isFieldOccupied(coordinates_t questioner);
	std::shared_ptr<Organism> GetOrganismByPosition(coordinates_t position);
	void DoTurn();
	bool AddOrganism(std::shared_ptr<Organism>);
	void RemoveOrganism(std::shared_ptr<Organism>);
	size_t GetOrganismCount() const;
	void PrintWorld() const;
	~World();
};