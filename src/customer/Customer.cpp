/**
 *
 * @file Customer.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This module is used to store customers' information such as name, age, address, or phone number.
 * There are 3 derived classes from the Customer class. Each kind of customer will have its own interest rates,
 * checking charges or overdraft penalty
 *
 */
#include <iostream>
#include "Customer.h"

using namespace std;

string Customer::get_name() const {
	return name;
}

string Customer::get_address() const {
	return address;
}

int Customer::get_age() const {
	return age;
}

string Customer::get_telephone_number() const {
	return phone_number;
}

int Customer::get_customer_number() const {
	return customer_number;
}

void Customer::set_name(string &name) {
	this->name = name;
}

void Customer::set_address(string &address) {
	this->address = address;
}

void Customer::set_age(int age) {
	this->age = age;
}

void Customer::set_telephone_number(string &phone_number) {
	this->phone_number = phone_number;
}

void Customer::set_customer_number(int customer_number) {
	this->customer_number = customer_number;
}
