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


int main()
{

	Place a;

	a.printMap();

	while (true)
	{
		for (int i = 0; i < 80; i++)
		{

			//a.printMap();
			gotoxy(i, 14);
			coutchar(15, 219);
			if (i + 1 < 80)
			{
				gotoxy(i + 1, 14);
				coutchar(15, 219);
			}
			if (i + 2 < 80)
			{
				gotoxy(i + 2, 14);
				coutchar(15, 219);
			}

			/*gotoxy(37, i % 25);
			coutchar(15, 219);
			if (i + 1 < 25)
			{
				gotoxy(37, (i + 1) % 25);
				coutchar(15, 219);
			}*/
			

			Sleep(100);
			gotoxy(i, 14);
			coutchar(15, a.returnPlace(14, i));

			/*gotoxy(37, i % 25);
			coutchar(15, a.returnPlace(i % 25, 37));*/
		}
	}
			
	system("pause");
	return 0;
}
