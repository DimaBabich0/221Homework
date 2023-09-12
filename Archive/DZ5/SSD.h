#pragma once
class SSD
{
private:
	char* model;
	double price;
	unsigned int storage;
public:
	SSD();
	SSD(const char*, double, unsigned int);
	~SSD();
	SSD(const SSD&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getStorage();

	void setModel(const char*);
	void setPrice(double);
	void setStorage(unsigned int);
};

