#include "CPU.h"
#include <iostream>
using namespace std;

void CPU::deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void CPU::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}


CPU::CPU()
{
	this->model = nullptr;
	this->price = NULL;
	this->power = NULL;
}
CPU::CPU(char* userModel, double userPrice, double userPower)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->price = userPrice;
	this->power = userPower;
}
CPU::~CPU()
{
	delete[]this->model;
}

void CPU::input()
{
	char buff[30];

	deleteNullPtr(this->model);

	cout << "Enter model: ";
	cin >> buff;
	this->model = new char[strlen(buff) + 1];
	strcpy_s(this->model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> this->price;

	cout << "Enter power: ";
	cin >> this->power;
}
void CPU::print()
{
	cout << "Model: ";
	coutVariable(model);

	cout << "Price: " << price << endl;
	cout << "Power: " << power << endl;
}

char* CPU::getModel()
{
	if (this->model == nullptr)
	{
		this->model = new char[strlen("empty") + 1];
		strcpy_s(this->model, strlen("empty") + 1, "empty");
		return this->model;
	}
	else
		return this->model;
}
double CPU::getPrice()
{
	return this->price;
}
double CPU::getPower()
{
	return this->power;
}

void CPU::setModel(const char* value)
{
	deleteNullPtr(this->model);
	this->model = new char[strlen(value) + 1];
	strcpy_s(this->model, strlen(value) + 1, value);
}
void CPU::setPrice(double value)
{
	this->price = value;
}
void CPU::setPower(double value)
{
	this->power = value;
}