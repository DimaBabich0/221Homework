#include "Date.h"
#include <iostream>
using namespace std;
const int CONVERT_DAY = 29;

Date::Date()
{
	day = NULL;
	month = NULL;
	year = NULL;
}
Date::Date(int userDay, int userMonth, int userYear)
{
	day = userDay;
	month = userMonth;
	year = userYear;
	convertUp();
}

bool Date::isLeapYear()
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
void Date::convertUp()
{
	const int month30Day[4] = { 4, 6, 9, 11 };
	const int month31Day[7] = { 1, 3, 5, 7, 8, 10, 12 };
	bool is30DayMonth = false;
	bool is31DayMonth = false;

	while (month > 12)
	{
		month -= 12;
		year++;
	}

	while (day >= CONVERT_DAY)
	{
		for (int i = 0; i < 7; i++)
		{
			if (month == month30Day[i])
			{
				is30DayMonth = true;
				break;
			}
			if (month == month31Day[i])
			{
				is31DayMonth = true;
				break;
			}
		}

		if (is30DayMonth == true)
		{
			if (day <= 30)
				break;
			day -= 30;
			is30DayMonth = false;
		}
		else if (is31DayMonth == true)
		{
			if (day <= 31)
				break;
			day -= 31;
			is31DayMonth = false;
		}
		else if (is30DayMonth == false && is31DayMonth == false)
		{
			if (isLeapYear() == true)
			{
				if (day == 29)
					break;
				else
					day -= 29;
			}
			else
			{
				if (day <= 28)
					break;
				day -= 28;
			}
		}
		month++;

		if (month > 12)
		{
			month -= 12;
			year++;
		}
	}
}
void Date::convertDown()
{
	const int month30Day[4] = { 4, 6, 9, 11 };
	const int month31Day[7] = { 1, 3, 5, 7, 8, 10, 12 };
	bool is30DayMonth = false;
	bool is31DayMonth = false;

	while (month < 1)
	{
		month += 12;
		year--;
	}

	while (day <= NULL)
	{
		for (int i = 0; i < 7; i++)
		{
			if (month == month30Day[i])
			{
				is30DayMonth = true;
				break;
			}
			if (month == month31Day[i])
			{
				is31DayMonth = true;
				break;
			}
		}

		if (is30DayMonth == true)
		{
			day += 30;
			is30DayMonth = false;
		}
		else if (is31DayMonth == true)
		{
			day += 31;
			is31DayMonth = false;
		}
		else if (is30DayMonth == false && is31DayMonth == false)
		{
			if (isLeapYear() == true)
			{
				day += 29;
			}
			else
			{
				day += 28;
			}
		}
		month--;

		while (month < 1)
		{
			month += 12;
			year--;
		}
	}

}

void Date::input()
{
	cout << "Enter day number: ";
	cin >> day;
	cout << "Enter month number: ";
	cin >> month;
	cout << "Enter year number: ";
	cin >> year;
	convertUp();
	convertDown(); 
}
void Date::print()
{
	cout << day << "/" << month << "/" << year << endl;
}

Date& Date::operator++()
{
	day++;
	convertUp();
	return *this;
}
Date& Date::operator--()
{
	day--;
	convertDown();
	return *this;
}
Date Date::operator++(int)
{
	Date temp(day, month, year);

	day++;
	convertUp();

	return temp;
}
Date Date::operator--(int)
{
	Date temp(day, month, year);
	
	day--;
	convertDown();

	return temp;
}

Date Date::operator-(Date& point)
{
	year -= point.year;
	month -= point.month;
	day -= point.day;
	convertDown();
	return *this;
}
Date Date::operator+(int numDays)
{
	day += numDays;
	convertUp();
	return *this;
}
Date Date::operator-(int numDays)
{
	day -= numDays;
	convertDown();
	return *this;
}

void Date::operator+=(int numDays)
{
	day += numDays;
	convertUp();
}
void Date::operator-=(int numDays)
{
	day -= numDays;
	convertDown();
}

bool Date::operator>(Date& point)
{
	return (year > point.year) ? true : false;
	return (month > point.month) ? true : false;
	return (day > point.day) ? true : false;
	return false;
}
bool Date::operator<(Date& point)
{
	return (year < point.year) ? true : false;
	return (month < point.month) ? true : false;
	return (day < point.day) ? true : false;
	return false;
}
bool Date::operator==(Date& point)
{
	if (year == point.year)
		if (month == point.month)
			if (day == point.day)
				return true;
	return false;
}
bool Date::operator!=(Date& point)
{
	if (year != point.year)
		if (month != point.month)
			if (day != point.day)
				return false;
	return true;
}
bool Date::operator>=(Date& point)
{
	if ((*this > point) == true || (*this == point) == true)
		return true;
	return false;
}
bool Date::operator<=(Date& point)
{
	if ((*this < point) == true || (*this == point) == true)
		return true;
	return false;
}

int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::setDay(int num)
{
	day = num;
	convertUp();
}
void Date::setMonth(int num)
{
	month = num;
	convertUp();
}
void Date::setYear(int num)
{
	year = num;
}