#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include <fstream>
#include <vector>
//#include "TrafficLight.h"

class Place
{
public:
	//Loads in the contents of Place.txt to the map vector
	Place();

	//Prints out the map after it's been loaded in
	void printMap();

	//Returns a given part of the map as an int
	static int returnPlace(int x, int y);

	typedef vector<vector<int> > world;
	static world map;
	//friend TrafficLight;
private:
	
};