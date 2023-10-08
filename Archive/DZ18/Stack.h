#pragma once

class Element
{
private:
	int data;
	Element* next;
	Element* prev;
public:
	Element(int userData) : data(userData), next(nullptr), prev(nullptr) {}

	int GetData()
	{
		return data;
	}
	Element* GetNext()
	{
		return next;
	}
	Element* GetPrev()
	{
		return prev;
	}

	void SetData(int userData)
	{
		data = userData;
	}
	void SetNext(Element* userNext)
	{
		next = userNext;
	}
	void SetPrev(Element* userPrev)
	{
		prev = userPrev;
	}
};

class Stack
{
private:
	Element* top;
public:
	Stack();
	~Stack();

	bool isEmpty();
	void Add(int userData);
	int Get();
	void Del();
	void DelAll();
	void Print();
};