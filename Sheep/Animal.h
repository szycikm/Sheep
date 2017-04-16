#pragma once
#include "Organism.h"

class Animal : public Organism
{
private:
	virtual bool Collision(Organism* other);
protected:
	const char* name;
	void Move(coordinates_t nextPosition);
public:
	using Organism::Organism;
	virtual void Action() override;
	const char* GetName();
	void IncrementAge() override;
};