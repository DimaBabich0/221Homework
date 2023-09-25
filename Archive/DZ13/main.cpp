#include "Bankomat.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//array for banknotes
	const int arrSize = 10;
	int array[arrSize] = { 10, 50, 50, 100, 500, 100, 50, 50, 1000, 200 };

	//bankomat class object creation
	Bankomat point("1020B", arrSize, array, 10, 1000);

	//print information
	point.Print();
	cout << endl;

	//add new banknotes
	point.AddMoney();
	point.Print();
	cout << endl;

	//withdraw money
	point.WithdrawalMoney();
	point.Print();
}