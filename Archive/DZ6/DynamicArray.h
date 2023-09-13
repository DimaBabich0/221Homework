#pragma once
class DynamicArray
{
private:
	int* ptr;
	int size;
public:
	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();

	void inputRand(int, int);
	void input();
	void print() const;
	int* getPointer() const;
	int getSize() const;

	void plusSize(const int);
	void sort();
	int search(int);
	void reverse();
};