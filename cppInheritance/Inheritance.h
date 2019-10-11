#pragma once
#include <iostream>
using namespace std;

class Vehicle {
private:
	double weight;
	int numTires;
	int numPassengers;
	string model;

public:
	void setModel(string model) {
		
	}


	void setnumTires(int numTires) {
		
	}

	void setnumPassengers(int numPassengers) {
		
	}
};

class Car : public Vehicle {

private:
	bool radio = true;
	int numDoors;

public:
	Car() {
		numDoors = 4;
		cout << "This is a car ";
		cout << "This vehicle has a radio " << endl;

	}


};


class Bike : public Vehicle {
private:
	string helmetSize;

public:
	Bike() {
		
	}

};
