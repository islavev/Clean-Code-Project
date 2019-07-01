#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include"CustomerAccount.h"
#include<iostream>
#include<cstring>

CustomerAccount::CustomerAccount(char* IBAN, int customerID, double accountBalance) {
	createCustomerAccount(IBAN, customerID, accountBalance);
}

CustomerAccount::CustomerAccount(const CustomerAccount& other) {
	createCustomerAccount(other.getIBAN(), other.getCustomerID(), other.getBalance());
}

CustomerAccount& CustomerAccount::operator=(const CustomerAccount& other) {
	if (this != &other) {
		delete[] IBAN;
		createCustomerAccount(other.getIBAN(), other.getCustomerID(), other.getBalance());
	}
	return *this;
}

CustomerAccount::~CustomerAccount() {
	delete[] IBAN;
}

double CustomerAccount::getBalance() const {
	return accountBalance;
}

char* CustomerAccount::getIBAN() const {
	return IBAN;
}

int CustomerAccount::getCustomerID() const {
	return customerID;
}

void CustomerAccount::createCustomerAccount(char* IBAN, int customerID, double accountBalance) {
	this->IBAN = new char[strlen(IBAN) + 1];
	strcpy(this->IBAN, IBAN);

	if (customerID >= 0) {
		this->customerID = customerID;
	}

	if (accountBalance >= 0) {
		this->accountBalance = accountBalance;
	}
}