#include <string>
#include <windows.h>
#include "Output.h"

std::ofstream Output::file;

void Output::GoToXY(size_t x, size_t y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Output::InitializeLog(std::string filename)
{
	file.open(filename);
}

void Output::AppendLog(std::string line)
{
	file << line << std::endl;
}

Output::~Output()
{
	file.close();
}