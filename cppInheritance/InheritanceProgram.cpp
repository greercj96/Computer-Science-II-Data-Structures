#include "Inheritance.h"
#include <iostream>

using namespace std;

int main() {
	Car car1;
	car1.setModel("Mercedes");
	car1.setnumPassengers(4);

	cout << "*** NEXT VEHICLE ***" << endl;

	Bike bike1;
	bike1.setModel("Harley Davidson");
	bike1.setnumPassengers(2);
	bike1.setHelmetSize("Small");
}
 
