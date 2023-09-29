#include "Matrix.h"
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	srand(time(0));
	cout << "myPoint1:" << endl;
	Matrix<Point> myPoint1(2, 2);
	myPoint1.InputRand(1,20);
	myPoint1.Print();

	cout << "myPoint2:" << endl;
	Matrix<Point> myPoint2(2, 2);
	myPoint2.Input();
	myPoint2.Print();

	cout << "Max and min of myPoint1: " << endl;
	myPoint1.FindMin();
	myPoint1.FindMax();
	cout << endl;

	cout << "myPoint1 + myPoint2:" << endl;
	Matrix<Point> pointResult = myPoint1 + myPoint2;
	pointResult.Print();

	cout << "myPoint1 - myPoint2:" << endl;
	pointResult = myPoint1 - myPoint2;
	pointResult.Print();

	cout << "myPoint1 * myPoint2:" << endl;
	pointResult = myPoint1 * myPoint2;
	pointResult.Print();

	cout << "myPoint1 / myPoint2:" << endl;
	pointResult = myPoint1 / myPoint2;
	pointResult.Print();

	system("pause");
	system("cls");

	cout << "myInt1:" << endl;
	Matrix<int> myInt1(3, 2);
	myInt1.InputRand(25, 50);
	myInt1.Print();

	cout << "myInt2:" << endl;
	Matrix<int> myInt2(3, 2);
	myInt2.InputRand(1, 25);
	myInt2.Print();

	cout << "Max and min of myInt1: " << endl;
	myInt1.FindMin();
	myInt1.FindMax();
	cout << endl;

	cout << "myInt1 + myInt2: " << endl;
	Matrix<int> intResult = myInt1 + myInt2;
	intResult.Print();

	cout << "myInt1 - myInt2: " << endl;
	intResult = myInt1 - myInt2;
	intResult.Print();

	cout << "myInt1 * myInt2: " << endl;
	intResult = myInt1 * myInt2;
	intResult.Print();

	cout << "myInt1 / myInt2: " << endl;
	intResult = myInt1 / myInt2;
	intResult.Print();
}