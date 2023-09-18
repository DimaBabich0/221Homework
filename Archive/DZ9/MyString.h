#pragma once
class MyString
{
private:
	char* str;
	int length;

	void deleteNullPtr(char* pointer);
	void coutVariable(char* variable);
	static void plusStatic();

	static unsigned int s_count;
public:
	MyString();
	MyString(const char* userStr);//parametrs
	MyString(const MyString& point);
	~MyString();

	void Input();
	void Print();

	void MyStrCpy(MyString& point);
	void MyStrCpy(const char* userStr);
	bool MyStrStr(const char* userStr);
	int MyChr(char ch);// поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen(const char* userStr);// возвращает длину строки
	void MyStrCat(MyString& point); // объединение строк
	void MyDelChr(char ch); // удаляет указанный символ
	int MyStrCmp(MyString& point); // сравнение строк

	static int getStatic();
	static void setStatic(int num);

	char& operator[](const unsigned int index);
	void operator() ();
};