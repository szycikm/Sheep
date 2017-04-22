#include <string>
#include "Animal.h"
#include "Plant.h"
#include "Output.h"
#include "World.h"
#include "Names.h"

void Animal::Init()
{
	this->name = Names::GetRandomName();
}

// default animal collision logic. Returns: if animal should be moved or not
bool Animal::Collision(std::shared_ptr<Organism> other)
{
	if (!other)
	{
		// nothing stands on new field or there's something dead -> just move there
		return true;
	}
	else if (this->GetType() == other->GetType())
	{
		// animal of the same type stands on this field -> just have sex and don't move there
		
		// check all four directions in random order
		for each (coordinates_t coords in RandomizeFields())
		{
			auto child = std::dynamic_pointer_cast<Animal>(this->Clone(this->fromWorld, coords));
			if (child != nullptr && this->fromWorld.AddOrganism(child))
			{
				Output::log << "D'awww. " << this->Introduce() << " and " << other->Introduce() << " are having a baby! And it's name is " << child->GetName() << std::endl;
				return false;
			}
		}

		// no place for new animal
		Output::log << this->Introduce() << " and " << other->Introduce() << " wanted to have a baby, but the world decided otherwise" << std::endl;
		return false;
	}
	else
	{
		// stronger (or attacker) wins and takes looser's field
		if (this->GetStrength() >= other->GetStrength())
		{
			if (other->TryResistAttack(shared_from_this()))
			{
				Output::log << other->Introduce() << " resisted " << this->Introduce() << "'s attack!" << std::endl;
				return false; // other organism reflected the attack -> don't move
			}
			else
			{
				Output::log << "Yeah! " << this->Introduce() << " ate " << other->Introduce() << "!" << std::endl;
				other->Die();
				return true;
			}
		}
		else
		{
			if(std::dynamic_pointer_cast<Plant>(other) != nullptr)
				Output::log << "Oh no! " << this->Introduce() << " ate " << other->Introduce() << " and died!" << std::endl; // other organism is plant
			else
				Output::log << "Oh no! " << other->Introduce() << " ate " << this->Introduce() << "!" << std::endl; // other organism is animal

			this->Die();
			return false;
		}
	}
}

// detect collisions and move to the next position if necessary
void Animal::Move(coordinates_t nextPosition)
{
	auto collider = this->fromWorld.GetOrganismByPosition(nextPosition);
	if (Collision(collider))
	{
		position = nextPosition;
		Output::log << this->Introduce() << " moved to (" << this->position.x << "," << this->position.y << ")" << std::endl;
	}
}

coordinates_t Animal::RandomizeField()
{
	return this->RandomizeFields()[0]; // just grab first random generated value
}

Animal::Animal(World& fromWorld, coordinates_t position) : Organism(fromWorld, position)
{
	this->Init();
}

Animal::Animal(World& fromWorld) : Organism(fromWorld)
{
	this->Init();
}

// default animal movement
void Animal::Action()
{
	this->Move(this->RandomizeField());
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

std::string Animal::toString()
{
	return Organism::toString() + ";" + this->name;
}