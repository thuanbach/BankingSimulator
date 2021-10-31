/*
 * Savings_Account.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: Thuan Bach
 */

#include "Savings_Account.h"
#include "Date.h"

void Savings_Account::deposit(const double amount, const Date &date) {
	process_transaction(DEPOSITE, amount, date);
}

void Savings_Account::withdraw(const double amount, const Date &date) {
	bool overdraft = amount > get_balance();

	process_transaction(WITHDRAW, amount, date);

	if (overdraft) {
		process_transaction(OVERDRAFT, get_customer()->get_overdraft_penality(), date);
	}

}

void Savings_Account::add_interest(const Date &date) {
	if (!has_interest(date)) {
		return;
	}

	double amount = calculate_interest_amount(
			get_customer()->get_savings_interest(), date);

	process_transaction(INTEREST, amount, date);
}
