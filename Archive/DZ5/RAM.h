#pragma once
class RAM
{
private:
	char* model;
	double price;
	unsigned int storage;
public:
	RAM();
	RAM(const char*, double, unsigned int);
	~RAM();
	RAM(const RAM&);

	void input();
	void print();

	char* getModel();
	double getPrice();
	double getStorage();

	void setModel(const char*);
	void setPrice(double);
	void setStorage(unsigned int);
};

