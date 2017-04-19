#pragma once
#include <fstream>

#define CONSOLE_HEIGHT 29

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_SPECIAL 'x'
#define KEY_QUIT 'q'
#define KEY_LOAD 'l'
#define KEY_SAVE 's'

class Output
{
public:
	static std::ofstream log;
	Output(std::string filename);
	static void GoToXY(short x, short y);
	~Output();
};