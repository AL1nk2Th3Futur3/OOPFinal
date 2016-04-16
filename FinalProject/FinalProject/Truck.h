#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include "Vehicle.h"
#include <fstream>
#include <vector>

class Truck : public Vehicle
{
public:

	Truck();
	~Truck();
	virtual void updateVehicle();

private:
	int dir;
	int count;
	int colour;
};