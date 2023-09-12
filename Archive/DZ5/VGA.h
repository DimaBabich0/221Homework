#pragma once
class VGA
{
private:
	char* model;
	double price;
	unsigned int memory;
public:
	VGA();
	VGA(const char*, double, unsigned int);
	~VGA();
	VGA(const VGA&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getMemory();

	void setModel(const char*);
	void setPrice(double);
	void setMemory(unsigned int);
};

