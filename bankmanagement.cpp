#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Deposited Successfully!\n";
        } else {
            cout << "Invalid Deposit Amount!\n";
        }
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance or Invalid Amount!\n";
        }
    }
    double getBalance() {
        return balance;
    }
    void displayAccount() {
        cout << "\n=========== Account Details ===========\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "========================================\n";
    }
    int getAccountNumber() {
        return accountNumber;
    }
};
int main() 
{
    vector<BankAccount> accounts;
    int choice, accNum;
    string name;
    double amount;

    while (true) 
    {
        cout << "\n========= Bank Management System =========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: 
            {
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Initial Deposit Amount: ";
                cin >> amount;
                accounts.push_back(BankAccount(name, accNum, amount));
                cout << "Account Created Successfully!\n";
                break;
            }
            case 2: {
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account Not Found!\n";
                break;
            }
            case 3: {
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Withdrawal Amount: ";
                cin >> amount;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account Not Found!\n";
                break;
            }
            case 4: {
                cout << "Enter Account Number: ";
                cin >> accNum;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        cout << "Current Balance: $" << fixed << setprecision(2) << acc.getBalance() << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account Not Found!\n";
                break;
            }
            case 5: {
                cout << "Enter Account Number: ";
                cin >> accNum;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.displayAccount();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account Not Found!\n";
                break;
            }
            case 6:
                cout << "Thank you for using the Bank Management System!\n";
                return 0;
            default:
                cout << "Invalid Choice! Please Try Again.\n";
        }
    }
    return 0;
}
