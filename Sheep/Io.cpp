#include <string>
#include <windows.h>
#include "Io.h"

std::ofstream Io::file;

void Io::GoToXY(size_t x, size_t y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Io::InitializeLog(std::string filename)
{
	file.open(filename);
}

void Io::AppendLog(std::string line)
{
	file << line << std::endl;
}

Io::~Io()
{
	file.close();
}