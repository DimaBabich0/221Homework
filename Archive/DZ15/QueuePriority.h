#pragma once
#include <iostream>
#include <string>
#include "QueueStatistic.h"
using namespace std;

class QueuePriority
{
private:
	string* Wait;
	int* Pri;
	int MaxQueueLength;
	int QueueLength;
public:
	QueuePriority(int userLength);
	~QueuePriority();

	void Add(string str, int userPri);
	void Print();
	void UsePrinter(QueueStatistic& point);

	string Extract();
	void Clear();

	bool IsEmpty();
	bool IsFull();
	int GetCount();
};