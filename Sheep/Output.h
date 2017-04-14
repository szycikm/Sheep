#pragma once
#include <fstream>

#define GRID_LEFT_MARGIN 50
#define CONSOLE_HEIGHT 30

class Output
{
private:
	static std::ofstream file;
public:
	static void GoToXY(size_t x, size_t y);
	static void InitializeLog(std::string filename);
	static void AppendLog(std::string line);
	~Output();
};