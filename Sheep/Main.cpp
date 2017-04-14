#include <iostream>
#include <conio.h>
#include <random>
#include <string>
#include <time.h>
#include "World.h"
#include "Organism.h"
#include "WinstonTheWolf.h"
#include "Sheep.h"
#include "Output.h"

int main()
{
	srand(time(NULL));
	Output::InitializeLog("sheep.log");
	World world(5,5);
	auto turns = 0;
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
	
	char c = 'n';
	size_t t = 1;
	while (c != 'q')
	{
		if (c == 't')
		{
			Output::GoToXY(0, CONSOLE_HEIGHT - 1);
			std::cout << "Input turns count: ";
			scanf_s("%i", &t);
		}
		
		for (size_t i = 0; i < t; i++)
		{
			system("CLS");
			Output::GoToXY(0, CONSOLE_HEIGHT - 8);
			std::cout << "Programowanie Obiektowe projekt 1: Owca" << std::endl;
			std::cout << "Autor: Marcin Szycik 165116" << std::endl;
			std::cout << "n = new turn" << std::endl << "q = quit" << std::endl << "t = input turns count" << std::endl;
			std::cout << "Turn " << turns << std::endl;
			std::cout << "Alive organisms: " << world.GetOrganismCount();

			Output::AppendLog("Turn " + std::to_string(turns));
			Output::AppendLog("Alive organisms: " + std::to_string(world.GetOrganismCount()));

			Output::GoToXY(0, 0);
			world.DoTurn();
			turns++;
			world.PrintWorld();
		}
		t = 1;
		c = _getch();
	}
	return 0;
}