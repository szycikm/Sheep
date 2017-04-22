#pragma once
#include <memory>
#include "Organism.h"

class Animal : public Organism, public std::enable_shared_from_this<Animal>
{
private:
	const char* name;
	void Init();
	virtual bool Collision(std::shared_ptr<Organism> other);
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