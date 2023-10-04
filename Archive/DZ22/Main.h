#pragma once
#include "Car.h"
#include "Motorcycle.h"
#include "Tram.h"
#include "Airplane.h"
#include "Boat.h"
#include <iostream>
using namespace std;

enum codeActionsMenu { codeChangeType = 1, codeInputObject, codePrintObject, codeExitProgram };
enum codeTypes { codeCar = 1, codeMotorcycle, codeTram, codeAirplane, codeBoat};

void ChangeType(Transport*& obj);
void PrintMenu();
void PrintTypes();

void ChangeType(Transport*& obj)
{
	if (obj != nullptr)
	{
		delete obj;
		obj = nullptr;
	}

	int userChoice;
	while (obj == nullptr)
	{
		PrintTypes();
		cout << "Choose type: ";
		cin >> userChoice;
		switch (userChoice)
		{
		case codeCar:
			obj = new Car;
			break;
		case codeMotorcycle:
			obj = new Motorcycle;
			break;
		case codeTram:
			obj = new Tram;
			break;
		case codeAirplane:
			obj = new Airplane;
			break;
		case codeBoat:
			obj = new Boat;
			break;
		default:
			cout << "Wrong code. Try again" << endl;
		}
	}
}
void PrintMenu()
{
	cout << "\tMenu" << endl;
	cout << codeChangeType << " - Change type of object" << endl;
	cout << codeInputObject << " - Input information" << endl;
	cout << codePrintObject << " - Print information" << endl;
	cout << codeExitProgram << " - Exit the program" << endl;
}
void PrintTypes()
{
	cout << codeCar << " - Car" << endl;
	cout << codeMotorcycle << " - Motorcycle" << endl;
	cout << codeTram << " - Tram" << endl;
	cout << codeAirplane << " - Airplane" << endl;
	cout << codeBoat << " - Boat" << endl;
}