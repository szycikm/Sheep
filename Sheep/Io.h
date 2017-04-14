#pragma once
#include <fstream>

class Io
{
private:
	static std::ofstream file;
public:
	static void GoToXY(size_t x, size_t y);
	static void InitializeLog(std::string filename);
	static void AppendLog(std::string line);
	~Io();
};