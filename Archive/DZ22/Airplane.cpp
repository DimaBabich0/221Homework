#include "Airplane.h"
#include <iostream>
using namespace std;

Airplane::Airplane() : Transport()
{
	AirplaneType = "empty";
	NumChassis = NULL;
}

void Airplane::Input()
{
	Transport::Input();
	cout << "Enter airplane type: ";
	cin >> AirplaneType;
	cout << "Enter number of chassis: ";
	cin >> NumChassis;
}
void Airplane::Print() const
{
	Transport::Print();
	cout << "Airplane type: " << AirplaneType << endl;
	cout << "Number of chassis: " << NumChassis << endl;
}