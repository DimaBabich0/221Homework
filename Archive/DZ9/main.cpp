#include <iostream>
#include "MyString.h"
using namespace std;

unsigned int MyString::s_count = 0;

int main()
{
	MyString point1("hello");
	MyString point2("world");

	cout << "\tExample of move constuctor: " << endl;
	cout << "First string: ";
	point1.Print();
	cout << "Second string: ";
	point2.Print();

	MyString temp = move(point1);
	point1 = move(point2);
	point2 = move(temp);

	cout << "\nFirst string: ";
	point1.Print();
	cout << "Second string: ";
	point2.Print();

	cout << "\nStatic count: " << MyString::getStatic();
}