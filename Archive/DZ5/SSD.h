#pragma once
class SSD
{
	char* model;
	double price;
	unsigned int storage;

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	SSD();
	SSD(char*, double, unsigned int);
	~SSD();

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getStorage();

	void setModel(const char*);
	void setPrice(double);
	void setStorage(unsigned int);
};

