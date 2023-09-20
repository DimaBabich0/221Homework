#pragma once
class MyString
{
private:
	char* str;
	int length;

	void coutVariable(char* variable);
	static void plusStatic();

	static unsigned int s_count;
public:
	MyString();
	MyString(const char* userStr);
	MyString(const MyString& point);
	~MyString();

	MyString& operator= (const MyString& point);
	MyString(MyString&& point);
	MyString& operator= (MyString&& point);

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

	static int getStatic();
	static void setStatic(int num);

	char& operator[](const unsigned int index);
	void operator() ();
};