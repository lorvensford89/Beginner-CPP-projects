// The Guessing Word Game is simple: I will display nine words of five diferent areas,
// with a 2D vector,
// and he will have only two attempts to get the right word. 
// If he misses the first attempt I will give him a hint of in which area the word is

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <algorithm>
#include <cctype>

void guessing_word() {

	std::cout << "======================= GUESSING WORD GAME =======================\n\n";

	const std::vector<std::string>& categories =
	{ "Chicken", "Bathroom", "Electronics", "Clothes", "Transportation" };

	const std::vector<std::vector<std::string>>& words = {
		{"Spoon", "Pan", "Cup"},
		{"Soap", "Towel", "Toothbrush"},
		{"Phone", "Laptop", "Charger"},
		{"Shirt", "Shoes", "Hat"},
		{"Bike", "Car", "Bag"} };

	std::cout << "   Categories       |	  Words\n\n";
	for (size_t i = 0; i < categories.size(); i++) {
		std::cout << std::left << std::setw(20) << (std::to_string(i + 1) + " - " + categories[i]) << ": ";
		for (size_t j = 0; j < words[i].size(); j++) {
			std::cout << words[i][j];
			if (j < words[j].size() - 1)
				std::cout << ", ";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";

	std::string user_guess;
	int computer_guess_number;
	std::string computer_guess_string("word");

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 15);
	computer_guess_number = distr(gen);

	if (computer_guess_number == 1 || computer_guess_number == 2 || computer_guess_number == 3) {
		for (size_t i = 0; i < words.size() - 4; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				if (computer_guess_number == j + 1) {
					computer_guess_string = words[i][j];
					break;
				}
			}
			break;
		}
	}
	else if (computer_guess_number == 4 || computer_guess_number == 5 || computer_guess_number == 6) {
		for (size_t i = 1; i < words.size() - 3; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				if (computer_guess_number == j + 4) {
					computer_guess_string = words[i][j];
					break;
				}
			}
			break;
		}
	}
	else if (computer_guess_number == 7 || computer_guess_number == 8 || computer_guess_number == 9) {
		for (size_t i = 2; i < words.size() - 2; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				if (computer_guess_number == j + 7) {
					computer_guess_string = words[i][j];
					break;
				}
			}
			break;
		}
	}
	else if (computer_guess_number == 10 || computer_guess_number == 11 || computer_guess_number == 12) {
		for (size_t i = 3; i < words.size() - 1; i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				if (computer_guess_number == j + 10) {
					computer_guess_string = words[i][j];
					break;
				}
			}
			break;
		}
	}
	else {
		for (size_t i = 4; i < words.size(); i++) {
			for (size_t j = 0; j < words[i].size(); j++) {
				if (computer_guess_number == j + 13) {
					computer_guess_string = words[i][j];
					break;
				}
			}
			break;
		}

	}

	std::cout << "-------------------------------------------------------------------\n";
	std::cout << "\n\nYou have two(2) attempts to guess the right word.\n";
	std::cout << "It is in one these categories above.\n\n";

	int attempt{0};
	const int max_attempt = 2;

	while (attempt < max_attempt) {
		std::cout << "\nPick the word: ";
		std::cin >> user_guess;
		transform(user_guess.begin(), user_guess.end(), user_guess.begin(), ::tolower);	// make the input lower case
		user_guess[0] = std::toupper(static_cast<unsigned char>(user_guess[0]));		// the first letter is capital

		attempt++;

		if (user_guess == computer_guess_string) {
			std::cout << "\nCongrats, you've won!!!!\nYou find the guessing word.\n";
			if (attempt == 1)
				std::cout << "You won just in the first attempt. \nAccuracy: 100.00%\n";
			else
				std::cout << "\nAccuracy: 50.00%\n";
			std::cout << "---------------------------------------------------------------------\n";
			break;
		}
		else {
			std::cout << "\nYou didn't find the guessing word.\n\n";

			if (attempt == 1) {
				std::cout << "Last attempt! Here is a hint: " << std::endl;
				for (size_t i = 0; i < categories.size(); i++)
					for (size_t j = 0; j < words[i].size(); j++)
						if (computer_guess_string == words[i][j]) {
							std::cout << " - The word is in category " << categories[i] << "\n";
							break;
						}
			}
			else {
				std::cout << "\nYou lost!\n\n";
				std::cout << "---------------------------------------------------------------------\n";
			}
			continue;
		}

	}
	std::cout << "\n\n=====================================================================\n\n";

	std::cout << "\n\n\tThank you for playing GUESSING WORD GAME! \n\n\t\t\tCreator: EL\n\n";
}