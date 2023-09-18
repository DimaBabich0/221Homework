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
	int MyChr(char ch);// ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen(const char* userStr);// ���������� ����� ������
	void MyStrCat(MyString& point); // ����������� �����
	void MyDelChr(char ch); // ������� ��������� ������
	int MyStrCmp(MyString& point); // ��������� �����

	static int getStatic();
	static void setStatic(int num);

	char& operator[](const unsigned int index);
	void operator() ();
};