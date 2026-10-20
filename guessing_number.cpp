/*
Guessing number project:

    Here is the rule of the game:
    The computer generates 10 random numbers from 1 to 10, they will be shown,
    the user has 3 attempts to get the right one and it will calculate their
    accuracy.
*/

#include <iostream>
#include <random>
#include <vector>
#include <limits>
#include <iomanip>

bool is_number_in_vector(const std::vector<int>& numbers, int user_choice);

void guessing_number() {

	std::cout << std::fixed << std::setprecision(2);

	int user_number;
	int attempt = 0;
	double accuracy = 3;

	std::random_device number;
	std::mt19937 gen(number());
	std::uniform_int_distribution<> distr(1, 10);

	const int SIZE = 5;
	std::vector<int> Numbers;

	// Put random numbers in the vector
	for (int i = 0; i < SIZE; i++)
		Numbers.push_back(distr(gen));


	const std::vector<int> frozen_numbers(Numbers.begin(), Numbers.end());		// Froze the vector	

	std::cout << "------ GUESSING NUMBER GAME -----" << std::endl << std::endl;

	std::cout << "You have 3 attempts. Numbers from 1 to 15." << std::endl;

	while (true) {
		std::cout << "Pick a number: ";
		while (!(std::cin >> user_number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input." << std::endl << std::endl;
			std::cout << "Pick a number: ";
		}

		attempt++;

		bool decision = is_number_in_vector(frozen_numbers, user_number);

		if (decision) {
			std::cout << "\nYey!!!\n" << user_number << " is in the winning number!" << std::endl;

			if (attempt == 1) {
				std::cout << "You win in the first attempt. Congrats.\n";
				std::cout << "Accuracy: " << 100 / 1 << "%\n";
			}
			else if (attempt == 2) {
				std::cout << "You win in the second attempt. Great!\n";
				std::cout << "Accuracy: " << 100 / 2 << "%\n";
			}
			else {
				std::cout << "You win in the last attempt. Good!\n";
				std::cout << "Accuracy:: " << double(100 / accuracy) << "%\n";
			}

			// Display the chosen random numbers
			std::cout << "\nThe numbers = {";
			for (int i = 0; i < SIZE; i++) {
				std::cout << frozen_numbers[i];
				if (i < SIZE - 1)
					std::cout << ", ";
			}
			std::cout << "}" << std::endl;
			break;
		}
		else {
			std::cout << "\n" << user_number << " is wrong!\n";
			std::cout << "Attempt: " << attempt << "\n\n";

			if (attempt == 3) {
				std::cout << "\nYou lost!\n\n";

				// Display the chosen random numbers
				std::cout << "Here are the numbers." << std::endl;
				std::cout << "\nThe numbers = {";
				for (int i = 0; i < SIZE; i++) {
					std::cout << frozen_numbers[i];
					if (i < SIZE - 1)
						std::cout << ", ";
				}
				std::cout << "}" << std::endl;

				break;
			}
			continue;
		}
	}

	std::cout << "\n\nThank you for playing! \n\n\t\tCreator: EL\n\n";
}

bool is_number_in_vector(const std::vector<int>& numbers, int user_choice) {
	for (const auto& number : numbers)
		if (number == user_choice)
			return true;
	return false;
}