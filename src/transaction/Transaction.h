/**
 *
 * @file Transaction.cpp
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * This holds information of a transaction such as transaction's date , the type of the transaction, the amount, and the balance after the transaction
 *
 */
#ifndef SRC_TRANSACTION_H_
#define SRC_TRANSACTION_H_

#include <iostream>
#include "Date.h"
#include "TransactionType.h"

using namespace std;

class Transaction {

public:

	/**
	 * Default constructor
	 */
	Transaction(): transaction_type(-1), balance(0), amount(0) {
	}


	/**
	 *
	 * Constructor with params
	 *
	 * @param transaction_type	Type of transaction
	 * @param amount	Amount of transaction
	 * @param balance	The re balance
	 *
	 */
	Transaction(int transaction_type, double amount, double balance, const Date& date) {

		this->transaction_type = transaction_type;
		this->amount = amount;
		this->date = date;
		this->balance = balance;
	}

	/**
	 * Returns a string object represents a transaction
	 *
	 * @return A string object represents a transaction
	 */
	string to_string() const;

	/**
	 * Returns the balance that is hold by transaction
	 *
	 * @return string The account balance at the end of the transaction
	 */
	double get_balance() const;

	/**
	 * Returns the transaction date
	 *
	 * @return date The transaction date
	 */
	Date get_transaction_date() const;

private:

	int transaction_type;

	double balance;

	double amount;

	Date date;

};

#endif /* SRC_TRANSACTION_H_ */
