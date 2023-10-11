#include "ArrayValueCalculator.h"
#include "ArraySizeException.h"
#include "ArrayDataException.h"
#include <iostream>
using namespace std;

int main()
{
	int cols;
	int rows;

	try
	{
		cout << "Enter number of cols: ";
		cin >> cols;
		cout << "Enter number of rows: ";
		cin >> rows;

		if (cols <= 0 && rows <= 0)
			throw ArraySizeException("Size can't be zero or minus");

		char** ptr = new char* [cols];
		for (int i = 0; i < rows; i++)
		{
			ptr[i] = new char[rows];
			for (int j = 0; j < rows; j++)
			{
				ptr[i][j] = '0' + rand()%9;

				//special error for throw a exception
				if (i == 2 && j == 3)
					ptr[i][j] = '/';

				cout << ptr[i][j] << " ";
			}
			cout << endl;
		}
		ArrayValueCalculator point;
		cout << "Sum: " << point.doCalc(ptr, cols, rows);

		for (int i = 0; i < rows; i++)
		{
			delete[] ptr[i];
		}
		delete ptr;
	}
	catch (ArraySizeException exception)
	{
		cout << exception.GetMessage() << endl;
	}
	catch (ArrayDataException exception)
	{
		cout << exception.GetMessage() << endl;
	}
}