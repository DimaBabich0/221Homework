#pragma once
#include "Transport.h"

class Airplane : public Transport
{
private:
	string AirplaneType;
	int NumChassis;
public:
	Airplane();

	void Input();
	void Print() const;
};