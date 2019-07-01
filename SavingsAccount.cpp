#include"CustomerAccount.h"
#include"SavingsAccount.h"
#include<iostream>
using namespace std;

SavingsAccount::SavingsAccount(char* IBAN, int customerID, double accountBalance, double annualInterestRate) : CustomerAccount(IBAN, customerID, accountBalance) {
	if (annualInterestRate > 0) {
		this->annualInterestRate = annualInterestRate;
	}
}

SavingsAccount::SavingsAccount(const SavingsAccount& other) : CustomerAccount(other) {
	annualInterestRate = other.getAnnualInterestRate();
}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other) {
	if (this != &other) {
		CustomerAccount::operator=(other);
		annualInterestRate = other.getAnnualInterestRate();
	}
	return *this;
}

double SavingsAccount::getAnnualInterestRate() const {
	return annualInterestRate;
}

void SavingsAccount::depositMoney(double moneyToDeposit) {
	if (moneyToDeposit > 0) {
		accountBalance += moneyToDeposit;
	}
}

bool SavingsAccount::withdrawMoney(double moneyToWithdraw) {
	if (moneyToWithdraw < 0) {
		return false;
	}

	if (accountBalance - moneyToWithdraw < 0) {
		return false;
	}

	accountBalance -= moneyToWithdraw;
	return true;
}

void SavingsAccount::displayAccountData() const {
	cout << "Type: Savings" << endl
		<< "IBAN: " << getIBAN() << endl
		<< "Customer No.: " << getCustomerID() << endl
		<< "Balance: " << getBalance() << endl
		<< "Interest Rate: " << getAnnualInterestRate() << endl << endl;
}

