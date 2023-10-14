#pragma once
#include "Herbivore.h"
#include <iostream>
using namespace std;
class Carnivore
{
protected:
	double power;
public:
	void Eat(Herbivore& object)
	{
		if (object.GetLife() && power > object.GetWeight())
		{
			object.SetLife(false);
			power += 10;
		}
		else
			power -= 10;
	}

	void Print()
	{
		cout << "Power: " << power << endl;
	}
	double GetPower()
	{
		return power;
	}
	void SetPower(double u_Power)
	{
		power = u_Power;
	}
};

class Lion : public Carnivore
{
public:
	Lion()
	{
		power = 40;
	}
	Lion(double userPower)
	{
		power = userPower;
	}
};
class Wolf : public Carnivore
{
public:
	Wolf()
	{
		power = 50;
	}
	Wolf(double userPower)
	{
		power = userPower;
	}
};