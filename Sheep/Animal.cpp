#include <iostream>
#include <random>
#include <string>
#include "Animal.h"
#include "Output.h"
#include "World.h"
#include "Names.h"

// default animal collision logic. Returns: if animal should be moved or not
bool Animal::Collision(Organism* other)
{
	if (other == nullptr)
	{
		// nothing stands on this field -> just move there
		return true;
	}
	else if (type == other->GetType())
	{
		// animal of the same type stands on this field -> just have sex and don't move there

		Animal* that = dynamic_cast<Animal*>(other);

		// check all four directions
		coordinates_t newPosition[] = {
			coordinates_t { position.x + 1, position.y },
			coordinates_t { position.x - 1, position.y },
			coordinates_t { position.x, position.y + 1 },
			coordinates_t { position.x, position.y - 1 },
		};

		for (size_t i = 0; i < 4; i++)
		{
			Animal* child = dynamic_cast<Animal*>(Clone(fromWorld, newPosition[i]));
			if (fromWorld.AddOrganism(child))
			{
				Output::log << "D'awww. " << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " and " << Names::GetSpeciesName(that->GetType()) << " " << that->GetName() << " are having a baby!"  << "And it's name is " << child->GetName() << std::endl;
				return false;
			}
		}

		// no place for new animal
		Output::log << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " and " << Names::GetSpeciesName(that->GetType()) << " " << that->GetName() << " wanted to have a baby, but there was no place for it" << std::endl;
		return false;
	}
	else
	{
		// stronger (or attacker) wins and takes looser's field
		std::string otherName = dynamic_cast<Animal*>(other) != nullptr ? (dynamic_cast<Animal*>(other))->GetName() : "";
		if (otherName != "") otherName = " " + otherName;
		if (strength >= other->GetStrength())
		{
			Output::log << "Yeah! " << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " ate " << Names::GetSpeciesName(other->GetType()) << otherName << "!" << std::endl;
			other->fromWorld.RemoveOrganism(other);
			return true;
		}
		else
		{
			Output::log << "Oh no! " << Names::GetSpeciesName(other->GetType()) << otherName << " ate " << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << "!" << std::endl;
			fromWorld.RemoveOrganism(this);
			return false;
		}
	}
}

// default animal movement
void Animal::Action()
{
	auto nextPosition = RandomizeNextField(position);
	auto collider = fromWorld.isFieldOccupied(nextPosition);
	if (Collision(collider))
	{
		position = nextPosition;
		Output::log << Names::GetSpeciesName(type) << " " << GetName() << " moved to (" << GetXY().x  << "," << GetXY().y << ")" << std::endl;
	}
}

const char* Animal::GetName()
{
	return name;
}

void Animal::IncrementAge()
{
	Organism::IncrementAge();
	if (age == ADULT_AGE)
	{
		Output::log << Names::GetSpeciesName(type) << " " << GetName() << " is all grown up now!" << std::endl;
	}
}