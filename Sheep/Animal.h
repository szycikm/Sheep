#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	const char* name;
	void Init();
	virtual bool Collision(Organism* other);
protected:
	void Move(coordinates_t nextPosition);
	coordinates_t RandomizeField();
public:
	Animal(World& fromWorld, coordinates_t position);
	Animal(World& fromWorld);
	virtual void Action() override;
	const char* GetName() const;
	void IncrementAge() override;
	std::string Introduce() const override;
};