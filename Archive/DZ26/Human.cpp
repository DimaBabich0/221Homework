#include "Human.h"
#include <iostream>
#include <string>
using namespace std;

void Human::Input()
{
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
}