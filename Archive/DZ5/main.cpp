#include <iostream>
#include "main.h"
#include "Laptop.h"
#include "CPU.h"
#include "SSD.h"
#include "VGA.h"
#include "RAM.h"
using namespace std;

//static int
unsigned int Laptop::s_count = 0;

int main()
{
	//Laptop number 1 (using constuctor)
	CPU cpu("AMD Ryzen 5 3600", 3399, 3.6);
	SSD ssd("Kingston A400", 1819, 960);
	VGA vga("GeForce RTX 3060TI", 13500, 8000);
	RAM ram("Kingston Fury DDR4-3200", 3099, 32000);
	Laptop Asus("ASUS TUF Gaming F15", 32499, "Grey", cpu, ssd, vga, ram);
	Asus.print();
	clearConsole();

	//Laptop number 2 (using class methods)
	Laptop point;
	point.print();
	clearConsole();
	point.input();
	clearConsole();
	point.print();
	clearConsole();

	//Laptop number 3 (using copy constuctor)
	Laptop copyPoint = Asus;
	copyPoint.print();
	clearConsole();

	//Print static number
	cout << "Number of laptops: " << Laptop::getStatic();
}

void clearConsole()
{
	system("pause");
	system("cls");
}
void deleteNullPtr(char* pointer)
{
	if (pointer != nullptr)
		delete[] pointer;
}
void coutVariable(char* variable)
{
	if (variable == nullptr)
		cout << "empty" << endl;
	else
		cout << variable << endl;
}