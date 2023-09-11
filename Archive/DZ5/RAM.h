#pragma once
class RAM
{
	char* model;
	double price;
	unsigned int storage;

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	RAM();
	RAM(char*, double, unsigned int);
	~RAM();

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getStorage();

	void setModel(const char*);
	void setPrice(double);
	void setStorage(unsigned int);
};

