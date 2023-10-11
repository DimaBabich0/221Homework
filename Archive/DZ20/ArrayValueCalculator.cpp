#include "ArrayValueCalculator.h"
#include "ArraySizeException.h"
#include "ArrayDataException.h"
#include <string>
using namespace std;

int ArrayValueCalculator::doCalc(char** ptr, int cols, int rows)
{
	if (cols != 4 && rows != 4)
	{
		throw ArraySizeException("Size not equals 4");
	}

	int sum = 0;
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (!isdigit(ptr[i][j]))
			{
				string temp = ("Error in index ");
				temp += to_string(i);
				temp += ", ";
				temp += to_string(j);
				throw ArrayDataException(temp.c_str());
			}
			sum += ptr[i][j];
		}
	}
	return sum;
}