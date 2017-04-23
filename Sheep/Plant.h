#pragma once
#include <memory>
#include "Organism.h"

class Plant : public Organism
{
public:
	using Organism::Organism;
	virtual void Action() override;
	std::string Introduce() const override;
	std::string toString() override;
};