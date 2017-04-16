#pragma once
#include <map>
#include <vector>

typedef struct
{
	const char* fullName;
	std::vector<char*> names;
} species_t;

class Names
{
private:
	static std::map<char, species_t> species;
public:
	Names(std::map<char, species_t> species);
	static const char GetLowercaseSymbol(char type);
	static const char* GetSpeciesName(char type);
	static const char* GetRandomName(char type);
};