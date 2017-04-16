#include <locale>
#include <random>
#include "Names.h"

std::map<char, char*> Names::speciesNames;
std::vector<char*> Names::names;

Names::Names(std::map<char, char*> speciesNames, std::vector<char*> names)
{
	this->speciesNames = speciesNames;
	this->names = names;
}

const char Names::GetLowercaseSymbol(char type)
{
	return std::tolower(type, std::locale());
}

const char* Names::GetSpeciesName(char type)
{
	return speciesNames.count(type) == 1 ? speciesNames.at(type) : "Undefined";
}

const char* Names::GetRandomName()
{
	return names[rand() % names.size()];
}