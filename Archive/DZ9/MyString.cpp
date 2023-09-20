#include "MyString.h"
#include <iostream>
using namespace std;

void MyString::coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}
void MyString::plusStatic()
{
	MyString::s_count++;
}

MyString::MyString()
{
	str = nullptr;
	length = NULL;
	plusStatic();
}
MyString::MyString(const char* userStr)//parametrs
{
	length = MyStrLen(userStr) + 1;
	str = new char[length];
	for (int i = 0; i < length; i++)
		str[i] = userStr[i];
	plusStatic();
}
MyString::MyString(const MyString& point)
{
	length = point.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = point.str[i];
	plusStatic();
}
MyString::~MyString()
{
	delete[] str;
}

MyString& MyString::operator= (const MyString& point)
{
	if (this != &point)
	{
		delete[] str;
		length = point.length;
		str = new char[length];
		for (int i = 0; i < length; i++)
			str[i] = point.str[i];
	}
	return *this;
}
MyString::MyString(MyString&& point)
{
	length = point.length;
	point.length = NULL;
	str = point.str;
	point.str = nullptr;
}
MyString& MyString::operator= (MyString&& point)
{
	if (this != &point)
	{
		delete[] str;
		length = point.length;
		point.length = NULL;
		str = point.str;
		point.str = nullptr;
	}
	return *this;
}

void MyString::Input()
{
	char buff[90];
	cout << "Enter string: ";
	cin.getline(buff, sizeof(buff));
	MyStrCpy(buff);
}
void MyString::Print()
{
	coutVariable(str);
}

void MyString::MyStrCpy(MyString& point)
{
	delete[] str;
	length = point.length;
	str = new char[length];
	for (int i = 0; i < length; i++)
		str[i] = point.str[i];
}
void MyString::MyStrCpy(const char* userStr)
{
	delete[] str;
	length = MyStrLen(userStr) + 1;
	str = new char[length];
	for (int i = 0; i < length; i++)
		str[i] = userStr[i];
}
bool MyString::MyStrStr(const char* subStr)
{
	if (str == nullptr || subStr == nullptr)
		return 0;

	int strLength = MyStrLen(str);
	int subStrLength = MyStrLen(subStr);
	int indexSubStr = 0;

	for (int i = 0; i < strLength; i++)
	{
		if (str[i] == subStr[indexSubStr])
			indexSubStr++;
		else if (str[i] != subStr[indexSubStr] && indexSubStr > 0)
		{
			indexSubStr = 0;
			i--;
		}
		else
			indexSubStr = 0;
		if (indexSubStr == subStrLength)
			return true;
	}
	return false;
}
int MyString::MyChr(char ch)
{
	if (str == nullptr)
		return -1;

	for (int i = 0; i < MyStrLen(str); i++)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}
int MyString::MyStrLen(const char* userStr)
{
	int i = 0;
	while (userStr[i] != '\0')
		i++;
	return i;
}
void MyString::MyStrCat(MyString& point)
{
	int newLength = length + point.length + 1;
	char* newStr = new char[newLength];

	int index = 0;
	for (int i = 0; i < length - 1; i++)
		newStr[index++] = str[i];
	for (int i = 0; i < point.length; i++)
		newStr[index++] = point.str[i];

	delete[] str;
	str = newStr;
	length = newLength;
}
void MyString::MyDelChr(char ch)
{
	bool isFind = false;
	int newLength = length;
	char* newStr = new char[newLength];

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ch && !isFind)
			isFind = true;

		if (!isFind)
			newStr[i] = str[i];
		else
			newStr[i] = str[i + 1];
	}

	if (isFind)
	{
		delete[] str;
		str = newStr;
		length = newLength;
	}
}
int MyString::MyStrCmp(MyString& point)
{
	if (str == nullptr)
		return -1;
	else if (point.str == nullptr)
		return 1;

	int index = 0;

	while (index != length || index != point.length)
	{
		if (str[index] == point.str[index])
			index++;
		else if (str[index] > point.str[index])
			return -1;
		else if (str[index] < point.str[index])
			return 1;
	}

	if (length > point.length)
		return -1;
	else if (length < point.length)
		return 1;
	else if (length == point.length)
		return 0;
}

int MyString::getStatic()
{
	return MyString::s_count;
}
void MyString::setStatic(int num)
{
	MyString::s_count = num;
}

char& MyString::operator[](const unsigned int index)
{
	if (index >= 0 && index < length)
		return str[index];
	return str[0];
}
void MyString::operator() ()
{
	this->Input();
	this->Print();
}