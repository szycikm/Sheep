#pragma once
#include <memory>
#include "Organism.h"

class Animal : public Organism
{
private:
	void Init();
	virtual bool Collision(std::shared_ptr<Organism> other);
protected:
	std::string name;
	void Move(coordinates_t nextPosition);
	coordinates_t RandomizeField();
public:
	Animal(World& fromWorld, int x, int y);
	Animal(World& fromWorld);
	virtual void Action() override;
	std::string GetName() const;
	void IncrementAge() override;
	std::string Introduce() const override;
	virtual std::string toString() override;
};