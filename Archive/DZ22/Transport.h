#pragma once
#include <string>
using namespace std;

class Transport
{
protected:
    string Model;
    double Speed;
    double Weight;
    string FuelType;
    int TankCapacity;
    int PassengerCapacity;
    int CarryingCapacity;
public:
    Transport();

    virtual void Input();
    virtual void Print() const;

    string GetFuelType() const;
    void SetFuelType(const char* u_FuelType);
};