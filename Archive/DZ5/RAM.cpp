#include "RAM.h"
#include "main.h"
#include <iostream>
using namespace std;

RAM::RAM()
{
	this->model = nullptr;
	this->price = NULL;
	this->storage = NULL;
}
RAM::RAM(const char* userModel, double userPrice, unsigned int userStorage)
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
RAM::RAM(const RAM& point)
{
	this->model = new char[strlen(point.model) + 1];
	strcpy_s(this->model, strlen(point.model) + 1, point.model);

	this->price = point.price;
	this->storage = point.storage;
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
	coutVariable(this->model);

	cout << "Price: " << this->price << endl;
	cout << "Storage: " << this->storage << endl;
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