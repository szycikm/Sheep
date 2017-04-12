#include "Log.h"
#include <string>

std::ofstream Log::file;

void Log::Initialize(std::string filename)
{
	file.open(filename);
}

void Log::Append(std::string line)
{
	file << line << std::endl;
}

void Log::Close()
{
	file.close();
}