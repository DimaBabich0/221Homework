#pragma once
#include <string>
#include <iostream>
using namespace std;
class Human
{
protected:
	string name;
	unsigned int age;
public:
	Human() : name("empty"), age(NULL) {}
	void Input();
};