#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include "World.h"
#include "Organism.h"
#include "WinstonTheWolf.h"
#include "Sheep.h"
#include "Io.h"

int main()
{
	srand(time(NULL));
	Io::InitializeLog("sheep.log");
	World world(5,5);
	int turns = 0;
	Organism *organisms[] = {
		&WinstonTheWolf(world, 1, 4),
		&Sheep(world, 2, 0),
		&Sheep(world, 4, 3),
		&WinstonTheWolf(world, 1, 2),
		&Sheep(world, 0, 3),
		&WinstonTheWolf(world, 4, 2)
	};

	for (size_t i = 0; i < 6; i++)
	{
		world.AddOrganism(organisms[i]);
	}
	
	char c = '\n';
	int t = 1;
	while (c != 'q')
	{
		if (c == 'n')
			scanf_s("%i", &t);
		
		for (size_t i = 0; i < t; i++)
		{
			system("CLS");
			std::cout << "Programowanie Obiektowe projekt 1: Owca" << std::endl;
			std::cout << "Autor: Marcin Szycik 165116" << std::endl;
			std::cout << "enter = nastepna tura" << std::endl << "q = zakoncz symulacje" << std::endl << "n = podaj ilosc tur" << std::endl;
			Io::AppendLog("Tura " + std::to_string(turns));
			std::cout << "Tura " << turns << std::endl;
			world.DoTurn();
			turns++;
			world.PrintWorld();
		}
		t = 1;
		c = getchar();
	}
	return 0;
}