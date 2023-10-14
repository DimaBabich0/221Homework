#pragma once
#include <iostream>
using namespace std;
class Herbivore
{
protected:
	bool life = true;
	double weight;
public:
	void EatGrass()
	{
		weight += 10;
	}

	void Print()
	{
		cout << "Life: " << life << endl;
		cout << "Weight: " << weight << endl;
	}
	bool GetLife()
	{
		return life;
	}
	double GetWeight()
	{
		return weight;
	}
	void SetLife(bool u_Life)
	{
		life = u_Life;
	}
	void SetWeight(double u_Weight)
	{
		weight = u_Weight;
	}
};

class Wildebeest : public Herbivore
{
public:
	Wildebeest()
	{
		weight = 20;
	}
	Wildebeest(double userWeight)
	{
		weight = userWeight;
	}
};
class Bison : public Herbivore
{
public:
	Bison() 
	{
		weight = 50;
	}
	Bison(double userWeight) 
	{
		weight = userWeight;
	}
};