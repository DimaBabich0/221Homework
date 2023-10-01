#include "Var.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Var intPoint = 5;
	Var doublePoint = 5.5;
	Var strPoint1 = "Hello";
	Var strPoint2 = "50";

	Var result = intPoint + doublePoint;
	result.Print();

	result = intPoint + strPoint2;
	result.Print();

	result = strPoint2 + intPoint;
	result.Print();

	result = doublePoint + intPoint;
	result.Print();

	result = doublePoint + strPoint2;
	result.Print();

	result = strPoint1 + doublePoint;
	result.Print();
}