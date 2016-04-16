#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include <fstream>
#include "Place.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <string>

//Currently used for testing purposes only
int main()
{
	srand(time(0));

	int NSTimer, EWTimer, carCount, probChance;
	cout << "Enter the timer for the North/South green lights: " << endl;
	cin >> NSTimer;
	cout << "Enter the timer for the East/West green lights: " << endl;
	cin >> EWTimer;
	cout << "Enter the amount of cars you want to simulate: " << endl;
	cin >> carCount;
	cout << "Enter the probabilty of a new car entering the intersection (1/n): " << endl;
	cin >> probChance;
	Place a;
	TrafficLight l(NSTimer, EWTimer);

	a.printMap();
	l.printLights();

	
	//Vehicle * v = &


	vector<Vehicle*> veh;
	int e;
	for (int k = 0; k < carCount; k++)
	{
		e = rand();

		if ((e % 4) == 1)
			veh.push_back(new Car());
		else if ((e % 4) == 2)
			veh.push_back(new Car());
		else if ((e % 4) == 3)
			veh.push_back(new Car());
		else if ((e % 4) == 0)
			veh.push_back(new Truck());

		gotoxy(10, 26);
		coutc(15, k);
	}
	//test.resize(carCount);



	int NScount = 0;
	int EWcount = 0;
	int i = 1;
	int w = 0;

	while (true){
		

		NScount = l.updateNSLights(NScount);
		EWcount = l.updateEWLights(EWcount);
		NScount++;
		EWcount++;

		

		
		for (w = 0; w < i; w++)
		{
			veh[w]->updateVehicle();
		}

		if ((rand() % probChance) == 1 && i != (carCount - 1))
		{
			i++;
		}
		
		gotoxy(0, 26);
		coutc(15, i);




		Sleep(100);
	}

	l.printMap();

			
	gotoxy(0, 25);
	system("pause");
	return 0;
}
