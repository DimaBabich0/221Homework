#include <iostream>
#include "DynamicArray.h"
using namespace std;

void clearConsole()
{
	cout << endl;
	system("pause");
	system("cls");
}

int main()
{
	cout << "First array:" << endl;
	DynamicArray point1(5);
	point1.inputRand(1, 10);
	point1.print();
	clearConsole();
	
	cout << "Result of adding 2 elements to array:" << endl;
	DynamicArray result = point1 + 2;
	result.print();
	clearConsole();
	
	cout << "Result of deleting 2 last elements to array:" << endl;
	result = point1 - 2;
	result.print();
	clearConsole();

	cout << "Result of multiplication of all array elements by 2:" << endl;
	result = point1 * 2;
	result.print();
	clearConsole();

	cout << "First array:" << endl;
	point1.print();
	cout << "\nSecond array:" << endl;
	DynamicArray point2(3);
	point2.inputRand(1, 10);
	point2.print();
	clearConsole();

	cout << "Result of subtracting arrays:" << endl;
	result = point1 - point2;
	result.print();
	clearConsole();

	cout << "Result of adding arrays:" << endl;
	result = point1 + point2;
	result.print();
	clearConsole();

	cout << "Result of adding point1 1 element:" << endl;
	++point1;
	point1.print();
	clearConsole();

	cout << "Result of deleting point2 1 element:" << endl;
    --point2;
	point2.print();
}