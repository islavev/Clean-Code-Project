#include"PrivilegeAccount.h"
#include<iostream>
using namespace std;

PrivilegeAccount::PrivilegeAccount(char* IBAN, int customerID, double accountBalance, double overdraft) : CustomerAccount(IBAN, customerID, accountBalance) {
	if (overdraft > 0) {
		this->overdraft = overdraft;
	}
	else {
		this->overdraft = 0;
	}
}

PrivilegeAccount::PrivilegeAccount(const PrivilegeAccount& other) : CustomerAccount(other) {
	overdraft = other.getOverdraft();
}

PrivilegeAccount& PrivilegeAccount::operator=(const PrivilegeAccount& other) {
	if (this != &other) {
		CustomerAccount::operator=(other);
		overdraft = other.getOverdraft();
	}
	return *this;
}

double PrivilegeAccount::getOverdraft() const {
	return overdraft;
}


void PrivilegeAccount::depositMoney(double moneyToDeposit) {
	if (moneyToDeposit > 0) {
		accountBalance += moneyToDeposit;
	}
}

bool  PrivilegeAccount::withdrawMoney(double moneyToWithdraw) {
	if (moneyToWithdraw < 0) {
		return false;
	}

	if ((accountBalance + overdraft) - moneyToWithdraw < 0) {
		return false;
	}

	accountBalance -= moneyToWithdraw;
	return true;
}

void PrivilegeAccount::displayAccountData() const {
	cout << "Type: Privilege" << endl
		<< "IBAN: " << getIBAN() << endl
		<< "Customer No.: " << getCustomerID() << endl
		<< "Balance: " << getBalance() << endl
		<< "Overdraft: " << getOverdraft() << endl << endl;
}
