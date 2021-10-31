/*
 * Account.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

#include <iostream>
#include "../customer/Customer.h"
#include "TransactionType.h"
#include "Transaction.h"

using namespace std;

class Account {

public:

	Account() :
			account_number(-1), balance(0), customer(NULL), number_of_transactions(
					0), transactions(
					new Transaction[MAXIMUM_OF_TRANSACTIONS_PER_ACC]) {
	}

	virtual ~Account() {
	}

	/**
	 * customer
	 */

	void set_customer(Customer &customer);

	Customer* get_customer() const;

	/**
	 * Balance
	 */

	void set_balance(double new_balance);

	double get_balance() const;

	/**
	 * account_number
	 */

	void set_account_number(int account_number);

	int get_account_number() const;


	string to_string() const;


	virtual void deposit(const double amount, const Date &date);

	virtual void withdraw(const double amount, const Date &date);

	virtual void add_interest(const Date &date);

	bool is_transaction_date_valid(const Date &date);

protected:


	static const int MAXIMUM_OF_TRANSACTIONS_PER_ACC = 1000;

	bool has_interest(const Date &new_transaction_date) const;

	int get_number_of_days_of_account_term() const;

	void process_transaction(const int transaction_type, const double amount,
			const Date &date);

	double calculate_interest_amount(float interest, const Date &date) const;

	int calculate_days_from_last_transaction(const Date &date) const;

	int calculate_number_of_annual_terms_from_last_transaction(
			const Date &date) const;


private:

	int account_number;

	double balance;

	Customer *customer;

	int number_of_transactions;

	Transaction *transactions;
};

#endif /* SRC_ACCOUNT_H_ */
