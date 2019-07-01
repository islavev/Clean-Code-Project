#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"Bank.h"
#include<iostream>

const int NO_CUSTOMER = -1, NO_ACCOUNT = -1;

Bank::Bank(char* bankName, char* bankAddress) {
	createBank(bankName,bankAddress);
}

Bank::Bank(const Bank& other) {
	createBank(other.getBankName(), other.getBankAddress());
}

Bank& Bank::operator=(const Bank& other) {
	if (this != &other) {
		delete[] bankName;
		delete[] bankAddress;
		createBank(other.getBankName(), other.getBankAddress());
	}
	return *this;
}

Bank::~Bank()
{
	delete[] bankName;
	delete[] bankAddress;
}

char* Bank::getBankName() const {
	return bankName;
}

char* Bank::getBankAddress() const {
	return bankAddress;
}

void Bank::addCustomer(int customerID, char* customerName, char* customerAddress) {
	if (customerID < 0) {
		return;
	}

	if (findCustomer(customerID) > NO_CUSTOMER) {
		std::cout << "Customer already exists!" << std::endl;
		return;
	}
	customers.push_back(new Customer(customerID, customerName, customerAddress));
}

void Bank::deleteCustomer(int customerID) {
	if (customerID < 0) {
		std::cout << "Customer's ID must be positive number" << std::endl;
		return;
	}

	int customerIndex = findCustomer(customerID);
	if (customerIndex == NO_CUSTOMER) {
		std::cout << "There is no such customer!" << std::endl;
		return;
	}

	std::vector<Customer*>::iterator customerToDelete = customers.begin() + customerIndex;
	delete *customerToDelete;
	customers.erase(customerToDelete);

	std::vector<CustomerAccount*>::iterator accountToDelete;
	for (accountToDelete = accounts.begin(); accountToDelete != accounts.end();) {
		if ((*accountToDelete)->getCustomerID() == customerID) {
			delete *accountToDelete;
			accountToDelete = accounts.erase(accountToDelete);
		}
		else {
			++accountToDelete;
		}
	}
}

void Bank::addCustomerAccount(AccountType type, char* accountIBAN, int customerID, double accountBalance) {
	if (findCustomer(customerID) == NO_CUSTOMER || findCustomerAccount(accountIBAN) >= 0) {
		std::cout << "Can't add new account: no such customer or account already exists!" << std::endl;
		return;
	}
	if (accountBalance >= 0 && customerID >= 0) {
		accounts.push_back(AccountFactory::generateCustomerAccount(type, accountIBAN, customerID, accountBalance));
	}
}

void Bank::deleteCustomerAccount(char* accountIBAN) {
	int accountIndex = findCustomerAccount(accountIBAN);
	if (accountIndex == NO_ACCOUNT) {
		std::cout << "There is no such account!" << std::endl;
		return;
	}

	std::vector<CustomerAccount*>::iterator accountToDelete = accounts.begin() + accountIndex;
	delete *accountToDelete;
	accounts.erase(accountToDelete);
}

void Bank::depositMoneyToAccount(char* accountIBAN, double moneyToDeposit) {
	int account = findCustomerAccount(accountIBAN);
	if (account == NO_ACCOUNT) {
		std::cout << "There is no such account!" << std::endl;
		return;
	}

	if (moneyToDeposit > 0) {
		accounts[account]->depositMoney(moneyToDeposit);
		std::cout << "Successfully deposited " << moneyToDeposit << "." << std::endl;
	}
}

void Bank::withdrawMoneyFromAccount(char* accountIBAN, double moneyToWithdraw) {
	int account = findCustomerAccount(accountIBAN);
	if (account == NO_ACCOUNT) {
		std::cout << "There is no such account!" << std::endl;
		return;
	}

	if (moneyToWithdraw < 0) {
		std::cout << "Desired amount to withdraw must be greater than 0" << std::endl;
	}

	if (!accounts[account]->withdrawMoney(moneyToWithdraw)) {
		std::cout << "Insufficient money!" << std::endl;
	}
	else std::cout << "Succesfully withdrawed " << moneyToWithdraw << "." << std::endl;
}

void Bank::transferMoneyToAccount(char* senderAccountIBAN, char* receiverAccountIBAN, double moneyToTransfer) {
	if (moneyToTransfer < 0) {
		std::cout << "Transfered amount of money must be greater than zero." << std::endl;
		return;
	}

	int sender = findCustomerAccount(senderAccountIBAN);
	int receiver = findCustomerAccount(receiverAccountIBAN);
	if (sender == NO_ACCOUNT || receiver == NO_ACCOUNT) {
		std::cout << "No such account!" << std::endl;
		return;
	}

	if (!accounts[sender]->withdrawMoney(moneyToTransfer)) {
		std::cout << "Insufficient money!" << std::endl;
		return;
	}

	accounts[receiver]->depositMoney(moneyToTransfer);
	std::cout << "Successfully transfered " << moneyToTransfer << " from " << senderAccountIBAN << " to " << receiverAccountIBAN << "." << std::endl;
}

void Bank::displayAllCustomers() const {
	for (int i = 0; i < customers.size(); ++i) {
		customers[i]->displayCustomerData();
	}
}

void Bank::displayAllAccounts() const {
	if (accounts.size() == 0) {
		std::cout << "There are currently no accounts." << std::endl;
		return;
	}

	for (int i = 0; i < accounts.size(); ++i) {
		accounts[i]->displayAccountData();
		std::cout << std::endl;
	}
}

void Bank::displayCustomerAccounts(int customerID) const {
	if (customerID < 0) {
		std::cout << "Customer's ID must be positive number" << std::endl;
		return;
	}

	if (findCustomer(customerID) == NO_CUSTOMER) {
		std::cout << "There is no such customer in the bank!" << std::endl;
		return;
	}

	int foundAccounts = 0;
	for (int i = 0; i < accounts.size(); ++i) {
		if (accounts[i]->getCustomerID() == customerID) {
			accounts[i]->displayAccountData();
			++foundAccounts;
		}
	}

	if (foundAccounts == 0) {
		std::cout << "The customer doesn't have any accounts!" << std::endl;
	}
}

void Bank::displayBankData() const {
	std::cout << "Name: " << bankName << std::endl
		<< "Address: " << bankAddress << std::endl
		<< "Customers count: " << customers.size() << std::endl
		<< "Accounts count: " << accounts.size() << std::endl;
}

void Bank::createBank(char* bankName, char* bankAddress) {
	this->bankName = new char[strlen(bankName) + 1];
	strcpy(this->bankName, bankName);

	this->bankAddress = new char[strlen(bankAddress) + 1];
	strcpy(this->bankAddress, bankAddress);
}

int Bank::findCustomer(int customerID) const {
	if (customerID < 0) {
		return NO_CUSTOMER;
	}

	for (int i = 0; i < customers.size(); ++i) {
		if (customers[i]->getID() == customerID) {
			return i;
		}
	}
	return NO_CUSTOMER;
}

int Bank::findCustomerAccount(char* accountIBAN) const {
	for (int i = 0; i < accounts.size(); ++i) {
		if (strcmp(accounts[i]->getIBAN(), accountIBAN) == 0) {
			return i;
		}
	}
	return NO_ACCOUNT;
}