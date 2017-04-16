#include <string>
#include <windows.h>
#include "Output.h"

std::ofstream Output::log;

Output::Output(std::string filename)
{
	log.open(filename);
}

void Output::GoToXY(short x, short y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Output::~Output()
{
	log.close();
}