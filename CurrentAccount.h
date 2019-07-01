#pragma once
#include"CustomerAccount.h"

class CurrentAccount : public CustomerAccount {
public:
	CurrentAccount(char* IBAN, int customerID, double accountBalance);
	CurrentAccount(const CurrentAccount& other);
	CurrentAccount& operator=(const CurrentAccount& other);
	void depositMoney(double moneyToDeposit);
	bool withdrawMoney(double moneyToWithdraw);
	void displayAccountData() const;
};