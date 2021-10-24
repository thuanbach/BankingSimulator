/*
 * Account.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: Thuan Bach
 */
#include "Account.h"
#include <sstream>



double Account::get_balance() const{
	return balance;
}

int Account::get_account_number() const{
	return account_number;
}

Customer* Account::get_customer() const{
	return customer;
}

string Account::to_string() const{
	ostringstream result;
	result << "Account: " << account_number << endl;
	result << "Owner: " << customer->get_name() <<endl;

	// TODO: Seems it not correct
	//result << "Type of customer: " << typeid(Customer) << endl;
	result << "Balance: " << balance << endl;

	for (int i=0; i<number_of_transactions;i++) {
		transactions[i].to_string();
	}

	return result.str();

}

void Account::set_customer(Customer &customer){
	// TODO: Please check if it correct
	this->customer = &customer;
}
void Account::set_balance(double new_balance) {
	this->balance = new_balance;
}
