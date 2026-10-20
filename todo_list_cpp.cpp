#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <limits>
#include <cstdlib>

void add_task(std::vector<std::string>& todo_list);
void view_tasks(const std::vector<std::string>& todo_list);
void delete_tasks(std::vector <std::string>& todo_list);

void todo_list() {

	std::vector<std::string> todo_list;
	char choice;

	std::cout << "\n\n        EL TO-DO LIST";

	do {
		std::system("cls");

		std::cout << "\n\n===============================";
		std::cout << "\n       TO-DO LIST MENU\n";
		std::cout << "===============================\n\n";
		std::cout << "1 - Add a task\n";
		std::cout << "2 - View tasks\n";
		std::cout << "3 - Delete a task\n\n";
		std::cout << "ESC to exit\n";
		std::cout << "===============================\n\n";

		std::cout << "Choose an option: ";
		choice = _getch();
		std::system("cls");

		switch (choice) {
		case '1':
			add_task(todo_list);
			break;
		case '2':
			view_tasks(todo_list);
			std::cout << "\nPress any key to return to menu...";
			_getch();
			break;
		case '3':
			delete_tasks(todo_list);
			std::cout << "\nPress any key to return to menu...";
			_getch();
			break;
		}

	} while (choice != 27); // ESC

	std::cout << "\n\n\tThank you for using EL TO-DO LIST.\n\n";
	std::cout << "\t\t\tCreator: " << "EL\n\n";
}

void add_task(std::vector<std::string>& todo_list) {

	int number;

	std::cout << "\n\nHow many tasks you are making? >> ";
	while (!(std::cin >> number)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input!.\n\n";
		std::cout << "How many tasks you are making? >> ";
	}

	while (number <= 0) {
		std::cout << "\n\nIncorrect! Number must greater than 0.\n\n";
		std::cout << "How many tasks you are making? >> ";

		while (!(std::cin >> number)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input!.\n\n";
			std::cout << "How many tasks you are making? >> ";
		}
	}

	std::string task;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (std::size_t i = 0; i < number; i++) {
		std::cout << "\nTask " << i + 1 << ": ";
		std::getline(std::cin, task);
		todo_list.push_back(task);
	}

}

void view_tasks(const std::vector<std::string>& todo_list) {

	std::cout << "\n\nTASKS: \n";
	std::cout << "\n-------------------------------\n";
	if (todo_list.empty()) {
		std::cout << "\nNo tasks in the to-do list.\n";
		std::cout << "-------------------------------\n";
	}
	else {
		for (std::size_t i = 0; i < todo_list.size(); i++) {
			std::cout << i + 1 << " - " << todo_list[i] << std::endl;
			std::cout << "-------------------------------\n";
		}
	}
}

void delete_tasks(std::vector<std::string>& todo_list) {

	view_tasks(todo_list);
	std::size_t index;

	std::cout << "\n\nEnter the task number to delete: ";
	while (!(std::cin >> index)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid input!.\n\n";
		std::cout << "\n\nEnter the task number to delete: ";
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int index_n = index - 1;	// index correcponding with the vector size

	if (index > 0 && index <= todo_list.size()) {
		std::string deleted_task = todo_list[index_n];
		todo_list.erase(todo_list.begin() + index_n);
		std::cout << "\n\"" << deleted_task << "\" deleted!\n";
	}
	else {
		std::cout << "\nInvalid task number.\n";
	}
}