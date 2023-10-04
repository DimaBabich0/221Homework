#pragma once
#include "Transport.h"

class Boat : public Transport
{
private:
	string ShipType;
public:
	Boat();

	void Input();
	void Print() const;
};