#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>

double get_Double(std::string prompt) {
	double number;
	std::cout << prompt;
	while (!(std::cin >> number)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input! Use numbers.\n\n";
		std::cout << prompt;
	}
	return number;
}

// 10 programs:
void adventure();
void banking();
void guessing_number();
void guessing_word();
void quiz();
void rock_paper_scissors();
void temp_converter();
void tic_tac_toe();
void todo_list();

#endif // HEADER_HPP