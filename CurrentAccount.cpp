#include"CurrentAccount.h"
#include<iostream>
using namespace std;

CurrentAccount::CurrentAccount(char* IBAN, int customerID, double accountBalance) : CustomerAccount(IBAN, customerID, accountBalance) {
}

CurrentAccount::CurrentAccount(const CurrentAccount& other) : CustomerAccount(other) {
}

CurrentAccount& CurrentAccount::operator=(const CurrentAccount& other) {
	if (this != &other) {
		CustomerAccount::operator=(other);
	}
	return *this;
}

void CurrentAccount::depositMoney(double moneyToDeposit) {
	if (moneyToDeposit > 0) {
		accountBalance += moneyToDeposit;
	}
}

bool CurrentAccount::withdrawMoney(double moneyToWithdraw) {
	if (moneyToWithdraw < 0) {
		return false;
	}

	if (accountBalance - moneyToWithdraw < 0) {
		return false;
	}

	accountBalance -= moneyToWithdraw;
	return true;
}

void CurrentAccount::displayAccountData() const {
	cout << "Type: Current" << endl
		<< "IBAN: " << getIBAN() << endl
		<< "Customer No.: " << getCustomerID() << endl
		<< "Balance: " << getBalance() << endl << endl;
}