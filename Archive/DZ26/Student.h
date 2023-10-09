#pragma once
#include "Human.h"
#include "University.h"
class Student : public Human, public University
{
private:
	string groupName;
	int arrSize;
	int* arrGrades;
public:
	Student();
	~Student();

	void Print();
	void Input();
};