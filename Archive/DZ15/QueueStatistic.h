#pragma once
#include <iostream>
#include <string>
using namespace std;

class QueueStatistic
{
private:
	string* Name;
	int* Pri;
	string* Time;
	int MaxQueueLength;
	int QueueLength;
public:
	QueueStatistic(int userLength);
	~QueueStatistic();

	bool IsFull();
	void Add(string userStr, int userPri);
	void Print();
};