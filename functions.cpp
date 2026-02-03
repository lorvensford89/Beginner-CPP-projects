
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