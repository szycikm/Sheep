#pragma once
#include <map>
#include <vector>

class Names
{
private:
	static std::map<char, char*> speciesNames;
	static std::vector<char*> names;
public:
	Names(std::map<char, char*> speciesNames, std::vector<char*> names);
	static const char GetLowercaseSymbol(char type);
	static const char* GetSpeciesName(char type);
	static const char* GetRandomName();
};