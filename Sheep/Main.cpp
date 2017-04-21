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
#include "Guarana.h"
#include "WolfBerries.h"

#define WORLD_X 15
#define WORLD_Y 10
#define ANIMAL_START_MAX 8
#define PLANT_START_MAX 3

int main()
{
	srand(time(NULL));

	// initialize log file
	Output output("..\\sheep.log");

	// start logger window
	system("start ..\\Debug\\SheepLogger");

	// set global names
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

	// init world
	World world(WORLD_X, WORLD_Y);
	auto turns = 0;

	world.AddOrganism(new Human(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y })); // HUMAN AFTER ALL (actually add him first)


	for (size_t i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(new WinstonTheWolf(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(new Sheep(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(new Fox(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(new Turtle(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(new Antelope(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(new Grass(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(new Dairy(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(new Guarana(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));

	for (size_t i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(new WolfBerries(world, coordinates_t{ rand() % WORLD_X, rand() % WORLD_Y }));
	
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