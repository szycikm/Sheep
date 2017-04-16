#include <iostream>
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

		// check all four directions in random order
		for each (coordinates_t coords in RandomizeFields())
		{
			Animal* child = dynamic_cast<Animal*>(Clone(fromWorld, coords));
			if (fromWorld.AddOrganism(child))
			{
				Output::log << "D'awww. " << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " and " << Names::GetSpeciesName(that->GetType()) << " " << that->GetName() << " are having a baby! And it's name is " << child->GetName() << std::endl;
				return false;
			}
		}

		// no place for new animal
		Output::log << Names::GetSpeciesName(this->GetType()) << " " << this->GetName() << " and " << Names::GetSpeciesName(that->GetType()) << " " << that->GetName() << " wanted to have a baby, but the world decided otherwise" << std::endl;
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

// detect collisions and move to the next position if necessary
void Animal::Move(coordinates_t nextPosition)
{
	auto collider = fromWorld.isFieldOccupied(nextPosition);
	if (Collision(collider))
	{
		position = nextPosition;
		Output::log << Names::GetSpeciesName(type) << " " << GetName() << " moved to (" << GetXY().x << "," << GetXY().y << ")" << std::endl;
	}
}

// default animal movement
void Animal::Action()
{
	auto nextPosition = RandomizeFields()[0]; // just grab first random generated value
	Move(nextPosition);
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