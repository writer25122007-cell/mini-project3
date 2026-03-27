#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
    int accountNumber;
    string name;
    double balance;

public:
    Account() : accountNumber(0), balance(0.0) {}

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "Account Created Successfully!\n";
    }

    void showAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited. New Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Amount Withdrawn. New Balance: " << balance << endl;
        }
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getName() const { return name; }

    void saveToFile() {
        ofstream outFile("accounts.txt", ios::app);
        outFile << accountNumber << " " << name << " " << balance << endl;
        outFile.close();
    }
};

void menu() {
    cout << "\n--- Banking Management System ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account Details\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Account acc;
    int choice;
    double amount;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            acc.createAccount();
            acc.saveToFile();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            break;
        case 4:
            acc.showAccount();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

