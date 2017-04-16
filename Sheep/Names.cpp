#include <locale>
#include <random>
#include "Names.h"

std::map<char, species_t> Names::species;

Names::Names(std::map<char, species_t> species)
{
	this->species = species;
}

const char Names::GetLowercaseSymbol(char type)
{
	return std::tolower(type, std::locale());
}

const char* Names::GetSpeciesName(char type)
{
	return species.count(type) == 1 ? species.at(type).fullName : "kappa";
}

const char* Names::GetRandomName(char type)
{
	return species.count(type) == 1 ? species.at(type).names[rand() % species.at(type).names.size()] : "kappa";
}