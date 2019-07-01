#pragma once
#include"CustomerAccount.h"
#include"CurrentAccount.h"
#include"SavingsAccount.h"
#include"PrivilegeAccount.h"

enum AccountType { Current, Savings, Privilege };

class AccountFactory {
public:
	static CustomerAccount* generateCustomerAccount(AccountType type, char* IBAN, int customerID, double accountBalance);
};