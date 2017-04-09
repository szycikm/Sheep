#include "World.h"
#include "Organism.h"
#include "Animal.h"

int main()
{
	World world(5, 5);
	Organism *organisms[] = {
		&Animal('a', 1, 2),
		&Animal('b', 5, 2),
		&Animal('c', 3, 0),
		&Animal('d', 0, 1),
		&Animal('e', 4, 2)
	};

	for (size_t i = 0; i < 5; i++)
	{
		if (!world.AddOrganism(*organisms[i]))
			std::cout << "Blad przy dodawaniu organizmu: wspolrzedne poza plansza" << std::endl;
	}
	std::cout << "Programowanie Obiektowe projekt 1: Owca. Autor: Marcin Szycik 165116" << std::endl;
	std::cout << world;
	return 0;
}