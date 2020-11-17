#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <list>

#include "iohandler.h"
#include "vehicle.h"
#include "environment.h"
#include "testclass.h"

int main() {

	//Run tests
	TestClass testClass;
	testClass.runTests();

	std::cout << "---Starting Program---" << std::endl;

	//Init input and output handler
	IOHandler io;

	//Input bounding parameters
	int width;
	int height;
	io.readRoomSize(width, height);

	//Create enviroment
	Environment env(width, height);

	//Input vehicle location paramaters
	int xPos;
	int yPos;
	std::string direction;
	io.readPositionAndOrientation(xPos, yPos, direction, &env);

	//Input movement sequence
	std::string moveSequence;
	io.readMoveSequence(moveSequence);

	//Create and add vehicle to the environment
	Vehicle vehicle(xPos, yPos, direction, &env);
	env.addVehicle(&vehicle);

	//Execute specified manuever 
	bool success = vehicle.executeMovement(moveSequence);
	if (success) {
		std::cout << "Vehicle did not hit the wall." << std::endl;
	} else {
		std::cout << "Vehicle did hit the wall." << std::endl;
	}

	return 0;
}

