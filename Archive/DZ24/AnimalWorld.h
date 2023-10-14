#pragma once
#include "Continent.h"
class AnimalWorld
{
protected:
	Continent* continent;
public:
	AnimalWorld()
	{
		continent = new Continent();
	}
	AnimalWorld(Continent* userContinent) : continent(userContinent) {}
	~AnimalWorld()
	{
		delete continent;
	}

	void Cycle()
	{
		cout << "\tBefore eat: " << endl;
		cout << "Carnivore animal: " << endl;
		continent->GetCarnivoreAnimal()->Print();
		cout << "Herbivore animal: " << endl;
		continent->GetHerbivoreAnimal()->Print();

		MealsHerbivores();
		NutritionCarnivores();

		cout << "\tAfter eat: " << endl;
		cout << "Carnivore animal: " << endl;
		continent->GetCarnivoreAnimal()->Print();
		cout << "Herbivore animal: " << endl;
		continent->GetHerbivoreAnimal()->Print();
	}
	void MealsHerbivores()
	{
		continent->GetHerbivoreAnimal()->EatGrass();
	}
	void NutritionCarnivores()
	{
		continent->GetCarnivoreAnimal()->Eat(*continent->GetHerbivoreAnimal());
	}
};