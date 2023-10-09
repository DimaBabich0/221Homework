#include "University.h"
#include <string>
#include <iostream>
using namespace std;

void University::Input()
{
	cout << "Name: ";
	cin >> name;
	cout << "Adress: ";
	cin >> adress;
	cout << "Faculty: ";
	cin >> faculty;
}