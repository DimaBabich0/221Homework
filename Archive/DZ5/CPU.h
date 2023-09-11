#pragma once
class CPU
{
	char* model;
	double price;
	double power;

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	CPU();
	CPU(char*, double, double);
	~CPU();

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getPower();

	void setModel(const char*);
	void setPrice(double);
	void setPower(double);
};

