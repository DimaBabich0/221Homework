#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char* str;
	int length;

	static unsigned int s_count;
	static void PlusStatic();
public:
	MyString();
	MyString(const char* userStr);
	MyString(const MyString& point);
	~MyString();
	MyString& operator=(const MyString& point);
	MyString(initializer_list<char> point);

	void Input();
	void Print();

	void MyStrCpy(MyString& point);
	void MyStrCpy(const char* userStr);
	bool MyStrStr(const char* userStr);
	int MyChr(char ch);
	int MyStrLen(const char* userStr);
	void MyStrCat(MyString& point);
	void MyDelChr(char ch);
	int MyStrCmp(MyString& point);

	static int GetStatic();
	static void SetStatic(int num);

	char* GetStr() const;
	int GetLength() const;
	void SetStr(char* userStr);
	void SetLength(int userLength);

	char& operator[](const unsigned int index);
	void operator() ();
};

MyString operator+(MyString point1, const char point2);
MyString operator+(const char point1, MyString point2);


ostream& operator<<(ostream& os, const MyString& point);
istream& operator>>(istream& is, MyString& obj);