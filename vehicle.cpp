#include <list>
#include <string>
#include <math.h>       

#include "environment.h"
#include "vehicle.h"

Vehicle::Vehicle(int x, int y, std::string d, Environment* envIn) {
	xPos = x;
	yPos = y;
	env = envIn;
	setDirection(d);
}

//Executes movements given a set of characters
//Returns true if not hitting wall
bool Vehicle::executeMovement(std::string instructions) {

	int lastX, lastY;
	for(char& c : instructions) {
		lastX = xPos;
		lastY = yPos;
		std::string s(1, c);
		move(s);
		if (!(xPos >= 0 && yPos >= 0 && xPos < env->width && yPos < env->height)) {
			xPos = lastX;
			yPos = lastY;
			return false;
		}
	}
	return true;

}


//Changes the direction of the vehicle
void Vehicle::setDirection(std::string dirIn) {

	if (!dirIn.compare("N")) {
		dir = 90;
	} else if (!dirIn.compare("W")) {
		dir = 180;
	} else if (!dirIn.compare("S")) {
		dir = 270;
	} else if (!dirIn.compare("E")) {
		dir = 0;
	}

}

//Moves vehicle one step given an valid action
void Vehicle::move(std::string action) {

	double rad = dir * (M_PI/180);

	if (!action.compare("F")) {
		xPos += cos(rad);
		yPos += sin(rad);
	} else if (!action.compare("B")) {
		xPos -= cos(rad);
		yPos -= sin(rad);
	} else if (!action.compare("L")) {
		dir += 90;
	} else if (!action.compare("R")) {
		dir -= 90;
	}

}

/*
//Vehicle class of which instances can be added to environment
class Vehicle {

	public: 

		int xPos, yPos, dir;
		Environment* env;

		Vehicle(int x, int y, std::string d, Environment* envIn) {
			xPos = x;
			yPos = y;
			env = envIn;
			setDirection(d);
		}

		//Executes movements given a set of characters
		//Returns true if not hitting wall
		bool executeMovement(std::string instructions) {

			int lastX, lastY;
			for(char& c : instructions) {
				lastX = xPos;
				lastY = yPos;
				std::string s(1, c);
				move(s);
				if (!(xPos >= 0 && yPos >= 0 && xPos < env->width && yPos < env->height)) {
					xPos = lastX;
					yPos = lastY;
					return false;
				}
			}
			return true;

		}

		//Changes the direction of the vehicle
		void setDirection(std::string dirIn) {

			if (!dirIn.compare("N")) {
				dir = 90;
			} else if (!dirIn.compare("W")) {
				dir = 180;
			} else if (!dirIn.compare("S")) {
				dir = 270;
			} else if (!dirIn.compare("E")) {
				dir = 0;
			}

		}

		//Moves vehicle one step given an valid action
		void move(std::string action) {

			double rad = dir * (M_PI/180);

			if (!action.compare("F")) {
				xPos += cos(rad);
				yPos += sin(rad);
			} else if (!action.compare("B")) {
				xPos -= cos(rad);
				yPos -= sin(rad);
			} else if (!action.compare("L")) {
				dir += 90;
			} else if (!action.compare("R")) {
				dir -= 90;
			}

		}

};
*/
