#include "Transport.h"
#include <iostream>
using namespace std;

Transport::Transport()
{
	Model = "empty";
	Speed = NULL;
	Weight = NULL;
	FuelType = "empty";
	TankCapacity = NULL;
	PassengerCapacity = NULL;
	CarryingCapacity = NULL;
}

void Transport::Input()
{
	cout << "Enter model: ";
	cin >> Model;
	cout << "Enter speed: ";
	cin >> Speed;
	cout << "Enter weight: ";
	cin >> Weight;
	cout << "Enter fuel type: ";
	cin >> FuelType;
	cout << "Enter tank capacity: ";
	cin >> TankCapacity;
	cout << "Enter passenger capacity: ";
	cin >> PassengerCapacity;
	cout << "Enter carrying capacity: ";
	cin >> CarryingCapacity;
}
void Transport::Print() const
{
	cout << "Model: " << Model << endl;
	cout << "Speed: " << Speed << endl;
	cout << "Weight: " << Weight << endl;
	cout << "Fuel type: " << FuelType << endl;
	cout << "Tank capacity: " << TankCapacity << endl;
	cout << "Passenger capacity: " << PassengerCapacity << endl;
	cout << "Carrying capacity: " << CarryingCapacity << endl;
}

string Transport::GetFuelType() const
{
	return FuelType;
}

void Transport::SetFuelType(const char* u_FuelType)
{
	FuelType = u_FuelType;
}
