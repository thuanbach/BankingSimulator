/**
 *
 * @file Account.h
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This module store information regarding accounts such as account number, balance, etc.
 * There are 2 kinds of accounts: Checking and Savings. Functionalities regarding withdrawal, deposit and interest for each kind of accounts are different.
 * And they will be implemented in derived classes instead of Account class.
 *
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


	void process_transaction(const int transaction_type, const double amount,
			const Date &date);

	static const int ANNUAL_TERM_IN_DAYS = 365;

	Date* get_latest_transaction_date() const;

private:

	int account_number;

	double balance;

	Customer *customer;

	int number_of_transactions;

	Transaction *transactions;


	static const int MAXIMUM_OF_TRANSACTIONS_PER_ACC = 1000;
};

#endif /* SRC_ACCOUNT_H_ */
