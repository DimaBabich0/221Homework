#include "Bankomat.h"
#include <iostream>
#include <string>
using namespace std;

void Bankomat::Sort()
{
	int temp;
	for (int i = 1; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize - i; j++)
		{
			if (arrBanknotes[j] > arrBanknotes[j + 1])
			{
				temp = arrBanknotes[j];
				arrBanknotes[j] = arrBanknotes[j + 1];
				arrBanknotes[j + 1] = temp;
			}
		}
	}
}

Bankomat::Bankomat(const char* userId, int userArrSize, int* userArrBanknotes, const int userMin, const int userMax) : id(userId), minWithdrawal(userMin), maxWithdrawal(userMax)
{
	arrSize = userArrSize;
	arrBanknotes = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
		arrBanknotes[i] = userArrBanknotes[i];
	Sort();
}
Bankomat::Bankomat(const Bankomat& point) : id(point.id), minWithdrawal(point.minWithdrawal), maxWithdrawal(point.maxWithdrawal)
{
	arrSize = point.arrSize;
	arrBanknotes = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
		arrBanknotes[i] = point.arrBanknotes[i];
}
Bankomat::~Bankomat()
{
	delete[] arrBanknotes;
}

void Bankomat::AddMoney()
{
	int userSize;
	cout << "How many new banknotes do you want to add: ";
	cin >> userSize;

	if (userSize <= 0)
	{
		cout << "You entered an invalid amount. The operation was canceled." << endl << endl;
		return;
	}
	
	int* newArr = new int[arrSize + userSize];
	for (int i = 0; i < arrSize + userSize; i++)
	{
		if (i < arrSize)
			newArr[i] = arrBanknotes[i];
		else
		{
			cout << "Enter the denomination of the banknote: ";
			cin >> newArr[i];
		}
	}

	arrSize += userSize;
	delete[] arrBanknotes;
	arrBanknotes = newArr;
	Sort();
	cout << "The operation was successful. The banknotes were added to the ATM." << endl << endl;
}
void Bankomat::WithdrawalMoney()
{
	int userWithdrawal;
	cout << "How much do you want to withdraw: ";
	cin >> userWithdrawal;

	if (userWithdrawal <= minWithdrawal || userWithdrawal >= maxWithdrawal)
	{
		cout << "You entered an invalid amount. The operation was canceled." << endl << endl;
		return;
	}

	int* tempArr = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		tempArr[i] = arrBanknotes[arrSize - i - 1];
	}

	int newSize = arrSize;
	for (int i = 0; i < arrSize; i++)
	{
		if ((userWithdrawal - tempArr[i]) >= 0)
		{
			userWithdrawal -= tempArr[i];
			tempArr[i] = 0;
			newSize--;
			if (userWithdrawal == 0)
				break;
		}
	}

	if (userWithdrawal != 0)
	{
		cout << "The ATM doesn't have the right banknotes. Try the different amount." << endl;
		return;
	}

	delete[] arrBanknotes;
	arrBanknotes = new int[newSize];
	int index = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (tempArr[i] != 0)
			arrBanknotes[index++] = tempArr[i];
	}
	delete[] tempArr;
	arrSize = newSize;
	Sort();
	cout << "The operation was successful. You can take your money." << endl << endl;
}
void Bankomat::Print()
{
	cout << "ID bankomat: " << id << endl;
	cout << "List of banknotes[" << arrSize << "]: " << endl;
	for (int i = 0; i < arrSize; i++)
	{
		if (i != 0 && i % 5 == 0)
			cout << endl;
		cout << arrBanknotes[i] << "\t";
	}
	cout << "\nAmount of banknotes: " << ToString() << endl;
	cout << "Number of minimum withdrawals: " << minWithdrawal << endl;
	cout << "Number of maximum withdrawals: " << maxWithdrawal << endl;
}
string Bankomat::ToString()
{
	int sum = 0;
	for (int i = 0; i < arrSize; i++)
	{
		sum += arrBanknotes[i];
	}
	return string(to_string(sum));
}