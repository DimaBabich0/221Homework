#include "Motorcycle.h"
#include <iostream>
using namespace std;

Motorcycle::Motorcycle() : Transport()
{
	NumWheels = NULL;
}

void Motorcycle::Input()
{
	Transport::Input();
	cout << "Enter number of wheels: ";
	cin >> NumWheels;
}
void Motorcycle::Print() const
{
	Transport::Print();
	cout << "Number of wheels: " << NumWheels << endl;
}