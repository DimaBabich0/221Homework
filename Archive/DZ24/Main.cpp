#include "AnimalWorld.h"

int main()
{
	//Testing africa class
	Wildebeest* wildebeest = new Wildebeest(20);
	Lion* lion = new Lion(35);
	Africa* africa = new Africa(wildebeest, lion);
	AnimalWorld p1(africa);
	p1.Cycle();
	cout << endl;

	system("pause");
	system("cls");

	//Testing north america class
	Bison* bison = new Bison;
	Wolf* wolf = new Wolf;
	NorthAmerica* northAmerica = new NorthAmerica(bison, wolf);
	AnimalWorld p2(northAmerica);
	p2.Cycle();
	cout << endl;

	system("pause");
	system("cls");

	//Testing empty class
	AnimalWorld emptyPoint;
	emptyPoint.Cycle();	
	cout << endl;
}