#pragma once
#include <string>
using namespace std;
class Bankomat
{
private:
	string id;
	int arrSize;
	int* arrBanknotes;
	const int minWithdrawal = 10;
	const int maxWithdrawal = 1000;

	void Sort();
public:
	Bankomat() = delete;
	Bankomat(const char* userId, int userArrSize, int* userBanknotes, const int userMin, const int userMax);
	Bankomat(const Bankomat& point);
	~Bankomat();

	void AddMoney();
	void WithdrawalMoney();
	void Print();
	string ToString();
};