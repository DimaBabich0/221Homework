#include "Boat.h"
#include <iostream>
using namespace std;

Boat::Boat() : Transport()
{
	ShipType = "empty";
}

void Boat::Input()
{
	Transport::Input();
	cout << "Enter ship type: ";
	cin >> ShipType;
}
void Boat::Print() const
{
	Transport::Print();
	cout << "Ship type: " << ShipType << endl;
}