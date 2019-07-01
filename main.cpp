#include"Bank.h"
#include<iostream>
using namespace std;

const int MAX_LENGTH = 250;

void displayMenuOptions() {
	cout << endl;
	cout << "1 Display all customers\n"
		<< "2 Add new customer\n"
		<< "3 Delete customer\n"
		<< "4 Display all accounts\n"
		<< "5 Display customer accounts\n"
		<< "6 Add new account\n"
		<< "7 Delete account\n"
		<< "8 Withdraw from account\n"
		<< "9 Deposit to account\n"
		<< "10 Transfer\n"
		<< "11 Display bank credentials\n"
		<< "12 Quit" << endl;
	cout << endl;
}

int main() {
	bool isRunning = true;
	int menuOption = 0;

	Bank fibank("Fibank", "Sofia, Bulgaria");

	while (isRunning)
	{
		cout << "Display menu options - YES(y)/NO(n) ? ";
		char menu;
		cin >> menu;
		if (menu == 'y') {
			displayMenuOptions();
		}

		cout << "Enter option : "; 
		cin >> menuOption;
		if (menuOption == 1) {
			fibank.displayAllCustomers();
		}
		else if (menuOption == 2) {
			int customerID;
			cout << "CustomerID (must be positive number): ";
			cin >> customerID;
			cin.ignore();
			char customerName[MAX_LENGTH], customerHomeAddress[MAX_LENGTH];
			cout << "Name: "; cin.getline(customerName, MAX_LENGTH - 1, '\n');
			cout << "Address: "; cin.getline(customerHomeAddress, MAX_LENGTH - 1, '\n');
			fibank.addCustomer(customerID, customerName, customerHomeAddress);
		}
		else if (menuOption == 3) {
			int customerID;
			cout << "CustomerID (must be positive number): ";
			cin >> customerID;
			fibank.deleteCustomer(customerID);
		}
		else if (menuOption == 4) {
			fibank.displayAllAccounts();
		}
		else if (menuOption == 5) {
			int customerID;
			cout << "CustomerID (must be positive number): "; 
			cin >> customerID;
			fibank.displayCustomerAccounts(customerID);
		}
		else if (menuOption == 6) {
			int accountType;
			cout << "AccountType (Current - 0, Savings - 1, Privilege - 2): ";
			cin >> accountType;

			int customerID;
			cout << "CustomerID (must be positive number): ";
			cin >> customerID;

			char IBAN[MAX_LENGTH];
			cout << "IBAN: ";
			cin >> IBAN;

			double accountBalance;
			cout << "Initial account balance: "; 
			cin >> accountBalance;

			fibank.addCustomerAccount((AccountType)accountType, IBAN, customerID, accountBalance);
		}
		else if (menuOption == 7) {
			char IBAN[MAX_LENGTH];
			cout << "IBAN: "; 
			cin >> IBAN;

			fibank.deleteCustomerAccount(IBAN);
		}
		else if (menuOption == 8) {
			char IBAN[MAX_LENGTH];
			cout << "Enter IBAN: ";
			cin >> IBAN;

			double amountToWithdraw;
			cout << "Enter amount: "; 
			cin >> amountToWithdraw;

			fibank.withdrawMoneyFromAccount(IBAN, amountToWithdraw);
		}
		else if (menuOption == 9) {
			char IBAN[MAX_LENGTH];
			cout << "Enter IBAN: ";
			cin >> IBAN;

			double amountToDeposit;
			cout << "Enter amount: "; 
			cin >> amountToDeposit;

			fibank.depositMoneyToAccount(IBAN, amountToDeposit);
		}
		else if (menuOption == 10) {
			char fromIBAN[MAX_LENGTH];
			cout << "Enter IBAN to withdraw from: ";
			cin >> fromIBAN;

			char toIBAN[MAX_LENGTH];
			cout << "Enter IBAN to transfer to: ";
			cin >> toIBAN;

			double amount;
			cout << "Enter amount: "; 
			cin >> amount;

			fibank.transferMoneyToAccount(fromIBAN, toIBAN, amount);
		}
		else if (menuOption == 11) {
			fibank.displayBankData();
		}
		else if (menuOption == 12) {
			isRunning = false;
		}
		else {
			cout << "Invalid option!" << endl;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}