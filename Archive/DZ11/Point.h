#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int x = 0;
	int y = 0;
public:
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}
	Point& operator=(int num)
	{
		x += num;
		y += num;
		return *this;
	}

	Point operator+(const Point& point);
	Point operator-(const Point& point);
	Point operator*(const Point& point);
	Point operator/(const Point& point);

	bool operator>(const Point& point);
	bool operator<(const Point& point);

	int GetX() const;
	int GetY() const;
	void SetX(int userX);
	void SetY(int userY);
};

ostream& operator<<(ostream& os, const Point& point);
istream& operator>>(istream& is, Point& point);