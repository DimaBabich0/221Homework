#pragma once
#include "CPU.h"
#include "SSD.h"
#include "VGA.h"
#include "RAM.h"
class Laptop
{
private:
	char* model;
	double price;
	double priceComponents;
	char* color;
	CPU cpu;
	SSD ssd;
	VGA vga;
	RAM ram;
	static unsigned int s_count;
public:
	Laptop();
	Laptop(const char*, double, const char*, CPU, SSD, VGA, RAM);
	~Laptop();
	Laptop(const Laptop&);

	void input();
	void print();
	void printCPU();
	void printSSD();
	void printVGA();
	void printRAM();
	void calcComponentPrice();

	static int getStatic();
	static void setStatic(int num);
	static void plusStatic();
};