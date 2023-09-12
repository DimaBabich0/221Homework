#include "CPU.h"
#include "main.h"
#include <iostream>
using namespace std;

CPU::CPU()
{
	this->model = nullptr;
	this->price = NULL;
	this->power = NULL;
}
CPU::CPU(const char* userModel, double userPrice, double userPower)
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
CPU::CPU(const CPU& point)
{
	this->model = new char[strlen(point.model) + 1];
	strcpy_s(this->model, strlen(point.model) + 1, point.model);

	this->price = point.price;
	this->power = point.power;
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
	coutVariable(this->model);

	cout << "Price: " << this->price << endl;
	cout << "Power: " << this->power << endl;
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