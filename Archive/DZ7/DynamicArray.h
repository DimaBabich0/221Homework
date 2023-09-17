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

	DynamicArray& operator=(DynamicArray&& );
	DynamicArray operator+(int);
	DynamicArray operator-(int);
	DynamicArray operator*(int);

	DynamicArray operator+(DynamicArray);
	DynamicArray operator-(DynamicArray);

	DynamicArray& operator++();
	DynamicArray& operator--();
};