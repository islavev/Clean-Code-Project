#pragma once

class Customer {
public:
	Customer(int ID, char* customerName, char* homeAddress);
	Customer(const Customer& other);
	Customer& operator=(const Customer& other);
	~Customer();
	int getID() const;
	char* getCustomerName() const;
	char* getHomeAddress() const;
	void displayCustomerData() const;

private:
	int ID;
	char* customerName;
	char* homeAddress;
	void createCustomer(int ID, char* customerName, char* homeAddress);
};