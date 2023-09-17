#include "DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray()
{
	//cout << "Construct by default" << endl;
	ptr = nullptr;
	size = NULL;
}
DynamicArray::DynamicArray(int userSize)
{
	//cout << "Construct by 1 param" << endl;
	if (userSize < 0)
		userSize = 0;
	size = userSize;
	ptr = new int[userSize];
	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}
DynamicArray::DynamicArray(const DynamicArray& point)// copy constructor
{
	//cout << "Copy construct" << endl;
	size = point.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
		ptr[i] = point.ptr[i];
}
DynamicArray::~DynamicArray()
{
	//cout << "Destruct" << endl;;
	delete[] ptr;
}

void DynamicArray::inputRand(int userMin, int userMax)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < size; i++)
		ptr[i] = (userMin + rand() % (userMax - userMin));
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
		cout << ptr[i] << " ";
}

int* DynamicArray::getPointer() const
{
	return ptr;
}
int DynamicArray::getSize() const
{
	return size;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& point)  
{
	if (this != &point)
	{
		delete[] ptr;
		ptr = point.ptr;
		point.ptr = nullptr;

		size = point.size;
		point.size = NULL;
	}
	return *this;
}
DynamicArray DynamicArray::operator+(int userNum)
{
	DynamicArray newArr(size + userNum);
	for (int i = 0; i < newArr.size; i++)
	{
		if (i < size)
			newArr.ptr[i] = ptr[i];
		else
			newArr.ptr[i] = 0;
	}
	return newArr;
}
DynamicArray DynamicArray::operator-(int userNum)
{
	int newSize;
	if(size < 2)
		newSize = 0;
	else
		newSize = size - userNum;

	DynamicArray newArr(newSize);
	for (int i = 0; i < newArr.size; i++)
		newArr.ptr[i] = ptr[i];
	return newArr;
}
DynamicArray DynamicArray::operator*(int userNum)
{
	DynamicArray newArr = *this;
	for (int i = 0; i < size; i++)
		newArr.ptr[i] *= userNum;
	return newArr;
}

DynamicArray DynamicArray::operator+(DynamicArray point)
{
	DynamicArray newArr(size + point.size);
	int temp = 0;
	for (int i = 0; i < newArr.size; i++)
	{
		if (i < size)
			newArr.ptr[i] = ptr[i];
		else
			newArr.ptr[i] = point.ptr[temp++];
	}
	return newArr;
}
DynamicArray DynamicArray::operator-(DynamicArray point)
{
	DynamicArray newArr(size - point.size);
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		if (i > point.size - 1)
			newArr.ptr[temp++] = ptr[i];
	}
	return newArr;
}

DynamicArray& DynamicArray::operator++()
{
	size++;
	int* newPtr = new int[size];

	for (int i = 0; i < size - 1; i++)
		newPtr[i] = ptr[i];
	newPtr[size - 1] = 0;

	delete[] ptr;
	ptr = newPtr;
	return *this;
}
DynamicArray& DynamicArray::operator--()
{
	if(size <= 0)
		return *this;

	size--;
	int* newPtr = new int[size];

	for (int i = 0; i < size; i++)
		newPtr[i] = ptr[i];

	delete[] ptr;
	ptr = newPtr;
	return *this;
}