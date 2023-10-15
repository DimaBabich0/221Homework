#include <iostream>
#include <cmath>
using namespace std;

class Square 
{
protected:
    double side;
public:
    Square(double userSide) : side(userSide) {}
    double getArea() const 
    {
        return side * side;
    }
};

class Circle 
{
protected:
    double radius;
public:
    Circle(double userRadius) : radius(userRadius) {}
    double getArea() const 
    {
        return 3.14159 * (radius * radius);
    }
};

class CircleInSquare : public Square, public Circle 
{
public:
    CircleInSquare(double userSide, double userRadius) : Square(userSide), Circle(userRadius) {}
    double getSquareArea() const 
    {
        return Square::getArea();
    }
    double getCircleArea() const 
    {
        return Circle::getArea();
    }
    bool isCircleInSquare() const 
    {
        if (2 * radius <= side*sqrt(2))
            return true;
        else
            return false;
    }
};

int main() {
    double side, radius;
    cout << "Enter the side length of the square: ";
    cin >> side;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    CircleInSquare point(side, radius);
    cout << "Area of the square: " << point.getSquareArea() << endl;
    cout << "Area of the circle: " << point.getCircleArea() << endl;
    cout << "Is circle in square: " << (point.isCircleInSquare() ? "yes" : "no") << endl;
}