#include "SSD.h"
#include <iostream>
using namespace std;

void SSD::deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void SSD::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}

SSD::SSD()
{
	this->model = nullptr;
	this->price = NULL;
	this->storage = NULL;
}
SSD::SSD(char* userModel, double userPrice, unsigned int userStorage)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->price = userPrice;
	this->storage = userStorage;
}
SSD::~SSD()
{
	delete[]this->model;
}

void SSD::input()
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
void SSD::print()
{
	cout << "Model: ";
	coutVariable(model);

	cout << "Price: " << price << endl;
	cout << "Storage: " << storage << endl;
}

char* SSD::getModel()
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
double SSD::getPrice()
{
	return this->price;
}
double SSD::getStorage()
{
	return this->storage;
}

void SSD::setModel(const char* value)
{
	deleteNullPtr(this->model);
	this->model = new char[strlen(value) + 1];
	strcpy_s(this->model, strlen(value) + 1, value);
}
void SSD::setPrice(double value)
{
	this->price = value;
}
void SSD::setStorage(unsigned int value)
{
	this->storage = value;
}