#include <iostream>
#include "Inheritance.h"
using namespace std;


Vehicle::Vehicle(
	double weight,
	int numTires,
	int numPassengers,
	string model
){}



void Vehicle :: setModel(string model) {
		model = model;
		cout << "This is a "<< model << endl;
	}


void Vehicle :: setnumTires(int numTires) {
		cin >> numTires;
		cout << "There are " << numTires << " tires" << endl;
	}

void Vehicle ::	setnumPassengers(int numPassengers) {
		numPassengers = numPassengers;
		cout << "You have " << numPassengers << " passengers" << endl;
	}




Car::Car() {
	cout << "This is a car " << endl;
	cout << "This vehicle has a radio " << endl;
}


Bike :: Bike () {
	cout << "This is a bike, so there is no radio" << endl;
}
	


void Bike::setHelmetSize(string helmetSize)
{
	helmetSize = helmetSize;
	cout << "Your helmet size is " << helmetSize << endl;
}
