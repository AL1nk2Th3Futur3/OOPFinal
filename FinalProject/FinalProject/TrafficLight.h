#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include "Place.h"
#include <vector>
//#include "Vehicle.h"

class TrafficLight
{
public:
	//Loads the col array with the code for red, yellow, and green
	TrafficLight(int, int);

	//Prints the lights out into the console
	void printLights();

	//Used for setting the North and South light colours
	void NSGreen();
	void NSYellow();
	void NSRed();

	//Used for setting the East and West light colours
	void EWGreen();
	void EWYellow();
	void EWRed();
	
	//Returns the currently set colour of either the North and South or the East and West lights
	char getNSCol() const;
	char getEWCol() const;

	//Used for the update timer for timing the lights
	int updateNSLights(int);
	int updateEWLights(int);

	//Used for placing and removing the vehicle block
	void NSblock();
	void NSunBlock();
	void EWblock();
	void EWunBlock();

	typedef vector<vector<int> > veh;
//	friend Car;
	static veh vehMap;
	static int getPlace(int,int);
	static void setPlace(int, int, int);
	//veh& getPlace();


	void printMap();



private:
	int col[3];
	int NSTimeG, NSTimeY, NSTimeR;
	int EWTimeG, EWTimeY, EWTimeR;
	int NScnt, EWcnt;
	char NSCol;
	char EWCol;
	Place map;
	
	//Used to set the North and South or the East and West lights off
	void NSOff();
	void EWOff();
};