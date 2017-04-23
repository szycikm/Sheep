#include <iostream>
#include <conio.h>
#include <random>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>

#include "Output.h"
#include "Names.h"
#include "World.h"
#include "Organism.h"

#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Human.h"

#include "Grass.h"
#include "Dairy.h"
#include "Guarana.h"
#include "WolfBerries.h"
#include "SosnowskisBorsch.h"

#define ANIMAL_START_MAX 5
#define PLANT_START_MAX 2
#define WORLD_X 15
#define WORLD_Y 10

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

	// add random amount of every organism (and 1 human)

	world.AddOrganism(std::make_shared<Human>(Human(world))); // HUMAN AFTER ALL (actually add him first)

	for (int i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(std::make_shared<Wolf>(Wolf(world)));

	for (int i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(std::make_shared<Sheep>(Sheep(world)));

	for (int i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(std::make_shared<Fox>(Fox(world)));

	for (int i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(std::make_shared<Turtle>(Turtle(world)));

	for (int i = 0; i < rand() % ANIMAL_START_MAX; i++)
		world.AddOrganism(std::make_shared<Antelope>(Antelope(world)));

	for (int i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(std::make_shared<Grass>(Grass(world)));

	for (int i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(std::make_shared<Dairy>(Dairy(world)));

	for (int i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(std::make_shared<Guarana>(Guarana(world)));

	for (int i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(std::make_shared<WolfBerries>(WolfBerries(world)));

	for (int i = 0; i < rand() % PLANT_START_MAX; i++)
		world.AddOrganism(std::make_shared<SosnowskisBorsch>(SosnowskisBorsch(world)));
	
	char c;
	while (true)
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
		if (c == KEY_SAVE)
		{
			std::ofstream save;
			save.open("..\\save.dat");
			save << turns << std::endl << world.toString();
			save.close();
			Output::log << "Saved world state" << std::endl;
		}
		else if (c == KEY_LOAD)
		{
			std::ifstream save("..\\save.dat");
			std::string line;
			getline(save, line);
			turns = std::stoi(line);
			getline(save, line);
			size_t worldx, worldy;
			worldx = std::stoi(line);
			getline(save, line);
			worldy = std::stoi(line);
			world = World(worldx, worldy); // also calls ~World();
			while (true)
			{
				getline(save, line, ';');
				if (line == "") break; // no next organism
				char type = line[0]; // first thing in line is organism type
				getline(save, line, ';');
				int age = std::stoi(line);
				getline(save, line, ';');
				int strength = std::stoi(line);
				getline(save, line, ';');
				int initiative = std::stoi(line);
				getline(save, line, ';');
				int posx = std::stoi(line);
				getline(save, line, ';');
				int posy = std::stoi(line);
				std::string name = "";
				int countdown = 0;
				getline(save, line, ';');
				name = line;
				getline(save, line); // read until endline
				if(line != "") countdown = std::stoi(line);
				switch (type)
				{
				case 'W':
					world.AddOrganism(std::make_shared<Wolf>(Wolf(world, posx, posy, age, strength, initiative, name)));
					break;
				case 'S':
					world.AddOrganism(std::make_shared<Sheep>(Sheep(world, posx, posy, age, strength, initiative, name)));
					break;
				case 'F':
					world.AddOrganism(std::make_shared<Fox>(Fox(world, posx, posy, age, strength, initiative, name)));
					break;
				case 'T':
					world.AddOrganism(std::make_shared<Turtle>(Turtle(world, posx, posy, age, strength, initiative, name)));
					break;
				case 'A':
					world.AddOrganism(std::make_shared<Antelope>(Antelope(world, posx, posy, age, strength, initiative, name)));
					break;
				case 'H':
					world.AddOrganism(std::make_shared<Human>(Human(world, posx, posy, age, strength, initiative, name, countdown)));
					break;
				case 'G':
					world.AddOrganism(std::make_shared<Grass>(Grass(world, posx, posy, age, strength, initiative)));
					break;
				case 'D':
					world.AddOrganism(std::make_shared<Dairy>(Dairy(world, posx, posy, age, strength, initiative)));
					break;
				case 'U':
					world.AddOrganism(std::make_shared<Guarana>(Guarana(world, posx, posy, age, strength, initiative)));
					break;
				case 'B':
					world.AddOrganism(std::make_shared<WolfBerries>(WolfBerries(world, posx, posy, age, strength, initiative)));
					break;
				case 'C':
					world.AddOrganism(std::make_shared<SosnowskisBorsch>(SosnowskisBorsch(world, posx, posy, age, strength, initiative)));
					break;
				}
			}
			save.close();
			Output::log << "Loaded world state" << std::endl;
		}
		else if (c == KEY_QUIT)
		{
			break;
		}
		else
		{
			world.DoTurn();
			turns++;
		}
	}

	// terminate logger window
	system("taskkill /im SheepLogger.exe");
	return 0;
}