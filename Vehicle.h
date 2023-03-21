#pragma once
#include <iostream>;  

using namespace std; 

class Vehicle {
	private:
		string name; 
		int nitro; 
		int speed; 
		int distance; 

	public:    
		string getName();

		int getSpeed(); 
		bool hasNitro(); 
		int getDistance(); 

		void init(string name);
		void setSpeed(int value);
		void useNitro();
};