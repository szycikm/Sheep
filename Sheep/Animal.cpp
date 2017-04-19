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
		// nothing stands on new field -> just move there
		return true;
	}
	else if (this->GetType() == other->GetType())
	{
		// animal of the same type stands on this field -> just have sex and don't move there

		Animal* that = dynamic_cast<Animal*>(other);

		// check all four directions in random order
		for each (coordinates_t coords in RandomizeFields())
		{
			Animal* child = dynamic_cast<Animal*>(this->Clone(this->GetWorld(), coords));
			if (this->GetWorld().AddOrganism(child))
			{
				Output::log << "D'awww. " << this->Introduce() << " and " << that->Introduce() << " are having a baby! And it's name is " << child->GetName() << std::endl;
				return false;
			}
		}

		// no place for new animal
		Output::log << this->Introduce() << " and " << that->Introduce() << " wanted to have a baby, but the world decided otherwise" << std::endl;
		return false;
	}
	else
	{
		// stronger (or attacker) wins and takes looser's field
		Animal* that = dynamic_cast<Animal*>(other);
		std::string otherName = that->GetName();
		if (that->GetName() != "") otherName = " " + otherName;
		
		if (this->GetStrength() >= that->GetStrength())
		{
			if (that->TryResistAttack(this))
			{
				Output::log << that->Introduce() << " resisted " << this->Introduce() << "'s attack!" << std::endl;
				return false; // other organism reflected the attack -> don't move
			}
			else
			{
				Output::log << "Yeah! " << this->Introduce() << " ate " << Names::GetSpeciesName(that->GetType()) << otherName << "!" << std::endl;
				other->GetWorld().RemoveOrganism(other);
				return true;
			}
		}
		else
		{
			Output::log << "Oh no! " << Names::GetSpeciesName(other->GetType()) << otherName << " ate " << this->Introduce() << "!" << std::endl;
			this->GetWorld().RemoveOrganism(this);
			return false;
		}
	}
}

coordinates_t Animal::RandomizeField()
{
	return this->RandomizeFields()[0]; // just grab first random generated value
}

// detect collisions and move to the next position if necessary
void Animal::Move(coordinates_t nextPosition)
{
	auto collider = this->GetWorld().isFieldOccupied(nextPosition);
	if (Collision(collider))
	{
		position = nextPosition;
		Output::log << this->Introduce() << " moved to (" << this->position.x << "," << this->position.y << ")" << std::endl;
	}
}

Animal::Animal(World& fromWorld, coordinates_t position) : Organism(fromWorld, position)
{
	this->name = Names::GetRandomName();
}

// default animal movement
void Animal::Action()
{
	this->Move(this->RandomizeField());
}

bool Animal::TryResistAttack(Organism* attacker)
{
	return false; // normal animals can't resist attack
}

const char* Animal::GetName() const
{
	return this->name;
}

void Animal::IncrementAge()
{
	Organism::IncrementAge();
	if (this->GetAge() == ADULT_AGE)
		Output::log << this->Introduce() << " is all grown up now!" << std::endl;
}

std::string Animal::Introduce() const
{
	return std::string(Names::GetSpeciesName(this->type)) + " " + this->name;
}