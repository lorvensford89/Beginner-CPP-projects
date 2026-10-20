#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

#include "header.hpp"

void show_balance(double balance);
double deposit();
double withdraw(double balance);
void history_transactions(std::vector<std::string>& history, const std::string& operation, double amount);
void show_history(const std::vector<std::string>& history);


using namespace std;

void banking() {

    char character;
    double balance = 0;
    vector<string> history;

    do {
        system("cls");

        cout << endl << endl;
        cout << "\t\t\t\t----------------------------------------------" << endl;
        cout << "\t\t\t\t              WELCOME TO EL - BANK" << endl;
        cout << "\t\t\t\t----------------------------------------------" << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t1 - BALANCE" << endl;
        cout << "\t\t\t\t\t\t2 - DEPOSIT" << endl;
        cout << "\t\t\t\t\t\t3 - WITHDRAW" << endl;
        cout << "\t\t\t\t\t\t4 - HISTORY" << endl << endl;
        cout << "\t\t\t\t----------------------------------------------" << endl;
        cout << endl << "\t\t\t\tESC - To exit >> ";

        character = _getch();
        system("cls");

        switch (character) {
        case '1':
            show_balance(balance);
            break;

        case '2': { // Deposit
            double amount = deposit();
            balance += amount;
            history_transactions(history, "\t\t\t\tDeposit", amount);
            show_balance(balance);
            break;
        }

        case '3': { // Withdraw
            double amount = withdraw(balance);
            balance -= amount;
            history_transactions(history, "\t\t\t\tWithdraw", amount);
            show_balance(balance);
            break;
        }

        case '4': // Show history
            show_history(history);
            break;
        }

        if (character != 27) {
            cout << endl << endl << "\t\t\t\tPress any key to go back to the menu >> ";
            _getch(); // just wait for key press
        }

    } while (character != 27);

    std::cout << "\n\n\tThank you for using EL- BANK services! \n\n\t\t\tCreator: Lorvensford\n\n";

}


// To show user balance
void show_balance(double balance) {
    cout << fixed << setprecision(2);
    cout << endl << endl;
    cout << "\t\t\t\t----------------------------------------------" << endl;
    cout << endl << endl;
    cout << "\t\t\t\tBALANCE: $ " << balance << endl << endl;
    cout << "\t\t\t\t----------------------------------------------" << endl;
}

// To deposit money
double deposit() {
    double amount = 0;
    cout << fixed << setprecision(2);
    cout << endl << endl;
    amount = get_Double("Enter amount to be deposited: $ ");

    if (amount < 0) {
        cout << "\t\t\t\tInvalid amount!" << endl;
        return 0;
    }
    else {
        return amount;
    }
}

// To withdraw money
double withdraw(double balance) {
    double amount = 0;
    cout << fixed << setprecision(2);
    cout << endl << endl;
    amount = get_Double("Enter amount to be withdrawn: $ ");
    if (amount < 0) {
        cout << "\t\t\t\tInvalid amount." << endl;
        return 0;
    }
    else if (amount > balance) {
        cout << "\t\t\t\tInsufficient amount!" << endl;
        return 0;
    }
    else {
        return amount;
    }
}

// 1 - Record the transactions
void history_transactions(vector<string>& history, const string& operation, double amount) {
    stringstream ss;
    ss << operation << ": $ " << fixed << setprecision(2) << amount;
    history.push_back(ss.str());
}

// 2 - Show the history
void show_history(const vector<string>& history) {
    if (history.empty()) {
        cout << endl << endl << "\t\t\t\tNo transactions yet." << endl;
        return;
    }

    cout << endl << endl << "\t\t\t\tTransaction history: " << endl << endl;
    for (const string& entry : history) {
        cout << entry << endl;
    }
}