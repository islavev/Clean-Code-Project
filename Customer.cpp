#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"Customer.h"
#include<cstring>
#include<iostream>

Customer::Customer(int ID, char* customerName, char* homeAddress) {
	createCustomer(ID, customerName, homeAddress);
}

Customer::Customer(const Customer& other) {
	createCustomer(other.getID(), other.getCustomerName(), other.getHomeAddress());
}

Customer& Customer::operator=(const Customer& other) {
	if (this != &other) {
		delete[] customerName;
		delete[] homeAddress;
		createCustomer(other.getID(), other.getCustomerName(), other.getHomeAddress());
	}
	return *this;
}

Customer::~Customer() {
	delete[] customerName;
	delete[] homeAddress;
}

int Customer::getID() const {
	return ID;
}

char* Customer::getCustomerName() const {
	return customerName;
}

char* Customer::getHomeAddress() const {
	return homeAddress;
}

void Customer::displayCustomerData() const {
	std::cout << "Customer: " << getID() 
		<< " " << getCustomerName()
		<< " " << getHomeAddress() << std::endl;
}

void Customer::createCustomer(int ID, char* customerName, char* homeAddress) {
	this->ID = ID;

	this->customerName = new char[strlen(customerName) + 1];
	strcpy(this->customerName, customerName);

	this->homeAddress = new char[strlen(homeAddress) + 1];
	strcpy(this->homeAddress, homeAddress);
}