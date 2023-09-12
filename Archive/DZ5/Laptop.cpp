#include <iostream>
#include "Laptop.h"
#include "CPU.h"
#include "SSD.h"
#include "VGA.h"
#include "RAM.h"
#include "main.h"
using namespace std;

Laptop::Laptop()
{
	this->model = nullptr;
	this->price = NULL;
	this->priceComponents = NULL;
	this->color = nullptr;
	this->cpu;
	this->ssd;
	this->vga;
	this->ram;
	plusStatic();
}
Laptop::Laptop(const char* userModel, double userPrice, const char* userColor, CPU userCpu, SSD userSsd, VGA userVga, RAM userRam) :cpu(userCpu), ssd(userSsd), vga(userVga), ram(userRam)
{
	this->model = new char[strlen(userModel) + 1];
	strcpy_s(this->model, strlen(userModel) + 1, userModel);

	this->price = userPrice;

	this->color = new char[strlen(userColor) + 1];
	strcpy_s(this->color, strlen(userColor) + 1, userColor);
	calcComponentPrice();
	plusStatic();
}
Laptop::~Laptop()
{
	delete[]this->model;
	delete[]this->color;
}
Laptop::Laptop(const Laptop& point)
{
	this->model = new char[strlen(point.model) + 1];
	strcpy_s(this->model, strlen(point.model) + 1, point.model);

	this->price = point.price;
	this->priceComponents = point.priceComponents;

	this->color = new char[strlen(point.color) + 1];
	strcpy_s(this->color, strlen(point.color) + 1, point.color);

	this->cpu = point.cpu;
	this->ssd = point.ssd;
	this->vga = point.vga;
	this->ram = point.ram;
}

void Laptop::input()
{
	char buff[30];

	deleteNullPtr(this->model);
	deleteNullPtr(this->color);

	cout << "Enter model: ";
	cin >> buff;
	this->model = new char[strlen(buff) + 1];
	strcpy_s(this->model, strlen(buff) + 1, buff);

	cout << "Enter price: ";
	cin >> this->price;

	cout << "Enter color: ";
	cin >> buff;
	this->color = new char[strlen(buff) + 1];
	strcpy_s(this->color, strlen(buff) + 1, buff);

	cout << "\nCPU: " << endl;
	this->cpu.input();
	cout << "\nSSD: " << endl;
	this->ssd.input();
	cout << "\nVGA: " << endl;
	this->vga.input();
	cout << "\nRAM: " << endl;
	this->ram.input();

	calcComponentPrice();
}
void Laptop::print()
{
	cout << "\tInfo about laptop: " << endl;
	cout << "Model: ";
	coutVariable(this->model);
	cout << "Price: " << this->price << endl;
	cout << "Price all components: " << this->priceComponents << endl;
	cout << "Color: ";
	coutVariable(this->color);

	cout << "\tList of components: " << endl;
	cout << "CPU:" << endl;
	cpu.print();
	cout << "\nSSD:" << endl;
	ssd.print();
	cout << "\nVGA:" << endl;
	vga.print();
	cout << "\nRAM:" << endl;
	ram.print();
}
void Laptop::printCPU()
{
	cout << "CPU:" << endl;
	cpu.print();
}
void Laptop::printSSD()
{
	cout << "\nSSD:" << endl;
	ssd.print();
}
void Laptop::printVGA()
{
	cout << "\nVGA:" << endl;
	vga.print();
}
void Laptop::printRAM()
{
	cout << "\nRAM:" << endl;
	ram.print();
}
void Laptop::calcComponentPrice()
{
	this->priceComponents += cpu.getPrice();
	this->priceComponents += ssd.getPrice();
	this->priceComponents += vga.getPrice();
	this->priceComponents += ram.getPrice();
}

int Laptop::getStatic()
{
	return Laptop::s_count;
}
void Laptop::setStatic(int num)
{
	Laptop::s_count = num;
}
void Laptop::plusStatic()
{
	Laptop::s_count++;
}