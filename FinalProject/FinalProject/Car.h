#pragma once

//#include "Vehicle.h"
#include "TrafficLight.h"

class Car
{
public:

	Car();
	~Car();

//	void moveCar();

	void deleteThis();

	void test();

	void updateCar();
private:
	int dir;
	int count;

};