#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction()
	{
		numerator = 1;
		denominator = 1;
	}
	Fraction(int num1, int num2)
	{
		numerator = num1;
		if (num2 != 0)
			denominator = num2;
		else
			denominator = 1;
	}
	void init(int num1, int num2)
	{
		numerator = num1;
		if (num2 != 0)
			denominator = num2;
	}
	void print()
	{
		cout << "Fraction: " << numerator << "/" << denominator << endl;
	}
	void reduce()
	{
		int num1 = numerator;
		int num2 = denominator;

		while (num2 != 0)
		{
			int temp = num2;
			num2 = num1 % num2;
			num1 = temp;
		}

		numerator /= num1;
		denominator /= num1;
	}

	void addition(Fraction point)
	{
		Fraction result;
		result.numerator = (numerator * point.denominator) + (point.numerator * denominator);
		result.denominator = denominator * point.denominator;
		result.reduce();
		result.print();
	}
	void subtraction(Fraction point)
	{
		Fraction result;
		result.numerator = (numerator * point.denominator) - (point.numerator * denominator);
		result.denominator = denominator * point.denominator;
		result.reduce();
		result.print();
	}
	void multiplication(Fraction point)
	{
		Fraction result;
		result.numerator = numerator * point.numerator;
		result.denominator = denominator * point.denominator;
		result.reduce();
		result.print();
	}
	void division(Fraction point)
	{
		Fraction result;
		result.numerator = numerator * point.denominator;
		result.denominator = denominator * point.numerator;
		result.reduce();
		result.print();
	}

	void setNumerator(int num)
	{
		numerator = num;
	}
	void setDenominator(int num)
	{
		if (num != 0)
			denominator = num;
	}
	int getNumerator()
	{
		return numerator;
	}
	int getDenominator()
	{
		return denominator;
	}
};

int main()
{
	Fraction point1(3, 5);
	Fraction point2(2, 7);

	point1.addition(point2);
	point1.subtraction(point2);
	point1.multiplication(point2);
	point1.division(point2);
}