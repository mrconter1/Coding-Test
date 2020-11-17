#ifndef VEHICLE_H
#define VEHICLE_H

#define _USE_MATH_DEFINES

#include <string>

class Environment;

//Vehicle class of which instances can be added to environment
class Vehicle {

	public: 

		int xPos, yPos, dir;
		Environment* env;

		Vehicle(int x, int y, std::string d, Environment* envIn);

		//Executes movements given a set of characters
		//Returns true if not hitting wall
		bool executeMovement(std::string instructions);

		//Changes the direction of the vehicle
		void setDirection(std::string dirIn);

		//Moves vehicle one step given an valid action
		void move(std::string action);

};

#endif
