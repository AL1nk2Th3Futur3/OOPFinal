#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include <vector>

class Vehicle
{
public:
	Vehicle();
	//~Vehicle();

	void move();

	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

	typedef vector<vector<int> > veh;
	//static veh vehMap;

private:

};