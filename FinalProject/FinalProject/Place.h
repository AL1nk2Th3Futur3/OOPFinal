#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;
#include <windows.h>
#include "functions.h"
#include <fstream>
#include <vector>

class Place
{
public:
	Place();


	void printMap();

	vector<vector<int> >* returnMap();

	int returnPlace(int x, int y);

private:
	vector<vector<int> > map;
	//int map[25][80];
};