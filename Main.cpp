#include <iostream>;
#include "Vehicle.h"; 
#include "Types.cpp"; 
#include <thread>;       
#include <chrono>; 

using namespace std; 

const int amountOfVehicles = 10;  

void run(Vehicle &vehicle, int round) {
	system("CLS"); 
	int dice = (rand() % 5) + 1;
	vehicle.setSpeed(vehicle.getSpeed() + dice); 

	cout << "[ Ronda " << round << " ] - " << vehicle.getName() << "\n\nSe ha tirado un dado y ha salido \033[33m" << dice << "\033[0m\n * Velocidad actual: \033[31m" << (vehicle.getSpeed() * 100) << "km/h\n\033[0m * Distancia recorrida: \033[32m" << vehicle.getDistance() << "m\033[0m" << endl;

	if (vehicle.hasNitro()) {
		string response = "";

		while (response != "y" && response != "n") {
			cout << "\n[\033[32mY\033[0m/\033[31mN\033[0m] Quieres usar el nitro?: "; 
			cin >> response;
		}

		if (response == "y") {
			vehicle.useNitro(); 
		}
	}
	else {
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}

	return; 
}

int main()
{
	Vehicle raceVehicles[amountOfVehicles]; 

	// @ Init
	for (int index = 0; index < amountOfVehicles; index++)
	{
		string vehicleName; 

		cout << "[" << index << "] Introduce el nombre del corredor: "; 
		cin >> vehicleName;  

		raceVehicles[index].init(vehicleName); 
	}

	// @ Race
	int round = 0; 

	while (round < 5) {
		for (int index = 0; index < amountOfVehicles; index++) {
			run(raceVehicles[index], round); 
		}

		round++; 
	}

	system("CLS");

	// @ Winner
	int maxVal = 0; 
	int winnerIndex; 

	cout << "La carrera ha \033[32mfinalizado\033[0m, resultados: \n" << endl; 

	for (int index = 0; index < amountOfVehicles; index++)
	{  
		int distance = raceVehicles[index].getDistance(); 

		if (distance > maxVal) {
			maxVal = distance; 
			winnerIndex = index;
		}

		cout << "[\033[33m" << index << "\033[0m] - " << raceVehicles[index].getName() << ": \033[31m" << raceVehicles[index].getDistance() << "m\033[0m" << endl;
	}

	cout << "\nEl ganador de la carrera es \033[34m" << raceVehicles[winnerIndex].getName() << "\033[0m con una distancia recorrida de \033[33m" << raceVehicles[winnerIndex].getDistance() << "m\033[0m]" << endl; 

	system("PAUSE"); 
	return 0; 
}
