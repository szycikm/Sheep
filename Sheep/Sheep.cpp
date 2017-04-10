#include "World.h"
#include "Organism.h"
#include "Animal.h"

int main()
{
	World world(5, 5);
	int turns = 0;
	Organism *organisms[] = {
		&Animal('a', 3, 1, 2),
		&Animal('b', 6, 5, 2),
		&Animal('c', 1, 3, 0),
		&Animal('d', 3, 0, 1),
		&Animal('e', 6, 4, 2)
	};

	for (size_t i = 0; i < 5; i++)
	{
		if (!world.AddOrganism(*organisms[i]))
			std::cout << "Blad przy dodawaniu organizmu: wspolrzedne poza swiatem" << std::endl;
	}
	
	char c = '\n';
	while (c != 'q')
	{
		c = getchar();
		system("CLS");
		std::cout << "Programowanie Obiektowe projekt 1: Owca. Autor: Marcin Szycik 165116" << std::endl;
		std::cout << "Tura " << turns << ". enter = nastepna tura; q = zakoncz symulacje" << std::endl;
		world.DoTurn();
		turns++;
		std::cout << world;
	}
	return 0;
}