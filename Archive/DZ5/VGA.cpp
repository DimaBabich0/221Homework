#include "VGA.h"
#include <iostream>
using namespace std;

void VGA::deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void VGA::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}

VGA::VGA()
{
	this->model = nullptr;
	this->price = NULL;
	this->memory = NULL;
}
VGA::VGA(char* userModel, double userPrice, unsigned int userMemory)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->price = userPrice;
	this->memory = userMemory;
}
VGA::~VGA()
{
	delete[]this->model;
}

void VGA::input()
{
	char buff[30];

	deleteNullPtr(this->model);

	cout << "Enter model: ";
	cin >> buff;
	this->model = new char[strlen(buff) + 1];
	strcpy_s(this->model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> this->price;

	cout << "Enter memory: ";
	cin >> this->memory;
}
void VGA::print()
{
	cout << "Model: ";
	coutVariable(model);

	cout << "Price: " << price << endl;
	cout << "Memory: " << memory << endl;
}

char* VGA::getModel()
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
double VGA::getPrice()
{
	return this->price;
}
double VGA::getMemory()
{
	return this->memory;
}

void VGA::setModel(const char* value)
{
	deleteNullPtr(this->model);
	this->model = new char[strlen(value) + 1];
	strcpy_s(this->model, strlen(value) + 1, value);
}
void VGA::setPrice(double value)
{
	this->price = value;
}
void VGA::setMemory(unsigned int value)
{
	this->memory = value;
}