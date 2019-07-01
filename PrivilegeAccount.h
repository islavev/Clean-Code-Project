#pragma once
#include"CustomerAccount.h"

class PrivilegeAccount : public CustomerAccount {
public:
	PrivilegeAccount(char* IBAN, int customerID, double accountBalance, double overdraft = 30.0);
	PrivilegeAccount(const PrivilegeAccount& other);
	PrivilegeAccount& operator=(const PrivilegeAccount& other);
	double getOverdraft() const;
	void depositMoney(double moneyToDeposit);
	bool withdrawMoney(double moneyToWithdraw);
	void displayAccountData() const;

private:
	double overdraft;
};