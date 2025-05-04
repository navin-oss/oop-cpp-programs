#include <iostream>
#include <string>
using namespace std;

class Bank {
public:
    void deposit(int amount) { cout << "Depositing ?" << amount << " in cash.\n"; }
    void deposit(float amount) { cout << "Depositing ?" << amount << " via digital payment.\n"; }
    void deposit(string upi, int amount) { cout << "Depositing ?" << amount << " using UPI (" << upi << ").\n"; }
};

class Account {
    int accNo;
    float bal;
public:
    Account(int n, float b) : accNo(n), bal(b) {}
    
    Account operator+(Account &a) {
        bal -= 3000;
        a.bal += 3000;
        cout << "Transferring ?3000 from Account " << accNo << " to Account " << a.accNo << "...\n";
        return *this;
    }
    
    void operator-(float amount) {
        bal -= amount;
        cout << "Withdrawing ?" << amount << " from Account " << accNo << "...\n";
    }
    
    void show() { cout << "Account " << accNo << " Balance: ?" << bal << "\n"; }
};

int main() {
    Bank b;
    b.deposit(5000);
    b.deposit(1500.75f);
    b.deposit("gpay@upi", 2500);
    cout << "\n";
    
    Account a1(1, 10000), a2(2, 5000);
    a1.show();
    a2.show();
    
    a1 + a2;
    cout << "New "; a1.show();
    cout << "New "; a2.show();
    
    a1 - 2000;
    cout << "Remaining "; a1.show();
    
    return 0;
}                
