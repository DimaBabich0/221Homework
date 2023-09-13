#pragma once
const int SIZE_PHONE = 11;
class Caller
{
private:
	char* firstName;
	char* lastName;
	int age;
	char* email;
	char workPhone[SIZE_PHONE];
	char mobilePhone[SIZE_PHONE];

	void deleteNullPtr(char*);
	void coutVariable(char*);
public:
	Caller();
	Caller(const char*, const char*, int, const char*, const char[], const char[]);
	~Caller();
	void deepCopy(const Caller&);

	void input();
	void print();

	char* getFirstName() const;
	char* getLastName() const;
};