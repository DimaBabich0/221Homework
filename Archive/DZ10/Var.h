#pragma once
#include <string>
using namespace std;

class Var
{
private:
	int intNum;
	double doubleNum;
	string str;

	bool isFullNull();
public:
	Var();
	Var(const int userNum);
	Var(const double userNum);
	Var(const char* userStr);

	void Print();
	
	Var operator+(Var point);
	Var operator-(Var point);
	Var operator*(Var point);
	Var operator/(Var point);
};