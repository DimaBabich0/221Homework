#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
	cout << "Construct by default" << endl;
	ptr = nullptr;
	size = NULL;
}
DynamicArray::DynamicArray(int userSize)
{
	cout << "Construct by 1 param" << endl;
	size = userSize;
	ptr = new int[userSize];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = 0;
	}
}
DynamicArray::DynamicArray(const DynamicArray& point)// copy constructor
{
	cout << "Copy construct" << endl;
	size = point.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = point.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct" << endl;;
	delete[] ptr;
}

void DynamicArray::inputRand(int userMin, int userMax)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
	{
		ptr[i] = (userMin + rand() % (userMax - userMin));
	}
}
void DynamicArray::input()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter number for element " << i + 1 << ": ";
		cin >> ptr[i];
	}
	cout << endl;
}

void DynamicArray::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << " ";
	}
	cout << "\n------------------" << endl;
}
int* DynamicArray::getPointer() const
{
	return ptr;
}
int DynamicArray::getSize() const
{
	return size;
}

void DynamicArray::plusSize(int newSize)
{
	int totalSize = size + newSize;
	int* newPtr = new int[totalSize];

	for (int i = 0; i < totalSize; i++)
	{
		if (i < size)
			newPtr[i] = ptr[i];
		else if (i >= size)
			newPtr[i] = 0;
	}

	delete[]ptr;
	ptr = newPtr;
	size = totalSize;
}
void DynamicArray::sort() 
{
	int temp;
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}
int DynamicArray::search(int userNum)
{
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == userNum)
			return i;
	}
	return -1;
}
void DynamicArray::reverse()
{
	int* tempPtr = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempPtr[i] = ptr[size - 1 - i];
	}

	delete[]ptr;
	ptr = tempPtr;
}