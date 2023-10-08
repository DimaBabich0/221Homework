#include <iostream>
using namespace std;

class Stack
{
private:
	enum { EMPTY = -1, FULL = 30 };
	char st[FULL + 1];
	int top;
public:
	Stack();
	void Print();
	void Push(char c);
	char Pop();
	char GetLastElem();
	void CheckCorrectness();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
};

Stack::Stack()
{
	top = EMPTY;
}
void Stack::Print()
{
	for (int i = 0; i <= top; i++)
		cout << st[i] << " ";
}
void Stack::Clear()
{
	top = EMPTY;
}
bool Stack::IsEmpty()
{
	return top == EMPTY;
}
bool Stack::IsFull()
{
	return top == FULL;
}
int Stack::GetCount()
{
	return top + 1;
}
void Stack::Push(char c)
{
	if (!IsFull())
		st[++top] = c;
}
char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else
		return 0;
}
char Stack::GetLastElem()
{
	if (!IsEmpty())
		return st[top];
	else
		return 0;
}
void Stack::CheckCorrectness()
{
	bool isCorrect = true;
	bool isFind = false;

	for (int i = 0; i <= top; i++)
	{
		if (st[i] == '{' || st[i] == '(' || st[i] == '[')
		{
			isFind = false;
			for (int j = i; j <= top; j++)
			{
				if (st[i] == '{' && st[j] == '}')
					isFind = true;
				else if (st[i] == '(' && st[j] == ')')
					isFind = true;
				else if (st[i] == '[' && st[j] == ']')
					isFind = true;

				if (isFind)
					break;
			}
			if (!isFind)
			{
				isCorrect = false;
				break;
			}

		}
	}
	
	if (isCorrect)
	{
		cout << "It's correct string:" << endl;
		Print();
	}
	else
	{
		cout << "It's not correct string." << endl;
	}
}

void main()
{
	Stack ST;
	char userCh;

	cout << "\tEnter a string. To stop entering, type \";\"" << endl;
	while (true)
	{
		cin >> userCh;
		if (userCh != ';')
			ST.Push(userCh);
		else
			break;
	}

	ST.CheckCorrectness();
}
