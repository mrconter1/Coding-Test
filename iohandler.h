#ifndef IOHANDLER_H
#define IOHANDLER_H

class Environment;

//Handles input, output and, error handling
class IOHandler {

	public:

		void readRoomSize(int& width, int& height);
		void readPositionAndOrientation(int& xPos, int& yPos, std::string& dir, Environment* env);
		void readMoveSequence(std::string& moveSequence);

	private:

		//Returns split list of std::strings given string and delimiter
		std::vector<std::string> splitString(std::string s, std::string delimiter);

		//Provides function for easy input with message
		std::string readInput(std::string message);

};

#endif
