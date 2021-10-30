/*
 * Savings_Account.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: Thuan Bach
 */

#include "Savings_Account.h"
#include "Date.h"




void Savings_Account::deposit(const double amount, const Date &date){
	process_transaction(DEPOSITE, amount, date);
}

void Savings_Account::withdraw(const double amount,const Date &date){

	if (get_balance() < amount) {
		cout << "ERROR: The current balance is less than the withdraw amount";
	} else {
		set_balance(get_balance() - amount);
	}

}

void Savings_Account::add_interest(const Date &date) {
	if (!has_interest(date)){
		return;
	}

	double amount = calculate_interest_amount(get_customer()->get_savings_interest(), date);

	process_transaction(INTEREST, amount, date);
}
