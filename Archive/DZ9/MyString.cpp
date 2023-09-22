#include "MyString.h"
void MyString::PlusStatic()
{
	MyString::s_count++;
}

MyString::MyString()
{
	str = nullptr;
	length = NULL;
	PlusStatic();
}
MyString::MyString(const char* userStr)
{
	length = MyStrLen(userStr) + 1;
	str = new char[length];
	for (int i = 0; i < length; i++)
		str[i] = userStr[i];
	PlusStatic();
}
MyString::MyString(const MyString& point)
{
	length = point.length;
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
		str[i] = point.str[i];
	PlusStatic();
}
MyString::~MyString()
{
	delete[] str;
}
MyString& MyString::operator=(const MyString& point)
{
	if (this != &point)
	{
		delete[] str;

		length = point.length;
		str = new char[length];

		for (int i = 0; i < length; ++i)
			str[i] = point.str[i];
	}

	return *this;
}
MyString::MyString(initializer_list<char> point)
{
	length = point.size() + 1;
	str = new char[length];
	for (auto i = point.begin(); i != point.end(); i++)
	{
		*str = *i;
		str++;
	}
	*str = '\0';
	str -= length - 1;
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
	if (str == nullptr)
		cout << "empty" << endl;
	else
		cout << str << endl;
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

int MyString::GetStatic()
{
	return MyString::s_count;
}
void MyString::SetStatic(int num)
{
	MyString::s_count = num;
}

char* MyString::GetStr() const
{
	return str;
}
int MyString::GetLength() const
{
	return length;
}
void MyString::SetStr(char* userStr)
{
	delete[] str;
	str = userStr;
}
void MyString::SetLength(int userLength)
{
	if (userLength >= 0)
		length = userLength;
	else
		length = NULL;
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

MyString operator+(MyString point1, const char point2)
{
	int newLength = point1.GetLength() + 1;
	char* newStr = new char[newLength];
	for (int i = 0; i < point1.GetLength() - 1; i++)
	{
		newStr[i] = point1.GetStr()[i];
	}
	newStr[newLength - 2] = point2;
	newStr[newLength - 1] = '\0';

	MyString tempStr(newStr);
	return tempStr;
}
MyString operator+(const char point1, MyString point2)
{
	int newLength = point2.GetLength() + 1;
	char* newStr = new char[newLength];
	for (int i = 0; i < point2.GetLength() - 1; i++)
	{
		newStr[i] = point2.GetStr()[i];
	}
	newStr[newLength - 2] = point1;
	newStr[newLength - 1] = '\0';

	MyString tempStr(newStr);
	return tempStr;
}

ostream& operator<<(ostream& os, const MyString& point)
{
	os << "String: " << point.GetStr() << endl;
	os << "Length: " << point.GetLength() << endl;
	return os;
}
istream& operator>>(istream& is, MyString& obj)
{
	char buff[90];
	cout << "Enter string: ";
	cin.getline(buff, sizeof(buff));
	obj.MyStrCpy(buff);
	return is;
}