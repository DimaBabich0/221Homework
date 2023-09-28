#include "QueuePriority.h"
#include "QueueStatistic.h"

int main()
{
	const int SIZE = 5;
	QueuePriority QUPrio(SIZE);//Queue clients
	QueueStatistic QUStat(SIZE);//Queue statistic

	//Enter all queue of clients
	for (int i = 0; i < SIZE; i++)
	{
		string userName;
		int userPri;

		cout << "Enter name for " << i + 1 << " client: ";
		cin >> userName;
		cout << "Enter priority for " << i + 1 << " client: ";
		cin >> userPri;
		QUPrio.Add(userName, userPri);
		cout << endl;
	}

	//Print both queue before using printer
	QUPrio.Print();
	QUStat.Print();
	system("pause");
	system("cls");

	//Emulation of using printer (will have to wait)
	cout << "The queue is running. Please wait..." << endl;
	for (int i = 0; i < SIZE; i++)
		QUPrio.UsePrinter(QUStat);
	system("cls");

	//Print both queue after using printer
	QUPrio.Print();
	QUStat.Print();
}