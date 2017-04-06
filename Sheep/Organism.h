#pragma once
class Organism
{
private:
	int strength, age, x, y;
	char type;
public:
	Organism(char type, int x, int y);
	virtual void Action() = 0;
	char Draw();
};