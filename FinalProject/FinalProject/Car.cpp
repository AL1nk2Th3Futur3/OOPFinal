#include "Car.h"
#include "TrafficLight.h"

Car::Car()
{
	/*
	0 - West
	1 - East
	2 - North
	3 - South
	*/
	dir = rand() % 4;
	//dir = i;
	if (dir == 0)
		count = 2;
	else if (dir == 1)
		count = 80;
	else if (dir == 2)
		count = 2;
	else if (dir == 3)
		count = 25;
}

Car::~Car()
{
	delete this;
}

void Car::test()
{
	cout << dir << endl;
}

void Car::deleteThis()
{
	delete this;
}

void Car::updateCar()
{
	if (dir == 0)
	{
		if (TrafficLight::getPlace(count + 1, 14) != 219)
		{
			if (count < 80)
			{
				gotoxy(count, 14);
				coutchar(15, 219);
				TrafficLight::setPlace(count, 14, 219);
				gotoxy(count - 1, 14);
				coutchar(15, 219);
				TrafficLight::setPlace(count - 1, 14, 219);
				gotoxy(count - 2, 14);
				coutchar(15, 219);
				TrafficLight::setPlace(count - 2, 14, 219);

			}
				if (count > 2)
			{
				gotoxy(count - 3, 14);
				coutchar(0, Place::returnPlace(14,count - 3));
				TrafficLight::setPlace(count - 3, 14, 255);
				if (count == 80)
				{
					gotoxy(count - 2, 14);
					coutchar(0, Place::returnPlace(14, count - 2));
					TrafficLight::setPlace(count - 2, 14, 255);
					gotoxy(count - 1, 14);
					coutchar(0, Place::returnPlace(14, count - 1));
					TrafficLight::setPlace(count - 1, 14, 255);
				}
			}

				if (count < 80)
					count++;			

		}

	}
	else if (dir == 1)
	{
		if (TrafficLight::getPlace(count - 4, 10) != 219)
		{
			if (count > 3)
			{
				/*gotoxy(count, 10);
				coutchar(15, 219);
				TrafficLight::setPlace(count, 10, 219);*/
				gotoxy(count - 1, 10);
				coutchar(15, 219);
				TrafficLight::setPlace(count - 1, 10, 219);
				gotoxy(count - 2, 10);
				coutchar(15, 219);
				TrafficLight::setPlace(count - 2, 10, 219);
				gotoxy(count - 3, 10);
				coutchar(15, 219);
				TrafficLight::setPlace(count - 3, 10, 219);

			}
			if (count >= 3)
			{
				gotoxy(count, 10);
				coutchar(0, Place::returnPlace(10, count));
				TrafficLight::setPlace(count, 10, 255);
			}
			if (count <= 4)
			{
				gotoxy(1, 10);
				coutchar(0, Place::returnPlace(10, 1));
				TrafficLight::setPlace(1, 10, 255);
				gotoxy(2, 10);
				coutchar(0, Place::returnPlace(10, 2));
				TrafficLight::setPlace(2, 10, 255);
				gotoxy(3, 10);
				coutchar(0, Place::returnPlace(10, 3));
				TrafficLight::setPlace(3, 10, 255);

			}

			if (count > 4)
				count--;

		}
	}
	else if (dir == 2)
	{
		if (TrafficLight::getPlace(36, count + 1) != 219)
		{
			if (count < 25)
			{
				gotoxy(36, count);
				coutchar(15, 219);
				TrafficLight::setPlace(36, count, 219);
				gotoxy(36, count - 1);
				coutchar(15, 219);
				TrafficLight::setPlace(36, count - 1, 219);


				count++;
			}

			if (count > 2)
			{
				gotoxy(36, count - 3);
				coutchar(0, Place::returnPlace(count - 3, 36));
				TrafficLight::setPlace(36, count - 3, 255);
			}

			if (count == 25)
			{
				gotoxy(36, 23);
				coutchar(0, Place::returnPlace(23, 36));
				TrafficLight::setPlace(36, 23, 255);

				gotoxy(36, 24);
				coutchar(0, Place::returnPlace(24, 36));
				TrafficLight::setPlace(36, 24, 255);

			}

		}
	}
	else if (dir == 3)
	{
		if (TrafficLight::getPlace(44, count - 1 ) != 219)
		{
			if (count >= 1)
			{
				gotoxy(44, count);
				coutchar(15, 219);
				TrafficLight::setPlace(44, count, 219);

				if (count != 1)
					count--;
			}

			if (count < 23)
			{
				gotoxy(44, count + 3);
				coutchar(0, Place::returnPlace(count + 3, 44));
				TrafficLight::setPlace(44, count + 3, 255);

				gotoxy(44, 25);
				coutcharbl(0, 3);
			}
			
			if (count <= 1)
			{
				gotoxy(44, 3);
				coutchar(0, Place::returnPlace(3, 44));
				TrafficLight::setPlace(44, 3, 255);
				gotoxy(44, 2);
				coutchar(0, Place::returnPlace(2, 44));
				TrafficLight::setPlace(44, 2, 255);
				gotoxy(44, 1);
				coutchar(0, Place::returnPlace(1, 44));
				TrafficLight::setPlace(44, 1, 255);
			}
		}

		
	}
}

//void Car::moveRight(int count)
//{
//	try
//	{
//		if (Place::map[14][count] == 255)
//		{
//			
//				gotoxy(count, 14);
//				coutchar(15, 219);
//				gotoxy(count - 1, 14);
//				coutchar(15, 219);
//				gotoxy(count - 2, 14);
//				coutchar(15, 219);
//
//				if (count > 2)
//				{
//					gotoxy(count - 3, 14);
//					coutchar(0, Place::map[14][count - 3]);
//				}
//			
//			
//		}
//		else if (Place::map[14][count] == 219)
//		{
//
//		}
//	}
//	catch (...)
//	{
//	}
//}