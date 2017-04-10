#include "World.h"
#include "Organism.h"
#include "WinstonTheWolf.h"
#include "Sheep.h"

int main()
{
	World world;
	int turns = 0;
	Organism *organisms[] = {
		&WinstonTheWolf(world, 1, 4),
		&Sheep(world, 2, 0),
		&Sheep(world, 0, 3),
		&WinstonTheWolf(world, 4, 2)
	};

	for (size_t i = 0; i < 4; i++)
	{
		world.AddOrganism(*organisms[i]);
	}
	
	char c = '\n';
	while (c != 'q')
	{
		system("CLS");
		std::cout << "Programowanie Obiektowe projekt 1: Owca. Autor: Marcin Szycik 165116" << std::endl;
		std::cout << "Tura " << turns << ". enter = nastepna tura; q = zakoncz symulacje" << std::endl;
		world.DoTurn();
		turns++;
		world.PrintWorld();
		c = getchar();
	}
	return 0;
}