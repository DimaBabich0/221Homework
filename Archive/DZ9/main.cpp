#include "MyString.h"
unsigned int MyString::s_count = 0;

int main()
{
	MyString point("hello");
	cout << "\tOriginal point:\n" << point << endl;

	point++;
	cout << "\tpoint++:\n" << point << endl;
	++point;
	cout << "\t++point:\n" << point << endl;

	point = point + 'w';
	point = 'o' + point;
	point = point + 'r';
	point = 'l' + point;
	point = point + 'd';
	cout << "\tAdd to point chars:\n" << point << endl;

	point = point + 5;
	cout << "\tAdd to point 5 elements (point + 5):\n" << point << endl;
	point = 5 + point;
	cout << "\tAdd to point 5 elements (5 + point):\n" << point << endl;
}