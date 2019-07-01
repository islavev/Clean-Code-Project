#pragma once
#include<vector>
#include"Customer.h"
#include"CurrentAccount.h"
#include"CustomerAccount.h"
#include"PrivilegeAccount.h"
#include"SavingsAccount.h"
#include"AccountFactory.h"

class Bank {
public:
	Bank(char* bankName, char* bankAddress);
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);
	~Bank();
	char* getBankName() const;
	char* getBankAddress() const;
	void addCustomer(int customerID, char* customerName, char* customerAddress);
	void deleteCustomer(int customerID);
	void addCustomerAccount(AccountType accountType, char* IBAN, int customerID, double accountBalance);
	void deleteCustomerAccount(char* IBAN);
	void depositMoneyToAccount(char* IBAN, double moneyToDeposit);
	void withdrawMoneyFromAccount(char* IBAN, double moneyToWithdraw);
	void transferMoneyToAccount(char* senderAccountIBAN, char* receiverAccountIBAN, double moneyToTransfer);
	void displayAllCustomers() const;
	void displayAllAccounts() const;
	void displayCustomerAccounts(int customerID) const;
	void displayBankData() const;

private:
	char* bankName;
	char* bankAddress;
	std::vector<Customer*> customers;
	std::vector<CustomerAccount*> accounts;
	void createBank(char* bankName, char* bankAddress);
	int findCustomer(int customerID) const;
	int findCustomerAccount(char* IBAN) const;
};