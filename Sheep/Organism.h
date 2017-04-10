#pragma once
class Organism
{
private:
	char type;
	int strength, age, x, y;
public:
	Organism(char type, int strength, int x, int y);
	virtual void Action() = 0;
	char Draw();
	int GetX();
	int GetY();
	int GetAge();
	int GetStrength();
	void IncrementAge();
};