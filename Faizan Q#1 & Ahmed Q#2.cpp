//
//  main.cpp
//  Q#1
//
//  Created by Afaq Ahmed on 18/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#include <iostream>
using namespace std;
class Account {
protected:
    double balance;
public:
    // Constructor
    Account(double initBalance);
    
    // Member methods
    bool credit(double amount);
    bool debit(double amount);
    double get_balance() const;
};

Account::Account(double initBalance) {
    if(initBalance >= 0){
        balance = initBalance;
    }else{
        cout << "The initial balance was invalid" << endl;
        balance = 0.0;
    }
}

bool Account::credit(double amount) {
    if (amount < 0) {
        return false;
    }else{
        balance += amount;
        return true;
    }
}

bool Account::debit(double amount){
    if (balance-amount >= 0) {
        balance -= amount;
        return true;
    }else{
        cout << "Debit amount exceeded amount balance" << endl;
        return false;
    }
}

double Account::get_balance() const {
    return balance;
}

//MARK: - SavingAccount

class SavingAccount : public Account {
private:
    double intRate;
public:
    SavingAccount(double initBalance = 0.0, double intRate = 0.0);
    
    // Member methods
    double calculateInterest();
};

SavingAccount::SavingAccount(double initBalance, double intRate)
: Account{initBalance}, intRate(intRate) {  }

double SavingAccount::calculateInterest() {
    double totalInt = balance * (intRate/100);
    return totalInt;
}

//MARK: - CheckingAccount
class CheckingAccount : public Account {
private:
    double fee;
public:
    CheckingAccount(double blnc, double fees);
    bool credit(double amount);
    bool debit(double amount);
};

CheckingAccount::CheckingAccount(double blnc, double fees)
:Account(blnc), fee(fees)   {   }

bool CheckingAccount::credit(double amount) {
    return Account::credit(amount);
}

bool CheckingAccount::debit(double amount) {
    if (balance-amount >= 0) {
        balance -= amount - fee;
        return true;
    }else{
        return false;
    }
}

int main() {
    
    Account acc1{0.0};
    if (acc1.credit(20000)) {
        cout << "credit successfull" << endl;
    }else
        cout << "Error crediting..." << endl;
    
    if (acc1.debit(4000)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    if (acc1.debit(200)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    if (acc1.debit(3000)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    if (acc1.debit(2000)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    //MARK: - SavingAccount testing
    SavingAccount acc2{20000, 1.5};
    
    
    acc2.credit(acc2.calculateInterest());
    
    cout << "Account Balance now, After interest : " << acc2.get_balance() << endl;
    
    //MARK: - CheckingAccount testing
    CheckingAccount acc3{20000, 1.5};
    
    if (acc3.credit(20000)) {
        cout << "credit successfull" << endl;
    }else
        cout << "Error crediting..." << endl;
    
    if (acc3.debit(4000)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    if (acc3.debit(200)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    if (acc3.debit(3000)) {
        cout << "Withdrawn successfully" <<endl;
    }else
        cout << "Error occur while debit." << endl;
    
    
    return 0;
}
