#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===============================
// BASE CLASS
// ===============================
class Account
{
protected:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    Account()
    {
        accountNumber = 0;
        accountHolder = "";
        balance = 0;
    }

    // Parameterized Constructor
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        accountHolder = name;
        balance = bal;
    }

    // Virtual Function - Polymorphism
    virtual void displayAccount()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolder;
        cout << "\nBalance        : Rs. " << balance << endl;
    }

    // Deposit Function
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    // Withdrawal Function
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    // Getter
    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    // Virtual Destructor
    virtual ~Account() {}
};


// ===============================
// SAVINGS ACCOUNT - INHERITANCE
// ===============================
class SavingsAccount : public Account
{
private:
    double interestRate;

public:

    SavingsAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal)
    {
        interestRate = rate;
    }

    // Function Overriding - Polymorphism
    void displayAccount() override
    {
        cout << "\n----- SAVINGS ACCOUNT -----";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolder;
        cout << "\nBalance        : Rs. " << balance;
        cout << "\nInterest Rate  : " << interestRate << "%\n";
    }

    void addInterest()
    {
        double interest = balance * interestRate / 100;
        balance += interest;

        cout << "Interest added successfully!\n";
        cout << "New Balance: Rs. " << balance << endl;
    }
};


// ===============================
// CURRENT ACCOUNT - INHERITANCE
// ===============================
class CurrentAccount : public Account
{
private:
    double minimumBalance;

public:

    CurrentAccount(int accNo, string name, double bal, double minBal)
        : Account(accNo, name, bal)
    {
        minimumBalance = minBal;
    }

    // Function Overriding - Polymorphism
    void displayAccount() override
    {
        cout << "\n----- CURRENT ACCOUNT -----";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Holder : " << accountHolder;
        cout << "\nBalance        : Rs. " << balance;
        cout << "\nMinimum Balance: Rs. " << minimumBalance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > 0 && balance - amount >= minimumBalance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        }
        else
        {
            cout << "Withdrawal not allowed!\n";
            cout << "Minimum balance must be maintained.\n";
        }
    }
};


// ===============================
// MAIN FUNCTION
// ===============================
int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n       BANK MANAGEMENT SYSTEM";
        cout << "\n====================================";
        cout << "\n1. Create Savings Account";
        cout << "\n2. Create Current Account";
        cout << "\n3. Display Savings Account";
        cout << "\n4. Display Current Account";
        cout << "\n5. Deposit Money";
        cout << "\n6. Withdraw from Savings Account";
        cout << "\n7. Add Interest";
        cout << "\n8. Save Account Data";
        cout << "\n9. Exit";
        cout << "\n====================================";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int accNo;
            string name;
            double balance, rate;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Account Holder Name: ";
            cin >> name;

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Interest Rate: ";
            cin >> rate;

            SavingsAccount savings(accNo, name, balance, rate);

            savings.displayAccount();

            break;
        }

        case 2:
        {
            int accNo;
            string name;
            double balance, minimumBalance;

            cout << "\nEnter Account Number: ";
            cin >> accNo;

            cout << "Enter Account Holder Name: ";
            cin >> name;

            cout << "Enter Initial Balance: ";
            cin >> balance;

            cout << "Enter Minimum Balance: ";
            cin >> minimumBalance;

            CurrentAccount current(
                accNo,
                name,
                balance,
                minimumBalance
            );

            current.displayAccount();

            break;
        }

        case 3:
        {
            SavingsAccount savings(
                101,
                "Anchal",
                5000,
                5
            );

            savings.displayAccount();

            break;
        }

        case 4:
        {
            CurrentAccount current(
                102,
                "Rahul",
                10000,
                2000
            );

            current.displayAccount();

            break;
        }

        case 5:
        {
            SavingsAccount savings(
                101,
                "Anchal",
                5000,
                5
            );

            double amount;

            cout << "Enter deposit amount: ";
            cin >> amount;

            savings.deposit(amount);
            savings.displayAccount();

            break;
        }

        case 6:
        {
            SavingsAccount savings(
                101,
                "Anchal",
                5000,
                5
            );

            double amount;

            cout << "Enter withdrawal amount: ";
            cin >> amount;

            savings.withdraw(amount);
            savings.displayAccount();

            break;
        }

        case 7:
        {
            SavingsAccount savings(
                101,
                "Anchal",
                5000,
                5
            );

            savings.addInterest();

            break;
        }

        case 8:
        {
            ofstream file("bank_data.txt");

            file << "BANK MANAGEMENT SYSTEM\n";
            file << "Account Number: 101\n";
            file << "Account Holder: Anchal\n";
            file << "Account Type: Savings Account\n";
            file << "Balance: Rs. 5000\n";

            file.close();

            cout << "\nAccount data saved successfully!\n";

            break;
        }

        case 9:
            cout << "\nThank you for using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}