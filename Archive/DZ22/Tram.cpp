#include "Tram.h"
#include <iostream>
using namespace std;

Tram::Tram() : Transport()
{
	NumberWagons = NULL;
}

void Tram::Input()
{
	Transport::Input();
	cout << "Enter number of wagons: ";
	cin >> NumberWagons;
}
void Tram::Print() const
{
	Transport::Print();
	cout << "Number of wagons: " << NumberWagons << endl;
}