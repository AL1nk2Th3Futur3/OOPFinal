#include "TrafficLight.h"

//Loads the col array with the code for red, yellow, and green
TrafficLight::TrafficLight()
{
	col[0] = 4;
	col[1] = 6;
	col[2] = 2;
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


//Used for the update timer for timing the lights
void TrafficLight::updateLights(int count)
{

}