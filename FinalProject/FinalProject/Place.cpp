#include "Place.h"

Place::Place()
{
	map.resize(25, vector<int>(80, 0));

	ifstream load("Place.txt");
	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < 80; i++)
		{
			load >> map[j][i];
		}
	}
}


int Place::returnPlace(int x, int y)
{
	return map[x][y];
}


void Place::printMap()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			
			if (map[y][x] == 219)
			{
				gotoxy((short)x, (short)y);
				coutchar(10, 219);
			}
			else if (map[y][x] == 177)
			{
				gotoxy((short)x, (short)y);
				coutchar(8, 177);
			}
			else if (map[y][x] == 186)
			{
				gotoxy((short)x, (short)y);
				coutchar(6, 186);
			}
			else if (map[y][x] == 205)
			{
				gotoxy((short)x, (short)y);
				coutchar(6, 205);
			}
			else
			{
				gotoxy((short)x, (short)y);
				coutchar(15, map[y][x]);
			}
		}
	}
}
