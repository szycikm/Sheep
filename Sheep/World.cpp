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

bool World::SortList(const Organism& first, const Organism& second)
{
	if (typeid(first) != typeid(Plant))
	{
		// organism is not a plant thus it has initiative
	}
	else
	{
		// organism is a plant
	}
	//return (first.length() < second.length());
	return true; // TODO sort here
}

void World::DoTurn()
{
	sortedOrganisms.sort();
	for each (Organism* org in sortedOrganisms)
	{
		std::cout << "teraz ture robi organizm " << org->Draw() << " na (" << org->GetX() << "," << org->GetY() << ") sila=" << org->strength << ", wiek=" << org->age << std::endl;
		org->Action();
		org->IncrementAge();
	}
}

bool World::AddOrganism(Organism &o)
{
	// TODO add collision support while adding new organisms
	if (o.GetX() >= w || o.GetY() >= h)
		return false; // organism position is outside this world -> don't add it
	
	organisms[o.GetX()][o.GetY()] = &o; // add to grid
	sortedOrganisms.push_front(&o);// add to list for sorting
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
	stream << "Zywe organizmy: " << world.sortedOrganisms.size() << std::endl;
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