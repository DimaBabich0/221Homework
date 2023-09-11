#pragma once
class VGA
{
	char* model;
	double price;
	unsigned int memory;

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	VGA();
	VGA(char*, double, unsigned int);
	~VGA();

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getMemory();

	void setModel(const char*);
	void setPrice(double);
	void setMemory(unsigned int);
};

