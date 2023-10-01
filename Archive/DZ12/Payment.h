#include <iostream>
#include <string>
using namespace std;

class Payment
{
private:
	string FirstName;
	string LastName;
	string MiddleName;

	int YearJoined;
	int AllowancePercent;

	int DaysWork;
	int DaysWorked;

	double SalaryAmount;
	double AccrualsAmount;
	double DeductionsAmount;
public:
	Payment();
	Payment(const char* u_FName, const char* u_LName, const char* u_MName, int u_yearJoined, int u_AP, int u_DWork, int u_Dworked, double u_salary);

	void CountDeductions();
	void CountAccruals();
	void PrintSeniority();
	void PrintTotal();
	void PrintAllInfo();
};