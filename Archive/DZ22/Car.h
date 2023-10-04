#pragma once
#include "Transport.h"

class Car : public Transport
{
private:
	int NumWheels;
public:
	Car();

	void Input();
	void Print() const;
};