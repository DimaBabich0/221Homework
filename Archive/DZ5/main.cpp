#include <iostream>
#include "CPU.h"
#include "SSD.h"
#include "VGA.h"
#include "RAM.h"
using namespace std;

class Laptop
{
	char* name;
	double price;
	CPU cpu;
	SSD ssd;
	VGA video;
	RAM ram;

	static unsigned int count;
};

int main()
{

}