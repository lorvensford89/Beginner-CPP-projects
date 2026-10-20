// I will create a calcultor where there will be 5 operator:
// +, -, x, /, sqrt

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

#include "header.hpp"

void calculator() {

	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\n\n              EL - CALCULATOR\n";
	std::cout << "=====================================================\n\n\n";

	std::cout << "There are five (5) operator availble: \n\n";
	std::vector<std::string> operators = { "+", "-", "x", "/", "sqrt()" };
	for (std::size_t i = 0; i < operators.size(); i++)
		std::cout << i + 1 << ")  " << operators[i] << '\n';

	double number, number_2;
	int user_operator;

	do {
		while (true) {
			std::cout << "\nPick the operation you want: ";
			std::cin >> user_operator;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\n\nInvalid numerator! Pick (1-5).\n\n";
				continue;
			}
			else {
				break;
			}
		}
		user_operator--;
	} while (user_operator < 0 || user_operator > 4);

	double result{0};

	switch (user_operator) {
	case 0: {
		std::cout << "\nAddition\n";
		std::cout << "------------------------\n";
		number = get_Double("Number 1: ");
		number_2 = get_Double("Number 2: ");
		result = number + number_2;
		std::cout << number << " + " << number_2 << " = " << result << '\n';
		std::cout << "------------------------\n";

		break;
	}

	case 1: {
		std::cout << "\nSubstraction\n";
		std::cout << "------------------------\n";
		number = get_Double("Number 1: ");
		number_2 = get_Double("Number 2: ");
		result = number - number_2;
		std::cout << number << " - " << number_2 << " = " << result << '\n';
		std::cout << "------------------------\n";

		break;
	}

	case 2: {
		std::cout << "\nMultiplication\n";
		std::cout << "------------------------\n";
		number = get_Double("Number 1: ");
		number_2 = get_Double("Number 2: ");
		result = number * number_2;
		std::cout << number << " x " << number_2 << " = " << result << '\n';
		std::cout << "------------------------\n";

		break;
	}

	case 3: {
		std::cout << "\nDivision\n";
		std::cout << "------------------------\n";
		number = get_Double("Number 1: ");
		number_2 = get_Double("Number 2: ");
		if (number_2 == 0) {
			std::cout << "Error: Division by zero.\n";
			break;
		}
		else {
			result = number / number_2;
			std::cout << number << " / " << number_2 << " = " << result << '\n';
			std::cout << "------------------------\n";
			break;
		}
	}

	case 4: {
		std::cout << "\nSquare root\n";
		std::cout << "------------------------\n";
		number = get_Double("Number: ");
		if (number < 0) {
			std::cout << "\nError: Square root of negative numbers.\n";
			break;
		}
		else {
			result = sqrt(number);
			std::cout << "Square root(" << number << ") = " << result << '\n';
			std::cout << "------------------------\n";
			break;
		}

	}
	}
	std::cout << "=====================================================\n\n\n";
	std::cout << "\tThank you for using EL - CALCULATOR\n\n";
	std::cout << "\t\t\tCreator: " << "EL\n\n";
}