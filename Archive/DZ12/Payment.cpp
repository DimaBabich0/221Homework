#include "Payment.h"
using namespace std;

const int CURRENT_YEAR = 2023;
const int PENSION_FUND_PERCENT = 1;
const int INCOME_TAX_PERCENT = 13;

Payment::Payment()
{
	FirstName = nullptr;
	LastName = nullptr;
	MiddleName = nullptr;

	YearJoined = NULL;
	AllowancePercent = NULL;
	DaysWork = NULL;
	DaysWorked = NULL;
	SalaryAmount = NULL;
	DeductionsAmount = NULL;
	AccrualsAmount = NULL;
}
Payment::Payment(const char* u_FName, const char* u_LName, const char* u_MName, int u_YearJoined, int u_AP, int u_DWork, int u_DWorked, double u_salary)
{
	FirstName = u_FName;
	LastName = u_LName;
	MiddleName = u_MName;
	YearJoined = u_YearJoined;
	AllowancePercent = u_AP;
	DaysWork = u_DWork;
	DaysWorked = u_DWorked;
	SalaryAmount = u_salary;
	CountAccruals();
	CountDeductions();
}

void Payment::CountDeductions()
{
	DeductionsAmount = (AccrualsAmount / 100) * (INCOME_TAX_PERCENT + PENSION_FUND_PERCENT);
}
void Payment::CountAccruals()
{
	AccrualsAmount = (SalaryAmount / DaysWork * DaysWorked) + ((SalaryAmount / DaysWork * DaysWorked) / 100 * AllowancePercent);
}
void Payment::PrintSeniority()
{
	int temp = CURRENT_YEAR - YearJoined;
	cout << "Work experience: " << temp << " years" << endl;
}
void Payment::PrintTotal()
{
	double temp = AccrualsAmount - DeductionsAmount;
	cout << "Total: " << temp << endl;
}
void Payment::PrintAllInfo()
{
	cout << "\tPayment info:" << endl;
	cout << "Full name: " << FirstName << " " << LastName << " " << MiddleName << endl;
	cout << "Year joined: " << YearJoined << endl;
	cout << "Salary: " << SalaryAmount << endl;
	cout << "Allowance percent: " << AllowancePercent << "%" << endl;
	cout << "Income tax: " << INCOME_TAX_PERCENT << "%" << endl;
	cout << "Total work days: " << DaysWork << endl;
	cout << "Days worked: " << DaysWorked << endl;
	cout << "Accurals: " << AccrualsAmount << endl;
	cout << "Deductions: " << DeductionsAmount << endl;
	PrintTotal();
	PrintSeniority();
}
