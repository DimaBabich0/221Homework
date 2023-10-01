#include "Var.h"
#include <string>
#include <iostream>
using namespace std;

bool Var::isFullNull()
{
	if (intNum == NULL && doubleNum == NULL && str.empty())
		return true;
	return false;
}

Var::Var()
{
	str = nullptr;
	intNum = NULL;
	doubleNum = NULL;
}
Var::Var(const int userNum)
{
	intNum = userNum;
	doubleNum = NULL;
}
Var::Var(const double userNum)
{
	doubleNum = userNum;
	intNum = NULL;
}
Var::Var(const char* userStr) : str(userStr)
{
	intNum = NULL;
	doubleNum = NULL;
}

void Var::Print()
{
	if (intNum != NULL)
		cout << intNum << endl;
	else if (doubleNum != NULL)
		cout << doubleNum << endl;
	else if (!str.empty())
		cout << str << endl;
	else
		cout << "all empty" << endl;
}

Var Var::operator+(Var point)
{
	if (point.isFullNull())
		return Var();

	if (intNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(int(intNum + point.intNum));
		else if (point.doubleNum != NULL)
			return Var(int(intNum + point.doubleNum));
		else if (!point.str.empty())
			return Var(int(intNum + stoi(point.str)));
	}
	else if (doubleNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(double(doubleNum + point.intNum));
		else if (point.doubleNum != NULL)
			return Var(double(doubleNum + point.doubleNum));
		else if (!point.str.empty())
			return Var(double(doubleNum + stold(point.str)));
	}
	else if (!str.empty())
	{
		if (point.intNum != NULL)
		{
			string temp = str + to_string(point.intNum);
			return Var(temp.c_str());
		}
		else if (point.doubleNum != NULL)
		{
			string temp = str + to_string(point.doubleNum);
			return Var(temp.c_str());
		}
		else if (!point.str.empty())
		{
			string temp = str + point.str;
			return Var(temp.c_str());
		}
	}
	return Var();
}
Var Var::operator-(Var point)
{
	if (point.isFullNull())
		return Var();

	if (intNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(int(intNum - point.intNum));
		else if (point.doubleNum != NULL)
			return Var(int(intNum - point.doubleNum));
	}
	else if (doubleNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(double(doubleNum - point.intNum));
		else if (point.doubleNum != NULL)
			return Var(double(doubleNum - point.doubleNum));
	}
	return Var();
}
Var Var::operator*(Var point)
{
	if (point.isFullNull())
		return Var();

	if (intNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(int(intNum * point.intNum));
		else if (point.doubleNum != NULL)
			return Var(int(intNum * point.doubleNum));
	}
	else if (doubleNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(double(doubleNum * point.intNum));
		else if (point.doubleNum != NULL)
			return Var(double(doubleNum * point.doubleNum));
	}
	return Var();
}
Var Var::operator/(Var point)
{
	if (point.isFullNull())
		return Var();

	if (intNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(int(intNum / point.intNum));
		else if (point.doubleNum != NULL)
			return Var(int(intNum / point.doubleNum));
	}
	else if (doubleNum != NULL)
	{
		if (point.intNum != NULL)
			return Var(double(doubleNum / point.intNum));
		else if (point.doubleNum != NULL)
			return Var(double(doubleNum / point.doubleNum));
	}
	return Var();
}