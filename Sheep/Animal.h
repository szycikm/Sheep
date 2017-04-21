#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	virtual bool Collision(Organism* other);
protected:
	void Move(coordinates_t nextPosition);
	const char* name;
	coordinates_t RandomizeField();
public:
	Animal(World& fromWorld, coordinates_t position);
	virtual void Action() override;
	const char* GetName() const;
	void IncrementAge() override;
	std::string Introduce() const override;
};