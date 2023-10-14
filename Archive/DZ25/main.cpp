#include <iostream>
#include "Animal.h"
using namespace std;

void ñlassFly(IFly* ptr)
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
    ñlassFly(&obj);
	cout << endl;

    Airplane airplane("Boeing 777");
    ñlassFly(&airplane);
}