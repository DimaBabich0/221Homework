#include "SSD.h"
#include "main.h"
#include <iostream>
using namespace std;

SSD::SSD()
{
	this->model = nullptr;
	this->price = NULL;
	this->storage = NULL;
}
SSD::SSD(const char* userModel, double userPrice, unsigned int userStorage)
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
SSD::SSD(const SSD& point)
{
	this->model = new char[strlen(point.model) + 1];
	strcpy_s(this->model, strlen(point.model) + 1, point.model);

	this->price = point.price;
	this->storage = point.storage;
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
	coutVariable(this->model);

	cout << "Price: " << this->price << endl;
	cout << "Storage: " << this->storage << endl;
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