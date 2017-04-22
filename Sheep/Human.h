#pragma once

#include "Animal.h"

#define SPECIAL_COUNTDOWN 5
#define SPECIAL_STRENGTH 10

class Human : public Animal
{
private:
	void Init();
	int specialCountdown;
public:
	Human(World& fromWorld, coordinates_t position);
	Human(World& fromWorld);
	std::shared_ptr<Organism> Clone(World& fromWorld, coordinates_t position) override;
	void Action() override;
};