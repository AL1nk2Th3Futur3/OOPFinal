#include "Truck.h"
#include "TrafficLight.h"

Truck::Truck()
{
	/*
	0 - West
	1 - East
	2 - North
	3 - South
	*/
	colour = rand() % 16;
	if (colour == 8)
		colour = 15;

	dir = rand() % 4;
	if (dir == 0)
		count = 9;
	else if (dir == 1)
		count = 79;
	else if (dir == 2)
		count = 4;
	else if (dir == 3)
		count = 25;
}

Truck::~Truck()
{
	delete this;
}


void Truck::updateVehicle()
{
	if (dir == 0 && count != 81)
	{
		if (TrafficLight::getPlace(count + 1, 14) != 219)
		{
			if (count < 80)
			{
				for (int i = 0; i < 5; i++)
				{
					gotoxy(count-i, 14);
					coutchar(colour, 219);
					TrafficLight::setPlace(count-1, 14, 219);
				}

			}
			if (count > 2)
			{
				gotoxy(count - 8, 14);
				coutchar(0, Place::returnPlace(14, count - 8));
				TrafficLight::setPlace(count - 8, 14, 255);

				if (count == 80)
				{
					for (int i = 0; i < 8; i++)
					{
						gotoxy(80-i, 14);
						coutchar(0, Place::returnPlace(14, 80-i));
						TrafficLight::setPlace(80-i, 14, 255);
					}
				}
			}

			if (count < 80)
				count++;

		}

	}
	else if (dir == 1 && count != 3)
	{
		if (TrafficLight::getPlace(count - 4, 10) != 219)
		{
			if (count > 3)
			{

				gotoxy(count, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count, 10, 219);
				gotoxy(count - 1, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 1, 10, 219);
				gotoxy(count - 2, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 2, 10, 219);
				gotoxy(count - 3, 10);
				coutchar(colour, 219);
				TrafficLight::setPlace(count - 3, 10, 219);

			}
			if (count >= 3)
			{
				gotoxy(count + 5, 10);
				coutchar(0, Place::returnPlace(10, count + 5));
				TrafficLight::setPlace(count + 5, 10, 255);
			}
			if (count <= 4)
			{
				for (int i = 1; i < 9; i++)
				{
					gotoxy(i, 10);
					coutchar(0, Place::returnPlace(10, i));
					TrafficLight::setPlace(i, 10, 255);
				}


			}

			if (count >= 4)
				count--;

		}
	}
	else if (dir == 2 && count != 25)
	{
		if (TrafficLight::getPlace(36, count + 1) != 219)
		{
			if (count < 25)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoxy(36, count-i);
					coutchar(colour, 219);
					TrafficLight::setPlace(36, count-i, 219);
				}

				count++;
			}

			if (count > 2)
			{
				gotoxy(36, count - 5);
				coutchar(0, Place::returnPlace(count - 5, 36));
				TrafficLight::setPlace(36, count - 5, 255);
			}

			if (count == 25)
			{
				for (int i = 0; i < 4; i++)
				{
					gotoxy(36, 24 - i);
					coutchar(0, Place::returnPlace(24-i, 36));
					TrafficLight::setPlace(36, 24-i, 255);
				}
			}

		}
	}
	else if (dir == 3 && count != 1)
	{
		if (TrafficLight::getPlace(44, count - 1) != 219)
		{
			if (count >= 1)
			{
				gotoxy(44, count);
				coutchar(colour, 219);
				TrafficLight::setPlace(44, count, 219);

				if (count != 1)
					count--;
			}

			if (count < 22)
			{
				gotoxy(44, count + 5);
				coutchar(0, Place::returnPlace(count + 5, 44));
				TrafficLight::setPlace(44, count + 5, 255);

			}

			if (count <= 1)
			{
				for (int i = 0; i < 7; i++)
				{
					gotoxy(44, i);
					coutchar(0, Place::returnPlace(i, 44));
					TrafficLight::setPlace(44, i, 255);
				}
			}


			gotoxy(44, 25);
			coutcharbl(0, 3);
			gotoxy(44, 26);
			coutcharbl(0, 3);
		}


	}
}

