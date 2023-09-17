#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
	Date date1, date2, result;
	int temp;

	cout << "\tEnter first date" << endl;
	date1.input();
	date1.print();

	cout << "\nEnter the number of days you want to increase the date by: ";
	cin >> temp;

	date1 += temp;
	cout << "Result: ";
	date1.print();
	
	cout << "\n\tEnter second date" << endl;
	date2.input();
	date2.print();

	cout << "\n\tResult of subtracting date 1 and date 2" << endl;
	cout << "Date 1: ";
	date1.print();
	cout << "Date 2: ";
	date2.print(); 
	cout << "Result: ";
	result = date1 - date2;
	result.print();
}