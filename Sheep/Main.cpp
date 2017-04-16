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
#include "Output.h"
#include "Names.h"

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
	std::vector<char*> randomNames = {
		"Jake", "Winston", "Harry", "Larry", "Lenny", "Johnny", "Spencer", "Fred", "Joey", "Steve",
		"Mascara", "Mooriela", "Vicky", "Christa", "Vicky", "Daisy", "Elizabeth", "Dolores", "Esmeralda", "Matilda"
	};
	Names names(speciesNames, randomNames);

	World world(10, 10);
	auto turns = 0;
	std::vector<Organism*> organisms;
	organisms.push_back(&WinstonTheWolf(world, coordinates_t{ 1, 4 }));
	organisms.push_back(&Sheep(world, coordinates_t{ 2, 0 }));
	organisms.push_back(&Sheep(world, coordinates_t{ 9, 0}));
	organisms.push_back(&Sheep(world, coordinates_t{ 4, 7}));
	organisms.push_back(&WinstonTheWolf(world, coordinates_t{ 5, 2 }));
	organisms.push_back(&WinstonTheWolf(world, coordinates_t{ 4, 2}));
	organisms.push_back(&Sheep(world, coordinates_t{ 0, 3}));
	organisms.push_back(&WinstonTheWolf(world, coordinates_t{ 4, 6}));

	for each (Organism* org in organisms)
	{
		world.AddOrganism(org);
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