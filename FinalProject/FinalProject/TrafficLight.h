#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"

class TrafficLight
{
public:
	//Loads the col array with the code for red, yellow, and green
	TrafficLight();

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
	void updateLights(int);

private:
	int col[3];
	//int count;
	char NSCol;
	char EWCol;
	
	//Used to set the North and South or the East and West lights off
	void NSOff();
	void EWOff();
};