#include <vector>
#include <list>

#include "environment.h"

Environment::Environment(int w, int h) {
	width = w;
	height = h;
}

void Environment::addVehicle(Vehicle* vehicle) {
	vehicles.insert(vehicles.begin(), vehicle);
}

