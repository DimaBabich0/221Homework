#include "QueueStatistic.h"
#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

QueueStatistic::QueueStatistic(int userLength)
{
	MaxQueueLength = userLength;
	Name = new string[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	Time = new string[MaxQueueLength];
	QueueLength = 0;
}
QueueStatistic::~QueueStatistic()
{
	delete[] Name;
	delete[] Pri;
	delete[] Time;
}

void QueueStatistic::Add(string userStr, int userPri)
{
	if (!IsFull())
	{
		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);
		char buff[9];
		strftime(buff, 9, "%H:%M:%S", &newtime);
		Time[QueueLength] = buff;

		Name[QueueLength] = userStr;
		Pri[QueueLength] = userPri;
		QueueLength++;
		Sleep(1000);//using Sleep for different time
	}
}
void QueueStatistic::Print()
{
	cout << "\tList of statistic:" << endl;
	for (int i = 0; i < QueueLength; i++)
		cout << Name[i] << " - " << Pri[i] << " - " << Time[i] << endl;
}

bool QueueStatistic::IsFull()
{
	return QueueLength == MaxQueueLength;
}