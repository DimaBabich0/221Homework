#pragma once
class Date
{
private:
	int day;
	int month;
	int year;

	bool isLeapYear();
	void convertUp();
	void convertDown();
public:
	Date();
	Date(int, int, int);

	void input();
	void print();

	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);

	Date operator-(Date&);
	Date operator+(int);
	Date operator-(int);

	void operator+=(int);
	void operator-=(int);

	bool operator>(Date&);
	bool operator<(Date&);
	bool operator==(Date&);
	bool operator!=(Date&);
	bool operator>=(Date&);
	bool operator<=(Date&);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
};
