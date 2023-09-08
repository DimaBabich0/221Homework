#include "Car.h"
#include <iostream>
using namespace std;

void Car::deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void Car::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}

Car::Car()
{
	this->model = nullptr;
	this->color = nullptr;
	this->year = NULL;
	this->price = NULL;
}
Car::Car(const char* userModel, const char* userColor, int userYear, double userPrice)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->color = new char[strlen(userColor) + 1];
	strcpy_s(this->color, strlen(userColor) + 1, userColor);

	this->year = userYear;
	this->price = userPrice;
}
Car::~Car()
{
	delete[]this->model;
	delete[]this->color;
}

void Car::input()
{
	char buff[30];

	deleteNullPtr(this->model);
	deleteNullPtr(this->color);

	cout << "Enter model: ";
	cin >> buff;
	this->model = new char[strlen(buff) + 1];
	strcpy_s(this->model, strlen(buff) + 1, buff);

	cout << "Enter color: ";
	cin >> buff;
	this->color = new char[strlen(buff) + 1];
	strcpy_s(this->color, strlen(buff) + 1, buff);

	cout << "Enter year: ";
	cin >> this->year;
	
	cout << "Enter price: ";
	cin >> this->price;
}
void Car::print()
{
	cout << "Model: ";
	coutVariable(model);

	cout << "Color: ";
	coutVariable(color);

	cout << "Year: " << year << endl;
	cout << "Price: " << price << endl;
}

char* Car::getModel()
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
char* Car::getColor()
{
	if (this->color == nullptr)
	{
		this->color = new char[strlen("empty") + 1];
		strcpy_s(this->color, strlen("empty") + 1, "empty");
		return this->color;
	}
	else
		return this->color;
}
int Car::getYear()
{
	return this->year;
}
double Car::getPrice()
{
	return this->price;
}

void Car::setModel(const char* value)
{
	deleteNullPtr(this->model);
	this->model = new char[strlen(value) + 1];
	strcpy_s(this->model, strlen(value) + 1, value);
}
void Car::setColor(const char* value)
{
	deleteNullPtr(this->color);
	this->color = new char[strlen(value) + 1];
	strcpy_s(this->color, strlen(value) + 1, value);
}
void Car::setYear(int value)
{
	this->year = value;
}
void Car::setPrice(double value)
{
	this->price = value;
}