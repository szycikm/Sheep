#pragma once

class World;
class Organism
{
private:
	size_t x, y;
	World& fromWorld;
protected:
	int age;
	char type;
	int strength, initiative;
public:
	Organism(World& fromWorld, size_t x, size_t y);
	virtual void Action() = 0;
	virtual void Collision(Organism & other) = 0;
	char Draw();
	size_t GetX() const;
	size_t GetY() const;
	int GetAge() const;
	int GetStrength() const;
	int GetInitiative() const;
	void IncrementAge();
};