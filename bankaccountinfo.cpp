#include <iostream>
#include <string>
using namespace std;

class Bank_Account
{
    private:
        string account_name;
        string account_number;
        int curr_balance;

    public:
        Bank_Account() : curr_balance(0)
        {
            cout << "Enter Account Holder Name: ";
            getline(cin, account_name);
            cout << "Enter Account Number: ";
            cin >> account_number;
            cout << "Account created successfully!\n";
        }

        void getInfo()
        {
            int choice;
            do {
                cout << "\n---------- Menu ----------";
                cout << "\n1. Credit";
                cout << "\n2. Debit";
                cout << "\n3. Display Mini Statement";
                cout << "\n4. Exit";
                cout << "\nEnter your choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                    {
                        int credit_amount;
                        cout << "Enter the amount to credit: ";
                        cin >> credit_amount;
                        curr_balance += credit_amount;
                        cout << "Credited successfully!\n";
                        break;
                    }
                    case 2:
                    {
                        int debit_amount;
                        cout << "Enter the amount to debit: ";
                        cin >> debit_amount;
                        if(curr_balance >= debit_amount)
                        {
                            curr_balance -= debit_amount;
                            cout << "Debited successfully!\n";
                        }
                        else
                        {
                            cout << "Insufficient balance!\n";
                        }
                        break;
                    }
                    case 3:
                    {
                        cout << "\n---------- Mini Statement ----------";
                        cout << "\nAccount Holder: " << account_name;
                        cout << "\nAccount Number: " << account_number;
                        cout << "\nCurrent Balance: " << curr_balance << endl;
                        break;
                    }
                    case 4:
                        cout << "Exiting... Thank you!\n";
                        break;
                    default:
                        cout << "Invalid choice! Please try again.\n";
                }
            } while (choice != 4);
        }
};

int main()
{
    Bank_Account acc1;
    acc1.getInfo();
    return 0;
}

