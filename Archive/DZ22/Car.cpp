#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() : Transport()
{
	NumWheels = NULL;
}

void Car::Input()
{
	Transport::Input();
	cout << "Enter number of wheels: ";
	cin >> NumWheels;
}
void Car::Print() const
{
	Transport::Print();
	cout << "Number of wheels: " << NumWheels << endl;
}