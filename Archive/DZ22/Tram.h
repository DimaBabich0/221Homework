#pragma once
#include "Transport.h"

class Tram : public Transport
{
private:
	int NumberWagons;
public:
	Tram();

	void Input();
	void Print() const;
};