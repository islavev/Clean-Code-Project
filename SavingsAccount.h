#pragma once

class SavingsAccount : public CustomerAccount {
public:
	SavingsAccount(char* IBAN, int customerID, double accountBalance, double annualInterestRate = 0.05);
	SavingsAccount(const SavingsAccount& other);
	SavingsAccount& operator=(const SavingsAccount& other);
	double getAnnualInterestRate() const;
	void depositMoney(double moneyToDeposit);
	bool withdrawMoney(double moneyToWithdraw);
	void displayAccountData() const;

private:
	double annualInterestRate;
};