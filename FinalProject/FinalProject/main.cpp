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
#include <string>

//Currently used for testing purposes only
int main()
{
	srand(time(0));

	int NSTimer, EWTimer;
	cout << "Enter the timer for the North/South green lights: " << endl;
	cin >> NSTimer;
	cout << "Enter the timer for the East/West green lights: " << endl;
	cin >> EWTimer;
	Place a;
	TrafficLight l(NSTimer, EWTimer);

	a.printMap();
	l.printLights();

	//l.test();
	
	vector<Car> test;
	test.resize(50);
	//test.push_back(temp);
	//test.push_back(temp2);
	//test[0].test();

	/*for (int i = 0; i < 80; i++)
	{
		
	}*/



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
			test[w].updateCar();

			if ((rand() % 50) == 1 && i != 49)
			{
				i++;
			}
		}

		gotoxy(0, 26);
		coutc(15, i);




		/*tempW.updateCar();
		tempE.updateCar();
		tempN.updateCar();
		tempS.updateCar();*/

		Sleep(100);
		//a.printMap();
	}

	l.printMap();

	//while (true)
	//{
	//	for (int i = 0; i < 80; i++)
	//	{

	//		//a.printMap();
	//		gotoxy(i, 14);
	//		coutchar(15, 219);
	//		if (i + 1 < 80)
	//		{
	//			gotoxy(i + 1, 14);
	//			coutchar(15, 219);
	//		}
	//		if (i + 2 < 80)
	//		{
	//			gotoxy(i + 2, 14);
	//			coutchar(15, 219);
	//		}

	//		/*gotoxy(37, i % 25);
	//		coutchar(15, 219);
	//		if (i + 1 < 25)
	//		{
	//			gotoxy(37, (i + 1) % 25);
	//			coutchar(15, 219);
	//		}*/
	//		

	//		Sleep(100);
	//		gotoxy(i, 14);
	//		coutchar(0, a.returnPlace(14, i));

	//		/*gotoxy(37, i % 25);
	//		coutchar(15, a.returnPlace(i % 25, 37));*/
	//	}
	//}
			
	gotoxy(0, 25);
	system("pause");
	return 0;
}
