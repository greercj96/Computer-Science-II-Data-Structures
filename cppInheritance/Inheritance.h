#pragma once
#include <iostream>
using namespace std;

class Vehicle {
private:
	Vehicle(double weight, int numTires, int numPassengers, string model);

public:
	
	void setModel(string model);


	void setnumTires(int numTires);

	void setnumPassengers(int numPassengers);

	Vehicle() {};
	
};

class Car : public Vehicle {

private:
	bool radio = true;
	int numDoors;

public:
	Car();
	

};


class Bike : public Vehicle {
private:
	string helmetSize;

public:
	Bike();


	void setHelmetSize(string helmetSize);
	

};
