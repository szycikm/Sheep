#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

int main()
{
	std::ifstream file("..\\sheep.log");
	std::string line;
	while (true)
	{
		while (getline(file, line))
			std::cout << line << std::endl;

		file.clear();

		Sleep(100);
	}
	file.close();
    return 0;
}