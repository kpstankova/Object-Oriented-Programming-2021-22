#include "bankAccount.h"

// BankAccount::BankAccount() {
//     balance = 0;
// }

BankAccount::BankAccount(const Person& _owner, double _balance) : owner(_owner), balance(_balance) {}

void BankAccount::withdraw(double amount) {
    balance -= amount;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

void BankAccount::setOwner(const Person& owner) {
    this->owner = owner;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

const Person& BankAccount::getOwner() const {
    return this->owner;
}

double BankAccount::getBalance() const {
    return this->balance;
}