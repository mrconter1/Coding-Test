#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "environment.h"
#include "iohandler.h"

void IOHandler::readRoomSize(int& width, int& height) {

	while (1) {

		//Tries to read and split the std::string
		std::vector<std::string> dimSplit;
		try {
			std::string dimensions = readInput("Input room size (ex \"3 1\"):");
			dimSplit = splitString(dimensions, " ");
		} catch(std::exception& e) {
			std::cout << "Error: " <<  e.what() << std::endl;
			continue;
		}

		//Checks so that std::string contains two elements
		if (dimSplit.size() != 2) {
			std::cout << "Input needs to contain two parameters." << std::endl;
			continue;
		}

		//Try to parse each element as integers
		try {
			width = stoi(dimSplit[0]);
			height = stoi(dimSplit[1]);
		} catch(std::exception& e) {
			std::cout << "Error: " <<  e.what() << std::endl;
			continue;
		}

		//Check so that dimensions are large enough
		if (width < 1 || height < 1) {
			std::cout << "Width or height cannot be less then 1." << std::endl;
			continue;
		}

		break;

	}

}

void IOHandler::readPositionAndOrientation(int& xPos, int& yPos, std::string& dir, Environment* env) {

	while (1) {

		//Tries to read and split the std::string
		std::vector<std::string> posSplit;
		try {
			std::string startPos = readInput("Input start position and orientation (ex \"3 1 N\" or \"1 1 W\"):");
			posSplit = splitString(startPos, " ");
		} catch(std::exception& e) {
			std::cout << "Error: " <<  e.what() << std::endl;
			continue;
		}

		//Checks so that std::string contains three elements
		if (posSplit.size() != 3) {
			std::cout << "Input needs to contain three parameters." << std::endl;
			continue;
		}


		//Try to parse elements
		try {
			xPos = stoi(posSplit[0]);
			yPos = stoi(posSplit[1]);
			dir = posSplit[2];
		} catch(std::exception& e) {
			std::cout << "Error: " <<  e.what() << std::endl;
			continue;
		}

		//Check validity of characters
		if (dir.compare("N") != 0 && dir.compare("W") != 0 && dir.compare("S") != 0 && dir.compare("E") != 0) {
			std::cout << "Please use either \"N\", \"W\", \"S\" or, \"E\" for orientation." << std::endl;
			continue;
		}

		//Check so that location is valid
		if (!(xPos >= 0 && yPos >= 0 && xPos < env->width && yPos < env->height)) {
			std::cout << "Cannot place outside world bounds." << std::endl;
			continue;
		}

		break;

	} 

}

void IOHandler::readMoveSequence(std::string& moveSequence) {

	while (1) {
		moveSequence = readInput("Input a sequence of movements the car will execute (ex \"FFLLRBB\"):");
		bool succeed = true;
		//Check validity of each character
		for(char& c : moveSequence) {
			if (!(c == 'F' || c == 'L' || c == 'R' || c == 'B')) {
				std::cout << "Invalid character in move sequence. Please use either \"F\", \"L\", \"R\" or, \"B\"." << std::endl;
				succeed = false;
				break;
			}
		}
		if (!succeed) 
			continue;
		break;
	}

}

//Returns split list of std::strings given std::string and delimiter
std::vector<std::string> IOHandler::splitString(std::string s, std::string delimiter) {

	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    tokens.push_back(token);
	    s.erase(0, pos + delimiter.length());
	}
	tokens.push_back(s);

	return tokens;

}

//Provides function for easy input with message
std::string IOHandler::readInput(std::string message) {

	std::string input;
	std::cout << message << std::endl;
	getline (std::cin, input);
	std::cout << std::endl;
	return input;

}
