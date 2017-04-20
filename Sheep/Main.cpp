#include <iostream>
#include <conio.h>
#include <random>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include <windows.h>
#include "Output.h"
#include "Names.h"
#include "World.h"
#include "Organism.h"
#include "WinstonTheWolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"
#include "Grass.h"
#include "Dairy.h"

#define WORLD_X 15
#define WORLD_Y 10
#define SPECIES_START_MAX 8

int main()
{
	srand(time(NULL));

	// initialize log file
	Output output("..\\sheep.log");

	// start logger window
	system("start ..\\Debug\\SheepLogger");

	std::map<char, char*> speciesNames;
	speciesNames['W'] = "Wolf";
	speciesNames['S'] = "Sheep";
	speciesNames['F'] = "Fox";
	speciesNames['T'] = "Turtle";
	speciesNames['A'] = "Antelope";
	speciesNames['H'] = "Human";
	speciesNames['G'] = "Grass";
	speciesNames['D'] = "Dairy";
	speciesNames['U'] = "Guarana";
	speciesNames['B'] = "Wolf Berries";
	speciesNames['C'] = "Sosnowski's Borsch";
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
	int antelopecnt = rand() % SPECIES_START_MAX;
	int grasscnt = rand() % SPECIES_START_MAX;
	int dairycnt = rand() % SPECIES_START_MAX;

	WinstonTheWolf wolf(world, coordinates_t{ 0, 0 });
	Sheep sheep(world, coordinates_t{ 0, 0 });
	Fox fox(world, coordinates_t{ 0, 0 });
	Turtle turtle(world, coordinates_t{ 0, 0 });
	Antelope antelope(world, coordinates_t{ 0, 0 });
	Human human(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }); // HUMAN AFTER ALL
	world.AddOrganism(&human);
	Grass grass(world, coordinates_t{ 0, 0 });
	Dairy dairy(world, coordinates_t{ 0, 0 });

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

		if (antelopecnt > i)
			world.AddOrganism(antelope.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

		if (grasscnt > i)
			world.AddOrganism(grass.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

		if (dairycnt > i)
			world.AddOrganism(dairy.Clone(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));
	}
	
	char c = '0';
	while (c != KEY_QUIT)
	{
		system("CLS");

		Output::GoToXY(0, CONSOLE_HEIGHT - 8);
		std::cout << "Programowanie Obiektowe projekt 1: Owca" << std::endl;
		std::cout << "Autor: Marcin Szycik 165116" << std::endl;
		std::cout << "arrows = move human" << std::endl << "x = human special ability" << std::endl << "s/l = save/load state" << std::endl << "q = quit" << std::endl;
		Output::log << "========== Turn: " << turns << " ========== " << std::endl << "Population: " << world.GetOrganismCount() << std::endl;
		std::cout << "Turn: " << turns << std::endl << "Population: " << world.GetOrganismCount() << std::endl;

		world.PrintWorld();

		c = _getch();
		switch (c)
		{
		case KEY_SAVE:
			// TODO save state
			break;
		case KEY_LOAD:
			// TODO load state
			break;
		default:
			world.DoTurn();
			turns++;
			break;
		}
	}

	// terminate logger window
	system("taskkill /im SheepLogger.exe");
	return 0;
}