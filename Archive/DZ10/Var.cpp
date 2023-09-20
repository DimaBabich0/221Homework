#include "Var.h"
#include "MyString.h"
#include <iostream>
using namespace std;

Var::Var() : str(MyString())
{
	intNum = NULL;
	doubleNum = NULL;
}
Var::Var(const int userNum) : intNum(userNum)
{}
Var::Var(const double userNum) : doubleNum(userNum)
{}
Var::Var(const char* userStr) : str(MyString(userStr))
{}

Var Var::operator+(Var point)
{
	return Var();
}
Var Var::operator-(Var point)
{
	return Var();
}
Var Var::operator*(Var point)
{
	return Var();
}
Var Var::operator/(Var point)
{
	return Var();
}
