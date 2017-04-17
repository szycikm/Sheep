#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	virtual bool Collision(Organism* other);
	const char* name;
	coordinates_t RandomizeField();
protected:
	void Move(coordinates_t nextPosition);
public:
	Animal(World& fromWorld, coordinates_t position);
	virtual void Action() override;
	bool TryResistAttack(Organism* attacker) override;
	const char* GetName();
	void IncrementAge() override;
	std::string Introduce();
};