#pragma once
class Var
{
private:
	int intNum;
	double doubleNum;
	MyString str;
public:
	Var();
	Var(const int userNum);
	Var(const double userNum);
	Var(const char* userStr);
	
	Var operator+(Var point);
	Var operator-(Var point);
	Var operator*(Var point);
	Var operator/(Var point);
};