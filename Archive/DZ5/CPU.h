#pragma once
class CPU
{
private:
	char* model;
	double price;
	double power;
public:
	CPU();
	CPU(const char*, double, double);
	~CPU();
	CPU(const CPU&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getPower();

	void setModel(const char*);
	void setPrice(double);
	void setPower(double);
};

