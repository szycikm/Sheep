#include <windows.h>
#include "Console.h"

void Console::GoToXY(size_t x, size_t y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}