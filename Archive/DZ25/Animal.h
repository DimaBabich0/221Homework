#pragma once
#include <iostream>
using namespace std;

struct IFly
{
	virtual void Fly() = 0;
};
struct ISwim
{
	virtual void Swim() = 0;
};
class Animal
{
protected:
	string name;
	int kg;
public:
	Animal() : name("empty"), kg(NULL) {}
	Animal(string userName, int userKg) : name(userName), kg(userKg) {}
	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Kg: " << kg << endl;
	}
	virtual void Continent() = 0;
	virtual void Eat() = 0;
	virtual void Sound() = 0;
};

class Penguin : public Animal, public ISwim
{
	string continent;
public:
	Penguin() : Animal(), continent("empty") {}
	Penguin(string userName, int userKg, string userContinent) : Animal(userName, userKg), continent(userContinent) {}

	virtual void Continent()
	{
		cout << "Continent: " << continent << endl;
	}
	virtual void Eat()
	{
		cout << name << " eats fish" << endl;
	}
	virtual void Sound()
	{
		cout << name << " makes sounds" << endl;
	}
	virtual void Swim()
	{
		cout << name << " can swim" << endl;
	}
};
class Parrot : public Animal, public IFly
{
	string continent;
public:
	Parrot() : Animal()
	{
		continent = "empty";
	}
	Parrot(string userName, int userKg, string userContinent) : Animal(userName, userKg), continent(userContinent) {}
	
	virtual void Continent()
	{
		cout << name << " lives in " << continent << endl;
	}
	virtual void Eat()
	{
		cout << name << " eats bread\n";
	}
	virtual void Sound()
	{
		cout << name << " makes sounds\n";
	}
	virtual void Fly()
	{
		cout << name << " can fly" << endl;
	}
};
class Airplane : public IFly
{
private:
	string model;
public:
	Airplane() : model("empty") {}
	Airplane(string userModel) : model(userModel) {}

	virtual void Print()
	{
		cout << "Model: " << model << endl;
	}
	virtual void Fly()
	{
		cout << model << " can fly" << endl;
	}
};