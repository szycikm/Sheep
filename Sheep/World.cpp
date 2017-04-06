#include "World.h"

World::World(size_t w, size_t h) : w(w), h(h) {}

void World::DoTurn()
{
	// TODO calculate organism turn order based on initiative and simulate movements/fights/sex
	// TODO increase age of all organisms
}

void World::PushOrganism(Organism &o)
{
	organisms.push_front(o);
}

World::~World()
{
	organisms.clear();
}

std::ostream & operator<<(std::ostream &stream, World &world)
{
	for (std::list<Organism>::iterator iterator = world.organisms.begin(); iterator != world.organisms.end(); ++iterator)
	{
		std::cout << iterator->Draw();
	}
	return stream;
}