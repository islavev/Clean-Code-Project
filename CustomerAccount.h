#pragma once

class CustomerAccount {
public:
	CustomerAccount(char* IBAN, int customerID, double accountBalance);
	CustomerAccount(const CustomerAccount& other);
	CustomerAccount& operator=(const CustomerAccount& other);
	virtual ~CustomerAccount();
	double getBalance() const;
	char* getIBAN() const;
	int getCustomerID() const;
	virtual void depositMoney(double moneyToDeposit) = 0;
	virtual bool withdrawMoney(double moneyToWithdraw) = 0;
	virtual void displayAccountData() const = 0;

protected:
	double accountBalance;

private:
	char* IBAN;
	int customerID;
	void createCustomerAccount(char* IBAN, int customerID, double accoutBalance);
};