#pragma once
#include <fstream>

class Log
{
private:
	static std::ofstream file;
public:
	static void Initialize(std::string filename);
	static void Append(std::string line);
	static void Close();
};