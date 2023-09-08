#pragma once
class Car
{
private:
	char* model;
	char* color;
	int year;
	double price;

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	Car();
	Car(const char*, const char*, int, double);
	~Car();

	void input();
	void print();

	char* getModel();
	char* getColor();
	int getYear();
	double getPrice();

	void setModel(const char*);
	void setColor(const char*);
	void setYear(int);
	void setPrice(double);
};

