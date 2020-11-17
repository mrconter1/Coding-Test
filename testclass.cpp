#include <list>
#include <string>
#include <iostream>

#include "environment.h"
#include "vehicle.h"
#include "testclass.h"

void TestClass::runTests() {

	std::cout << "---Running tests---" << std::endl;

	TestClass::testNavigation_executeMovement_shouldReachDestination();
	TestClass::testHittingWall_executeMovement_shouldHitWall();
	TestClass::testHittingWall_executeMovement_shouldNotHitWall();

	std::cout << std::endl;

}

void TestClass::printer(std::string message, bool condition, bool expectedOutcome) {

	std::cout << message;
	std::cout << " ";

	if (!expectedOutcome)
		condition = !condition;

	if (condition) {
		std::cout << "passed." << std::endl;
	} else {
		std::cout << "failed." << std::endl;
	}

}

void TestClass::testNavigation_executeMovement_shouldReachDestination() {

	Environment env(16, 15);
	Vehicle vehicle(5, 5, "W", &env);
	env.addVehicle(&vehicle);
	vehicle.executeMovement("FFLBLFFFRRB");

	printer("Test navigation", vehicle.xPos == 7 && vehicle.yPos == 6, true);

}

void TestClass::testHittingWall_executeMovement_shouldHitWall() {

	Environment env(4, 4);
	Vehicle vehicle(2, 2, "N", &env);
	env.addVehicle(&vehicle);
	printer("Test hit wall", vehicle.executeMovement("FFF"), false);

}

void TestClass::testHittingWall_executeMovement_shouldNotHitWall() {

	Environment env(5, 5);
	Vehicle vehicle(1, 1, "E", &env);
	env.addVehicle(&vehicle);
	printer("Test not hit wall", vehicle.executeMovement("FFLFF"), true);

}

