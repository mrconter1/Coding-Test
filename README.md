# Coding-Test

This repository contains a solution for a typical coding test. The test involves simulating a car that navigates in a 2D environment. The task is to determine if the simulation results in the car hitting the wall.

## Task Instructions

The user should be able to specify the dimensions of the rectangular environment. After that, the user should be prompted by specifying the location and orientation of the vehicle. The user can then input a sequence of actions which the car will execute.

* **Requirements**
  * The car can only move to and exist in discrete locations
  * The direction of the car can only be along with the points of the compass
  * Should be written using C++


Orientation is specified with:
* **N** (North), **W** (West), **S** (South) and, **E** (East)

Movement can be specified with:
Orientation is specified with:
* **F** (Move forward), **B** (Move back), **L** (Rotate vehicle 90° left) and, **R** (rotate vehicle 90° right)

## Installation and Execution

Clone the project

`git clone https://github.com/mrconter1/Coding-Test/`

Build project

`g++ main.cpp testclass.cpp environment.cpp vehicle.cpp iohandler.cpp -o program`

Run resulting program

`./program`

## Roadmap

The following could be a potential approach in the future for this project:
* Use a square structure for world representation. You could then specify more arbitrary spaces.
* Implement more tests. Specifically for input.
* Create a specialized error handling class.
* Standardize code format using code formatter.
* Improve error feedback to the user


