#include <iostream>
#include <random>
#include <cctype>

void rock_paper_scissors() {

	std::cout << "\n\n\t\tROCK-PAPER-SCISSORS\n" << std::endl;
	std::cout << "======================================================\n\n";

	char user_choice;

	do {
		std::cout << "\nPick : \n\n";
		std::cout << " - 'r' for Rock\n";
		std::cout << " - 'p' for Paper\n";
		std::cout << " - 's' for Scissors\n";

		std::cout << "\n\nYour choice: ";
		std::cin >> user_choice;
		user_choice = std::tolower(user_choice);

	} while (user_choice != 'r' && user_choice != 'p' && user_choice != 's');


	// Show the user choice
	std::cout << "\n1) You chose ";

	switch (user_choice) {
        case 'r': std::cout << "ROCK.\n"; break;
        case 'p': std::cout << "PAPER.\n"; break;
        case 's': std::cout << "SCISSORS.\n"; break;
	}

	// computer choice
	std::random_device random_number;
	std::mt19937 gen(random_number());
	std::uniform_int_distribution<int> distr(1, 3);
	int computer = distr(gen);

	std::cout << "2) Computer chose ";

	switch (computer) {
        case 1:	std::cout << "ROCK.\n"; break;
        case 2: std::cout << "PAPER.\n"; break;
        case 3: std::cout << "SCISSORS.\n"; break;
	}

	// check winner and tie
	std::cout << "\n\t\t     RESULTS\n";
	std::cout << "\t\t******************\n";

	if ((user_choice == 'r' && computer == 1) || (user_choice == 'p' && computer == 2) || (user_choice == 's' && computer == 3))
		std::cout << "\n\t\tTHAT'S A TIE!\n\n";
	else if ((user_choice == 'r' && computer == 2) || (user_choice == 'p' && computer == 3) || (user_choice == 's' && computer == 1))
		std::cout << "\n\t\tCOMPUTER WINS!\n\n";
	else if ((user_choice == 'r' && computer == 3) || (user_choice == 'p' && computer == 1) || (user_choice == 's' && computer == 2))
		std::cout << "\n\t\tYOU WIN!\n\n";

	std::cout << "\t\t******************\n";

	std::cout << "======================================================\n\n";

	std::cout << "\n\n\tThank you for playing.\n\n";
	std::cout << "\t\t\tCreator: " << "EL\n\n";
}