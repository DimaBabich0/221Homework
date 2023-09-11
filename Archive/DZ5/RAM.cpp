#include "RAM.h"
#include <iostream>
using namespace std;

void RAM::deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void RAM::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}

RAM::RAM()
{
	this->model = nullptr;
	this->price = NULL;
	this->storage = NULL;
}
RAM::RAM(char* userModel, double userPrice, unsigned int userStorage)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->price = userPrice;
	this->storage = userStorage;
}
RAM::~RAM()
{
	delete[]this->model;
}

void RAM::input()
{
	char buff[30];

	deleteNullPtr(this->model);

	cout << "Enter model: ";
	cin >> buff;
	this->model = new char[strlen(buff) + 1];
	strcpy_s(this->model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> this->price;

	cout << "Enter Storage: ";
	cin >> this->storage;
}
void RAM::print()
{
	cout << "Model: ";
	coutVariable(model);

	cout << "Price: " << price << endl;
	cout << "Storage: " << storage << endl;
}

char* RAM::getModel()
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
double RAM::getPrice()
{
	return this->price;
}
double RAM::getStorage()
{
	return this->storage;
}

void RAM::setModel(const char* value)
{
	deleteNullPtr(this->model);
	this->model = new char[strlen(value) + 1];
	strcpy_s(this->model, strlen(value) + 1, value);
}
void RAM::setPrice(double value)
{
	this->price = value;
}
void RAM::setStorage(unsigned int value)
{
	this->storage = value;
}