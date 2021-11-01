/**
 *
 * @file Account.h
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This module stores information regarding accounts such as account number, balance, etc.
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

	/**
	 * Default constructor
	 */
	Account() :
			account_number(-1), balance(0), customer(NULL), number_of_transactions(
					0), transactions(
					new Transaction[MAXIMUM_OF_TRANSACTIONS_PER_ACC]) {
	}

	/**
	 * Default de-constructor
	 */
	virtual ~Account() {
	}

	/**
	 * Set a customer for the account
	 *
	 * @param	customer	A customer object
	 * @return 	N/A
	 */
	void set_customer(Customer &customer);


	/**
	 * Get a customer from the account
	 *
	 * @param	N/A
	 * @return 	Customer* A pointer to the customer object of the account
	 */
	Customer* get_customer() const;

	/**
	 * Update the account balance
	 *
	 * @param	new_balance	The new balance of the account
	 * @return 	N/A
	 */
	void set_balance(double new_balance);


	/**
	 * Returns the account balance
	 *
	 * @param	N/A
	 * @return 	double The current account balance
	 */
	double get_balance() const;

	/**
	 * Set the account number
	 *
	 * @param	account_number	The account number
	 */
	void set_account_number(int account_number);

	/**
	 * Returns the account number
	 *
	 * @param	N/A
	 * @return	int	The account number
	 */
	int get_account_number() const;


	/**
	 * Returns a string that represents the account information

	 * @param	N/A
	 * @return	string	A string object that represents the account information
	 */
	string to_string() const;


	/**
	 * The interface for the deposit method that will be implemented by derived classes
	 *
	 * @param	amount	The deposit amount
	 * @param 	date	The deposit's date
	 * @return	N/A
	 */
	virtual void deposit(const double amount, const Date &date);

	/**
	 * The interface for the withdraw method that will be implemented by derived classes
	 *
	 * @param	amount	The amount that is withdrawn
	 * @param 	date	The withdrwal's date
	 * @return	N/A
	 */
	virtual void withdraw(const double amount, const Date &date);

	/**
	 * The interface for the add_interest method that will be implemented by derived classes
	 *
	 * @param 	date	The date that the interest is added
	 * @return	N/A
	 */
	virtual void add_interest(const Date &date);

	/**
	 * Check if the transaction date validity. The new transaction date must be equal or greater than the latest transaction date
	 *
	 * @param date	the date transaction
	 * @return	boolean	Represents if transaction is valid
	 */
	bool is_transaction_date_valid(const Date &date);

protected:

	/**
	 * Process a transaction for the account. This updates the balance and adds a new transaction to the account
	 *
	 * @param	transaction_type	Type of transaction
	 * @param	amount	The amount for the transaction
	 * @param	date	The transaction date
	 *
	 * @return N/A
	 */
	void process_transaction(const int transaction_type, const double amount,
			const Date &date);

	/* Define a constant number of days in a annual term*/
	static const int ANNUAL_TERM_IN_DAYS = 365;

	/**
	 * Returns the latest transaction date
	 *
	 * @param	N/A
	 * @return Date* The latest transaction's date
	 */
	Date* get_latest_transaction_date() const;

private:

	/* The account number */
	int account_number;

	/* The account balance */
	double balance;

	/* The customer information */
	Customer *customer;

	/* Number of transaction executed of the account */
	int number_of_transactions;

	/* A list of transactions */
	Transaction *transactions;

	/* Define a constant for the maximum number of transaction executed*/
	static const int MAXIMUM_OF_TRANSACTIONS_PER_ACC = 1000;
};

#endif /* SRC_ACCOUNT_H_ */
