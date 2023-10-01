#include <iostream>
#include "Payment.h"
using namespace std;

int main()
{
	Payment point("Dmitry", "Babich", "Evgenievich", 2021, 5, 19, 20, 10000);
	point.PrintAllInfo();
}