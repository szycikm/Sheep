#include <iostream>
#include <conio.h>
#include <random>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <windows.h>
#include "World.h"
#include "Organism.h"
#include "WinstonTheWolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Output.h"
#include "Names.h"

#define WORLD_X 15
#define WORLD_Y 10
#define SPECIES_START_MAX 10

int main()
{
	srand(time(NULL));

	// initialize log file
	Output output("..\\sheep.log");

	// start log window
	system("start ..\\Debug\\SheepLogger");

	std::map<char, char*> speciesNames;
	speciesNames['W'] = "Wolf";
	speciesNames['S'] = "Sheep";
	speciesNames['F'] = "Fox";
	speciesNames['T'] = "Turtle";
	std::vector<char*> randomNames = {
		"Jake", "Winston", "Harry", "Larry", "Lenny", "Johnny", "Spencer", "Fred", "Joey", "Steve", "Bob",
		"Mascara", "Mooriela", "Vicky", "Christina", "Vicky", "Daisy", "Elizabeth", "Dolores", "Esmeralda", "Matilda", "Jenny"
	};
	Names names(speciesNames, randomNames);

	World world(WORLD_X, WORLD_Y);
	auto turns = 0;

	int wolfcnt = rand() % SPECIES_START_MAX;
	int sheepcnt = rand() % SPECIES_START_MAX;
	int foxcnt = rand() % SPECIES_START_MAX;
	int turtlecnt = rand() % SPECIES_START_MAX;

	WinstonTheWolf wolf(world, coordinates_t{ 0, 0 });
	Sheep sheep(world, coordinates_t{ 0, 0 });
	Fox fox(world, coordinates_t{ 0, 0 });
	Turtle turtle(world, coordinates_t{ 0, 0 });

	for (size_t i = 0; i < SPECIES_START_MAX; i++)
	{
		if (wolfcnt > i)
			world.AddOrganism(wolf.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

		if (sheepcnt > i)
			world.AddOrganism(sheep.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

		if (foxcnt > i)
			world.AddOrganism(fox.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

		if (turtlecnt > i)
			world.AddOrganism(turtle.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));
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
			Output::log << "========== Turn: " << turns << " ========== " << std::endl;
			std::cout << "Turn: " << turns << std::endl;

			world.DoTurn();
			turns++;

			Output::GoToXY(0, CONSOLE_HEIGHT - 2);
			Output::log << "Population: " << world.GetOrganismCount() << std::endl;
			std::cout << "Population: " << world.GetOrganismCount() << std::endl;

			world.PrintWorld();
		}
		t = 1;
		c = _getch();
	}

	// terminate logger window
	system("taskkill /im SheepLogger.exe");
	return 0;
}