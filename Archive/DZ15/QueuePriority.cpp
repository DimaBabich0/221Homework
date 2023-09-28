#include "QueuePriority.h"
#include "QueueStatistic.h"
#include <iostream>
#include <string>
using namespace std;

QueuePriority::QueuePriority(int userLength)
{
	MaxQueueLength = userLength;
	Wait = new string[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}
QueuePriority::~QueuePriority()
{
	delete[] Wait;
	delete[] Pri;
}

void QueuePriority::Add(string userStr, int userPri)
{
	if (!IsFull())
	{
		Wait[QueueLength] = userStr;
		Pri[QueueLength] = userPri;
		QueueLength++;
	}
}
void QueuePriority::Print()
{
	cout << "\tList of queue:" << endl;
	for (int i = 0; i < QueueLength; i++)
		cout << Wait[i] << " - " << Pri[i] << endl;
}
void QueuePriority::UsePrinter(QueueStatistic& point)
{
	if (!IsEmpty())
	{
		int max_pri = Pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++)
		{
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		}

		point.Add(Wait[pos_max_pri], Pri[pos_max_pri]);

		string temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;
	}
}

string QueuePriority::Extract()
{
	if (!IsEmpty())
	{
		int max_pri = Pri[0];
		int pos_max_pri = 0;

		for (int i = 1; i < QueueLength; i++)
		{
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		}

		string temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}

		QueueLength--;
		return temp1;
	}
	else return string("empty");
}
void QueuePriority::Clear()
{
	QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}
bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	return QueueLength;
}