#include "World.h"

World::World(size_t w, size_t h) : w(w), h(h)
{
	organisms = new Organism**[w];
	for (size_t x = 0; x < w; x++)
	{
		organisms[x] = new Organism*[h];
		for (size_t y = 0; y < h; y++)
		{
			organisms[x][y] = nullptr;
		}
	}
}

void World::DoTurn()
{
	// TODO calculate organism turn order based on initiative and simulate movements/fights/sex
	// TODO increase age of all organisms
}

bool World::AddOrganism(Organism &o)
{
	// TODO add collision support while adding new organisms
	if (o.GetX() >= w || o.GetY() >= h)
		return false; // organism position is outside this world -> don't add it
	
	organisms[o.GetX()][o.GetY()] = &o;
	return true;
}

World::~World()
{
	for(short x = 0; x < h; x++)
		delete[] organisms[x];

	delete[] organisms;
}

std::ostream & operator<<(std::ostream &stream, World &world)
{
	for (size_t x = 0; x < world.w; x++)
	{
		for (size_t y = 0; y < world.h; y++)
		{
			if (world.organisms[x][y] == nullptr)
			{
				stream << " ";
				continue;
			}
			stream << world.organisms[x][y]->Draw();
		}
		stream << std::endl;
	}
	return stream;
}