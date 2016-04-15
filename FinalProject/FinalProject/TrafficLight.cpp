#include "TrafficLight.h"


TrafficLight::veh TrafficLight::vehMap;

int TrafficLight::getPlace(int x, int y)
{
	return TrafficLight::vehMap[y][x];
}

void TrafficLight::setPlace(int x, int y, int z)
{
	TrafficLight::vehMap[y][x] = z;
}


//Loads the col array with the code for red, yellow, and green
//Asks for timer settings
TrafficLight::TrafficLight(int _NSTimeG, int _EWTimeG)
{
	vehMap.resize(30, vector<int>(85, 0));

	NSTimeG = _NSTimeG;
	EWTimeG = _EWTimeG;

	NSTimeY = 15;
	EWTimeY = 25;

	NSTimeR = EWTimeY + EWTimeG;
	EWTimeR = NSTimeY + NSTimeG;

	col[0] = 4;
	col[1] = 6;
	col[2] = 2;

	NScnt = 0;
	EWcnt = 2;
}

//Prints the lights out into the console
void TrafficLight::printLights()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40, 4 + i);
		coutcharbl(col[i], 3);

		gotoxy(25 + (i * 2), 12);
		coutcharbl(col[i], 3);
	}

	for (int i = 2; i >= 0; i--)
	{
		gotoxy(40, 20 - i);
		coutcharbl(col[i], 3);

		gotoxy(55 - (i * 2), 12);
		coutcharbl(col[i], 3);
	}


}

//Used for setting the North and South lights to the off colour
void TrafficLight::NSOff()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(40, 4 + i);
		coutcharbl(col[i], 3);
	}

	for (int i = 2; i >= 0; i--)
	{
		gotoxy(40, 20 - i);
		coutcharbl(col[i], 3);
	}
}

//Used for setting the East and West lights to the off colour
void TrafficLight::EWOff()
{
	for (int i = 0; i < 3; i++)
	{
		gotoxy(25 + (i * 2), 12);
		coutcharbl(col[i], 3);
	}

	for (int i = 2; i >= 0; i--)
	{
		gotoxy(55 - (i * 2), 12);
		coutcharbl(col[i], 3);
	}
}

//Used for setting the North and South lights to green
void TrafficLight::NSGreen()
{
	NSOff();
	gotoxy(40, 6);
	coutcharbl(10, 3);
	gotoxy(40, 18);
	coutcharbl(10, 3);
	NSunBlock();
	NSCol = 'G';
}

//Used for setting the North and South lights to yellow
void TrafficLight::NSYellow()
{
	NSOff();
	gotoxy(40, 5);
	coutcharbl(14, 3);
	gotoxy(40, 19);
	coutcharbl(14, 3);
	NSblock();
	NSCol = 'Y';
}

//Used for setting the North and South lights to red
void TrafficLight::NSRed()
{
	NSOff();
	gotoxy(40, 4);
	coutcharbl(12, 3);
	gotoxy(40, 20);
	coutcharbl(12, 3);
	NSblock();
	NSCol = 'R';
}


//Used for setting the East and West lights to green
void TrafficLight::EWGreen()
{
	EWOff();
	gotoxy(29, 12);
	coutcharbl(10, 3);
	gotoxy(51, 12);
	coutcharbl(10, 3);
	EWunBlock();
	EWCol = 'G';
}

//Used for setting the East and West lights to yellow
void TrafficLight::EWYellow()
{
	EWOff();
	gotoxy(27, 12);
	coutcharbl(14, 3);
	gotoxy(53, 12);
	coutcharbl(14, 3);
	EWblock();
	EWCol = 'Y';
}

//Used for setting the East and West lights to red
void TrafficLight::EWRed()
{
	EWOff();
	gotoxy(25, 12);
	coutcharbl(12, 3);
	gotoxy(55, 12);
	coutcharbl(12, 3);
	EWblock();
	EWCol = 'R';
}

//Used for getting the colour of the East and West lights
char TrafficLight::getEWCol() const
{
	return EWCol;
}

//Used for getting the colour of the North and South lights
char TrafficLight::getNSCol() const
{
	return NSCol;
}


//Used for the update timer for timing the North and South lights
int TrafficLight::updateNSLights(int count)
{
	if (count <= NSTimeG && NScnt == 0)
	{
		NSGreen();
		if (count == NSTimeG)
		{
			NScnt++;
			return 0;
		}
	}
	else if (count <= NSTimeY && NScnt == 1)
	{
		NSYellow();
		if (count == NSTimeY)
		{
			NScnt++;
			return 0;
		}
	}
	else if (count <= NSTimeR - 1 && NScnt == 2)
	{
		NSRed();
		if (count == NSTimeR)
		{
			NScnt++;
			return 0;
		}
	}
	else
	{
		NSRed();
		NScnt = 0;
		return 0;
	}

	return count;
}

//Used for the update timer for timing the East and West lights
int TrafficLight::updateEWLights(int count)
{
	if (count <= EWTimeG && EWcnt == 0)
	{
		EWGreen();
		if (count == EWTimeG)
		{
			EWcnt++;
			return 0;
		}
	}
	else if (count <= EWTimeY && EWcnt == 1)
	{
		EWYellow();
		if (count == EWTimeY)
		{
			EWcnt++;
			return 0;
		}
	}
	else if (count <= EWTimeR - 1 && EWcnt == 2)
	{
		EWRed();
		if (count == EWTimeR)
		{
			EWcnt++;
			return 0;
		}
	}
	else
	{
		EWRed();
		EWcnt = 0;
		return 0;
	}

	return count;
}

void TrafficLight::NSblock()
{
	TrafficLight::vehMap[8][36] = 219;
	TrafficLight::vehMap[16][44] = 219;
}

void TrafficLight::NSunBlock()
{
	TrafficLight::vehMap[8][36] = 255;
	TrafficLight::vehMap[16][44] = 255;
}

void TrafficLight::EWblock()
{
	TrafficLight::vehMap[14][32] = 219;
	TrafficLight::vehMap[10][48] = 219;
}

void TrafficLight::EWunBlock()
{
	TrafficLight::vehMap[14][32] = 255;
	TrafficLight::vehMap[10][48] = 255;
}






void TrafficLight::printMap()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 80; x++)
		{

			//Goes through and defines a colour based on the character then prints the 
			//character out at the given position
			if (TrafficLight::vehMap[y][x] == 219)
			{
				gotoxy((short)x, (short)y);
				coutchar(10, 219);
			}
			else if (TrafficLight::vehMap[y][x] == 177)
			{
				gotoxy((short)x, (short)y);
				coutchar(0, 177);
			}
			else if (TrafficLight::vehMap[y][x] == 186)
			{
				gotoxy((short)x, (short)y);
				coutchar(14, 186);
			}
			else if (TrafficLight::vehMap[y][x] == 205)
			{
				gotoxy((short)x, (short)y);
				coutchar(14, 205);
			}
			else if (TrafficLight::vehMap[y][x] == 0)
			{
				gotoxy((short)x, (short)y);
				coutcharbl(0, 0);
			}
			else
			{
				gotoxy((short)x, (short)y);
				coutchar(0, TrafficLight::vehMap[y][x]);
			}
		}
	}
}