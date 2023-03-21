#include <iostream>; 
#include "Vehicle.h";   

using namespace std;

string Vehicle::getName() {
	return name; 
}

int Vehicle::getSpeed() {
	return speed;
}

bool Vehicle::hasNitro() {
	if (nitro == 0) {
		return false; 
	}

	return true; 
}

int Vehicle::getDistance() {
	return distance;
}

void Vehicle::init(string vehicleName) {
	name = vehicleName;
	nitro = 1;
	speed = 0;
	distance = 0;
}

void Vehicle::setSpeed(int value) {
	speed = value; 
	distance = distance + (value * 100);
}

void Vehicle::useNitro() {
	nitro = 0; 
	int dice = rand() % 2;
	
	if (dice == 0) {
		speed = speed / 2;  
	}
	else {
		speed = speed * 2; 
	}
}