/*
 * Checking_Account.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: Thuan Bach
 */

#include <iostream>
#include "Checking_Account.h"
#include "TransactionType.h"
#include "Transaction.h"

using namespace std;


void Checking_Account::deposit(const double amount,  const Date &date){

	process_transaction(DEPOSITE, amount, date);
}

void Checking_Account::withdraw(const double amount, const Date &date){

	bool overdraft = amount > get_balance();

	process_transaction(WITHDRAW, amount, date);

	process_transaction(CHKCHG,  get_customer()->get_checking_charge(), date);

	if (overdraft) {
		process_transaction(OVERDRAFT, get_customer()->get_overdraft_penality(), date);
	}

}

void Checking_Account::add_interest(const Date& date){

	if (!has_interest(date)){
		return;
	}

	double amount = calculate_interest_amount(get_customer()->get_checking_interest(), date);

	process_transaction(INTREST, amount, date);

}
