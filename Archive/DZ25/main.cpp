#include <iostream>
#include "Animal.h"
using namespace std;

void �lassFly(IFly* ptr)
{
	ptr->Fly();
}

int main()
{
	Parrot obj("Jack", 17, "Australia");
    Animal* parrot = &obj;
	parrot->Print();
	parrot->Continent();
	parrot->Eat();
    �lassFly(&obj);
	cout << endl;

    Airplane airplane("Boeing 777");
    �lassFly(&airplane);
}