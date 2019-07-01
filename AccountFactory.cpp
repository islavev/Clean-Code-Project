#include"AccountFactory.h"
#include<iostream>

CustomerAccount* AccountFactory::generateCustomerAccount(AccountType type, char* IBAN, int customerID, double accountBalance) {
	if (type == AccountType::Current) {
		return new CurrentAccount(IBAN, customerID, accountBalance);
	}
	
	if (type == AccountType::Savings) {
		return new SavingsAccount(IBAN, customerID, accountBalance);
	}

	if (type == AccountType::Privilege) {
		return new PrivilegeAccount(IBAN, customerID, accountBalance);
	}
	return NULL;
}