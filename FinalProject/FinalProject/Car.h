#pragma once

#include "Vehicle.h"
#include "TrafficLight.h"

class Car : public Vehicle
{
public:

	Car();
	~Car();


	virtual void updateVehicle();


private:
	int dir;
	int count;
	int colour;

};