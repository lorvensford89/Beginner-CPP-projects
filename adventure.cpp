// This is a text based adventure project; this is my first time doing it


#include <iostream>
#include <string>
#include <limits>

void adventure() {
    bool game_running = true;
    std::string location = "Haiti";
    int choice;

    do {
        // Haiti
        if (location == "Haiti") {
            std::cout << "\n\nYou are in Haiti - home.\n";
            std::cout << "This is where your roots are. Everything familiar starts here.\n";
            std::cout << "From home, you can either explore the world briefly or commit to something bigger.\n\n";
            std::cout << "Commands:\n";
            std::cout << "1 - Visit (go to Cuba)\n";
            std::cout << "2 - Study (go to Russia)\n";
            std::cout << "3 - Quit (exit the game)\n";

            std::cout << ">> ";
            while (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter 1, 2, or 3 >> ";
            }

            if (choice == 1) location = "Cuba";
            else if (choice == 2) location = "Russia";
            else if (choice == 3) {
                game_running = false;
                std::cout << "Thanks for playing!\n";
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }

        // Cuba
        else if (location == "Cuba") {
            std::cout << "\n\nYou are in Cuba.\n";
            std::cout << "This place is about experience, culture, and short stays.\n";
            std::cout << "You are not here to settle - only to see, learn, and reflect.\n";
            std::cout << "1 - Go back home\n";
            std::cout << "2 - Move forward to Russia\n";

            std::cout << ">> ";
            while (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Pick 1 or 2 >> ";
            }

            if (choice == 1) {
                location = "Haiti";
                std::cout << "\nWelcome back home! I hope that you've had a pleasant time in Cuba.\n";
            }
            else if (choice == 2) {
                location = "Russia";
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }

        // Russia
        else if (location == "Russia") {
            std::cout << "\n\nYou are in Russia.\n";
            std::cout << "This is a place of discipline, structure, and long-term commitment.\n";
            std::cout << "Studying here means choosing effort over comfort.\n";
            std::cout << "1 - Continue to learn\n";
            std::cout << "2 - Define this chapter as your life (end game)\n";
            std::cout << "3 - Go back home\n";

            std::cout << ">> ";
            while (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Pick 1, 2, or 3 >> ";
            }

            if (choice == 1) {
                std::cout << "\nYou continue learning. This will affect your future.\n";
            }
            else if (choice == 2) {
                std::cout << "\nYou define this chapter as your life. The journey ends here.\n";
                game_running = false;
            }
            else if (choice == 3) {
                location = "Haiti";
                std::cout << "\nWelcome back home! That experience in Russia was valuable.\n";
            }
            else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }

    } while (game_running);

}
