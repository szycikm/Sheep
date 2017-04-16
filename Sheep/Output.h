#pragma once
#include <fstream>

#define CONSOLE_HEIGHT 30

class Output
{
public:
	static std::ofstream log;
	Output(std::string filename);
	static void GoToXY(short x, short y);
	~Output();
};