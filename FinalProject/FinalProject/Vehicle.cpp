#include "Vehicle.h"

static Vehicle::veh vehMap;

Vehicle::Vehicle()
{
	vehMap.resize(25, vector<int>(80, 0));
}