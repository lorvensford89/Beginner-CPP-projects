// This is a temperature converter where there will be 
// three (3) type of degree: C, F and K
// C → F: F = C x 9 / 5 + 32
// C → K: K = C + 273.15 
// F → C: C = (F - 32) x 5 / 9
// F → K: (F − 32) × 5/9 + 273.15
// K → C: K - 273.15
// K → F: (K - 273.15) x 9 / 5 + 32

#include <iostream>
#include <iomanip>
#include <limits>
#include "functions.hpp"



void temp_converter() {

	std::cout << std::fixed << std::setprecision(2);
	double C, F, K;
	int user_choice;

	std::cout << "\n=========================================\n";
	std::cout << "\tTEMPERATURE CONVERTER";
	std::cout << "\n=========================================\n";
	std::cout << "\n" << std::endl;

	std::cout << "\nSelect conversion type: \n\n\n";
	std::cout << "1 - Celcius  - Fahrenheit\n";
	std::cout << "2 - Celsius  - Kelvin\n";
	std::cout << "3 - Fahrenheit  - Celcius\n";
	std::cout << "4 - Fahrenheit  - Kelvin\n";
	std::cout << "5 - Kelvin  - Celsius\n";
	std::cout << "6 - Kelvin  - Farenheit\n";

	std::cout << "\n\n";
	std::cout << "\n-----------------------------------------\n";

	while (true) {
		std::cout << "\nEnter your choice of converter: ";

		if (!(std::cin >> user_choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input!\n";
			continue;
		}

		if (user_choice < 1 || user_choice > 6) {
			std::cout << "Invalid input!\n";
			continue;
		}

		break;
	}


	switch (user_choice) {
	case 1: {
		std::cout << "1 - Celsius - Fahrenheit\n";
		std::cout << "******************************\n\n";
		C = get_Double("Celsius = ");
		F = (C * 9 / 5) + 32;
		std::cout << C << " C = " << F << '\n';
		break;
	}

	case 2: {
		std::cout << "2 - Celsius  - Kelvin\n";
		std::cout << "******************************\n\n";
		C = get_Double("Celsius = ");
		K = C + 273.15;
		std::cout << C << " C = " << K << " K\n";
		break;
	}

	case 3: {
		std::cout << "3 - Fahrenheit  - Celsius\n";
		std::cout << "******************************\n\n";
		F = get_Double("Fahrenheit = ");
		C = (F - 32) * 5 / 9;
		std::cout << F << " F = " << C << " C\n";

		break;
	}

	case 4: {
		std::cout << "4 - Fahrenheit  - Kelvin\n";
		std::cout << "******************************\n\n";
		F = get_Double("Fahrenheit = ");
		K = (F - 32) * 5 / 9 + 273.15;
		std::cout << F << " F = " << K << " K\n";

		break;
	}

	case 5: {
		std::cout << "5 - Kelvin  - Celsius\n";
		std::cout << "******************************\n\n";
		K = get_Double("Kelvin = ");
		C = K - 273.15;
		std::cout << K << " K = " << C << " C\n";

		break;
	}

	case 6: {
		std::cout << "6 - Kelvin  - Fahrenheit\n";
		std::cout << "******************************\n\n";
		K = get_Double("Kelvin = ");
		F = (K - 273.15) * 9 / 5 + 32;
		std::cout << K << " K = " << F << " F\n";

		break;
	}

	}

	std::cout << "\n-----------------------------------------\n\n";
	std::cout << "\n=========================================\n";

	std::cout << "\n\nThank you for using TEMPERATURE CONVERTER\n\n";
	std::cout << "\t\tCreator: " << "LORVENSFORD\n\n";
}

