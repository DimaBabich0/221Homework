#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
	DynamicArray point(5);
	point.inputRand(1, 10);
	cout << "Random numbers: " << endl;
	point.print();

	cout << "Sort numbers: " << endl;
	point.sort();
	point.print();

	cout << "Plus 5 to size: " << endl;
	point.plusSize(5);
	point.print();

	system("pause");
	system("cls");

	cout << "Copy object, print and enter new number: " << endl;
	DynamicArray copyPoint = point;
	copyPoint.print();
	copyPoint.input();
	copyPoint.print();

	cout << "Search number 5 in array: " << endl;
	cout << "Index: " << copyPoint.search(5) << endl;
}