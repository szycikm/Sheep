# Sheep
First project for Objective Programming class, second semester on Gdańsk University of Technology
# Download
https://github.com/szycikm/Sheep/releases/latest
# The goal
Implement a simple turn-based simulation of world. There are animals and plants (and also a cyber-sheep) that have their unique properties, like strength and special abilities. They live on a rectangular grid, only one organism can occupy a single field. Every turn all animals make a move in random direction, if two of them end up in a single field they fight and one eats another. Plants have a small chance to sow the same kind of plant in one of the surrounding fields. Eating plants gives animals special abilities. Etc, etc, there will be more of it. The point is to learn objective programming
# Observations
Once the world and organism logic was implemented, adding new animal or plant was very easy - it was just the matter of setting properties (like strength and initiative) and overriding some methods for specyfic behaviour. Most of the boring logic (movement, fights, sex, ...) was already in Organism/Animal/Plant.
