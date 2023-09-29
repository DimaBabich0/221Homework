#include "Point.h"
#include <iostream>
using namespace std;

Point Point::operator+(const Point& point)
{
	return Point(x + point.x, y + point.y);
}
Point Point::operator-(const Point& point)
{
	return Point(x - point.x, y - point.y);
}
Point Point::operator*(const Point& point)
{
	return Point(x * point.x, y * point.y);
}
Point Point::operator/(const Point& point)
{
	return Point(x / point.x, y / point.y);
}

bool Point::operator>(const Point& point)
{
	return (x > point.x && y > point.y) ? true : false;
}
bool Point::operator<(const Point& point)
{
	return (x < point.x && y < point.y) ? true : false;
}

int Point::GetX() const
{
	return x;
}
int Point::GetY() const
{
	return y;
}
void Point::SetX(int userX)
{
	x = userX;
}
void Point::SetY(int userY)
{
	y = userY;
}

ostream& operator<<(ostream& os, const Point& point)
{
	os << point.GetX() << "|" << point.GetY();
	return os;
}
istream& operator>>(istream& is, Point& point)
{
	int temp;
	cout << "Enter X and Y: ";
	cin >> temp;
	point.SetX(temp);
	cin >> temp;
	point.SetY(temp);
	return is;
}