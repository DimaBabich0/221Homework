#pragma once
#include "Herbivore.h"
#include "Carnivore.h"
#include <iostream>

class Continent
{
protected:
	Herbivore* HerbivoreAnimal;
	Carnivore* CarnivoreAnimal;
public:
	Continent()
	{
		HerbivoreAnimal = new Herbivore();
		CarnivoreAnimal = new Carnivore();
	}
	Continent(Herbivore* u_HerbivoreAnimal, Carnivore* u_CarnivoreAnimal) : 
		HerbivoreAnimal(u_HerbivoreAnimal), 
		CarnivoreAnimal(u_CarnivoreAnimal) 
	{}
	~Continent()
	{
		delete HerbivoreAnimal;
		delete CarnivoreAnimal;
	}

	Herbivore* GetHerbivoreAnimal()
	{
		return HerbivoreAnimal;
	}
	Carnivore* GetCarnivoreAnimal()
	{
		return CarnivoreAnimal;
	}
};

class Africa : public Continent
{
public:
	Africa()
	{
		HerbivoreAnimal = new Wildebeest();
		CarnivoreAnimal = new Lion();
	}
	Africa(Wildebeest* u_HerbivoreAnimal, Lion* u_CarnivoreAnimal) : Continent(u_HerbivoreAnimal, u_CarnivoreAnimal) {}
};

class NorthAmerica : public Continent
{
public:
	NorthAmerica()
	{
		HerbivoreAnimal = new Bison();
		CarnivoreAnimal = new Wolf();
	}
	NorthAmerica(Bison* u_HerbivoreAnimal, Wolf* u_CarnivoreAnimal) : Continent(u_HerbivoreAnimal, u_CarnivoreAnimal) {}
};