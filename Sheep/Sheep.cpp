#include "World.h"
#include "Organism.h"
#include "Animal.h"

int main()
{
	World world(10, 10);
	world.PushOrganism(Animal('x', 1, 2));
	world.PushOrganism(Animal('y', 4, 5));
	world.PushOrganism(Animal('z', 2, 4));
	std::cout << world;
	return 0;
}