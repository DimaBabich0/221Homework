#pragma once
#include "Transport.h"

class Motorcycle : public Transport
{
private:
	int NumWheels;
public:
	Motorcycle();

	void Input();
	void Print() const;
};