/**
 *
 * @file Checking_Account.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This class extends from the Account to implement functionalities for a checking account.
 * Functionalities for each kind of accounts are different.
 *
 */

#include <iostream>
#include "Checking_Account.h"
#include "TransactionType.h"
#include "Transaction.h"

using namespace std;

int Checking_Account::calculate_days_from_last_transaction(const Date &date) const {

	Date* latest_transaction_date  = get_latest_transaction_date();

	if ( latest_transaction_date == NULL){
		return 0;
	}

	int difference_in_days = -(*latest_transaction_date - date);

	return difference_in_days;
}


void Checking_Account::deposit(const double amount, const Date &date) {

	process_transaction(DEPOSITE, amount, date);
}

void Checking_Account::withdraw(const double amount, const Date &date) {

	bool overdraft = amount > get_balance();

	process_transaction(WITHDRAW, amount, date);

	// If checking_charge is empty, don't add transaction
	float withdraw_charge = get_customer()->get_checking_charge();
	if (withdraw_charge > 0) {
		process_transaction(CHKCHG, withdraw_charge, date);
	}

	if (overdraft) {
		process_transaction(OVERDRAFT, get_customer()->get_overdraft_penality(),
				date);
	}

}

void Checking_Account::add_interest(const Date &date) {

	int nr_of_days = calculate_days_from_last_transaction(date);

	// Don't calculate interest if balance is negative due to overdraft is charged
	// OR number of days from the last transaction is 0
	if (get_balance() <= 0 || nr_of_days == 0) {
		return;
	}

	// interest will be calculated daily
	double interest_per_day = (double) get_customer()->get_checking_interest()
			/ ANNUAL_TERM_IN_DAYS;

	double interest_amount = (interest_per_day * nr_of_days) * get_balance();

	process_transaction(INTEREST, interest_amount, date);
}
