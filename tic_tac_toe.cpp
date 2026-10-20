#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <limits>

void draw_board(const std::vector<char>& spaces);
void player_move(std::vector<char>& spaces, char player);
void computer_move(std::vector<char>& spaces, char computer);
bool checking_winner(const std::vector<char>& spaces, char player, char computer);
bool checking_tie(const std::vector<char>& spaces);

void tic_tac_toe() {
	std::cout << "\n\n" << std::setw(50) << "TIC TAC TOE" << "\n\n";
	std::cout << std::setw(60) << "==============================\n";

	std::vector<char> spaces(9, ' ');	// it contains spaces


	char player = 'X';		// it contains the player move symbol of char
	char computer = 'O';	// it constains the computer move symbol of chat too
	bool running = true;	// just put this boolean value to make a loop later


	std::cout << std::setw(40) << "Have fun!\n";
	draw_board(spaces);

	while (running) {

		// Player move
		player_move(spaces, player);
		draw_board(spaces);

		if (checking_winner(spaces, player, computer))
			break;
		if (checking_tie(spaces)) {
			std::cout << "\n\n\t\t\t\tIT'S A TIE!\n\n";
			break;
		}

		// Computer move
		computer_move(spaces, computer);
		draw_board(spaces);

		if (checking_winner(spaces, player, computer))
			break;
		if (checking_tie(spaces)) {
			std::cout << "\n\n\t\t\t\tIT'S A TIE!\n\n";
			break;
		}
	}
}

void draw_board(const std::vector<char>& spaces) {
	std::cout << "\n\n";
	std::cout << std::setw(53) << "     |     |     " << std::endl;
	std::cout << std::setw(38) << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
	std::cout << std::setw(53) << "_____|_____|_____" << std::endl;
	std::cout << std::setw(53) << "     |     |     " << std::endl;
	std::cout << std::setw(38) << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
	std::cout << std::setw(53) << "_____|_____|_____" << std::endl;
	std::cout << std::setw(53) << "     |     |     " << std::endl;
	std::cout << std::setw(38) << "  " << spaces[6] << "  |  " << spaces[7] << "  |   " << spaces[8] << "  " << std::endl;
	std::cout << std::setw(53) << "     |     |     " << std::endl;
}

void player_move(std::vector<char>& spaces, char player) {
	int number;

	do {
		std::cout << "\n\n\t\t\tEnter the number of your mark (1-9) >> ";
		while (!(std::cin >> number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::setw(60) << "Invalid input! Enter the number of your mark (1-9) >> ";
		}
		number--;

		if (number < 0 || number > 8) {
			std::cout << std::setw(60) << "Invalid input! Enter the number of your mark (1-9) >> ";
			continue;
		}

		if (spaces[number] != ' ') {
			std::cout << std::setw(60) << "Spot is already taken! Try another one >> ";
			continue;
		}

		spaces[number] = player;
		break;

	} while (true);
}

void computer_move(std::vector<char>& spaces, char computer) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distr(1, 9);

	std::vector<int> random_numbers;
	for (size_t i = 0; i < 9; i++)
		random_numbers.push_back(distr(gen));

	for (size_t i = 0; i < random_numbers.size(); i++) {
		for (size_t j = 0; j < i;) {
			if (random_numbers[i] == random_numbers[j]) {
				random_numbers[i] = distr(gen);
				j = 0;
			}
			else {
				j++;
			}
		}
	}

	for (size_t i = 0; i < random_numbers.size(); i++) {
		int number = random_numbers[i] - 1;
		if (spaces[number] != ' ')
			continue;
		else {
			spaces[number] = computer;
			break;
		}
	}

}

bool checking_winner(const std::vector<char>& spaces, char player, char computer) {

	// rows
	for (size_t i = 0; i < 9; i += 3) {
		if (spaces[i] != ' ' && spaces[i] == spaces[i + 1] && spaces[i] == spaces[i + 2]) {
			if (spaces[i] == player)
				std::cout << "\n\n\t\t\t\tYOU WIN!\n\n";
			else
				std::cout << "\n\n\t\t\t\tCOMPUTER WINS!\n\n";
			return true;
		}
	}

	// columns
	for (size_t i = 0; i < 3; i++) {
		if (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i] == spaces[i + 6]) {
			if (spaces[i] == player)
				std::cout << "\n\n\t\t\t\tYOU WIN!\n\n";
			else
				std::cout << "\n\n\t\t\t\tCOMPUTER WINS!\n\n";
			return true;

		}
	}

	// first diagonal (0,4,8)
	if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[0] == spaces[8]) {
		if (spaces[0] == player)
			std::cout << "\n\n\t\t\t\tYOU WIN!\n\n";
		else
			std::cout << "\n\n\t\t\t\tCOMPUTER WINS!\n\n";
		return true;
	}

	// second diagonal (2,4,6)
	if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[2] == spaces[6]) {
		if (spaces[2] == player)
			std::cout << "\n\n\t\t\t\tYOU WIN!\n\n";
		else
			std::cout << "\n\n\t\t\t\tCOMPUTER WINS!\n\n";
		return true;
	}
	return false;
}

bool checking_tie(const std::vector<char>& spaces) {
	for (size_t i = 0; i < 9; i++) {
		if (spaces[i] == ' ')
			return false;
	}
	return true;
}