#include <iostream>
#include "Car.h"
using namespace std;

int main()
{
	Car p1;
	p1.print();
	cout << "-----------" << endl;
	p1.input();
	cout << "-----------" << endl;
	p1.print();
	
	system("pause");
	system("cls");

	Car p2("Tayota", "Red", 2019, 30000.80);
	p2.print();
	cout << "-----------" << endl;
	cout << "Model: " << p2.getModel() << endl;
	p2.setModel("Audi");
	cout << "New model: " << p2.getModel() << endl;
}