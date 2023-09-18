#include <iostream>
#include "MyString.h"
using namespace std;

unsigned int MyString::s_count = 0;

int main()
{
	MyString point1("Hello ");
	MyString point2("world");
	cout << "First string: ";
	point1.Print();
	cout << "Second string: ";
	point2.Print();

	cout << "\nConnect second string to first: ";
	point1.MyStrCat(point2);
	point1.Print();

	MyString point3;
	cout << "\nCopy to third string first: ";
	point3.MyStrCpy(point1);
	point3.Print();

	cout << "\nComparison of the first string with the third: " << point1.MyStrCmp(point3) << endl;

	cout << "\nDelete character ('w'): ";
	point3.MyDelChr('w');
	point3.Print();

	cout << "\nComparison of the third line with the first (after deleting the character): " << point3.MyStrCmp(point1) << endl;

	cout << "\nInput user string: " << endl;
	MyString point4;
	point4();

	cout << "\nStatic count: " << MyString::getStatic();
}