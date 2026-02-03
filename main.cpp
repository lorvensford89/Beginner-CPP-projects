#include <iostream>
#include <cstdlib>
#include <limits>
#include <conio.h>

// Include project headers (10)
#include "banking.hpp"
#include "calculator.hpp"
#include "temp_converter.hpp"
#include "todo_list.hpp"
#include "adventure.hpp"
#include "guessing_number.hpp"
#include "guessing_word.hpp"
#include "quiz.hpp"
#include "tic_tac_toe.hpp"
#include "rock_paper_scissors.hpp"



int main() {

	int ch;

	do {

		std::system("cls");

		std::cout << "\n\n\n";
		std::cout << "\t\t\t\t**************************************************************\n";
		std::cout << "\t\t\t\t*                                                            *\n";
		std::cout << "\t\t\t\t*                      EL - C++ PROJECTS                     *\n";
		std::cout << "\t\t\t\t*------------------------------------------------------------*\n";
		std::cout << "\t\t\t\t*                                                            *\n";
		std::cout << "\t\t\t\t*               10 Projects to Learn C++ Basics              *\n";
		std::cout << "\t\t\t\t*                                                            *\n";
		std::cout << "\t\t\t\t*          1  - Banking System                               *\n";
		std::cout << "\t\t\t\t*          2  - Calculator                                   *\n";
		std::cout << "\t\t\t\t*          3  - Temperature Converter                        *\n";
		std::cout << "\t\t\t\t*          4  - To-Do List                                   *\n";
		std::cout << "\t\t\t\t*          5  - Text-Based Adventure                         *\n";
		std::cout << "\t\t\t\t*          6  - Number Guessing Game                         *\n";
		std::cout << "\t\t\t\t*          7  - Word Guessing Game                           *\n";
		std::cout << "\t\t\t\t*          8  - Quiz                                         *\n";
		std::cout << "\t\t\t\t*          9  - Tic Tac Toe                                  *\n";
		std::cout << "\t\t\t\t*          10 - Rock Paper Scissors                          *\n";
		std::cout << "\t\t\t\t*                                                            *\n";
		std::cout << "\t\t\t\t*                                                            *\n";
		std::cout << "\t\t\t\t**************************************************************\n\n\n";

	

		std::cout << "\t\t\t\t- Enter the number of the project to explore it.\n";
		std::cout << "\t\t\t\t- Press 11 to Quit.\n\n";
		std::cout << "\t\t\t\tYour choice: ";
		
		std::cin >> ch;

		// If input fails, clear it
		while (std::cin.fail() || (ch < 1 || ch > 11)) {
			std::cin.clear(); // clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
			std::cout << "\t\tInvalid input. Enter 1-10 or 11 to Quit: ";
			std::cin >> ch;
		}

		// Now handle quitting
		if (ch == 11) {
			std::cout << "\n\n\t\t\t\t\tThank you for exploring the EL-PROJECTS.\n";
			std::cout << "\n\t\t\t\t\t\t\t\t\tCreator: LORVENSFORD\n\n";
			break; // exit loop
		}
		std::system("cls");
		

		switch (ch) {
		case 1: banking(); break;
		case 2: calculator(); break;
		case 3: temp_converter(); break;
		case 4: todo_list(); break;
		case 5: adventure(); break;
		case 6: guessing_number(); break;
		case 7: guessing_word(); break;
		case 8: quiz(); break;
		case 9: tic_tac_toe(); break;
		case 10: rock_paper_scissors(); break;
		}

		// Pause before returning to menu
		if (ch != 11) {
			std::cout << "\n\n\t\t\t\tPress any key to return to the main menu...";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			(void)_getch();
		}

	} while (ch != 11); 

	

	return 0;
}