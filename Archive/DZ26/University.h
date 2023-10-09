#pragma once
#include <string>
using namespace std;

class University
{
protected:
	string name;
	string adress;
	string faculty;
public:
	University() : name("empty"), adress("empty"), faculty("empty") {}
	void Input();
};

