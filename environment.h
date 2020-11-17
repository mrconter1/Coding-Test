#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Vehicle;

//Represent an environment which can contain objects
class Environment {

	public:

		int width, height;
		std::list<Vehicle*> vehicles;

		Environment(int w, int h);

		void addVehicle(Vehicle* vehicle);

};

#endif
