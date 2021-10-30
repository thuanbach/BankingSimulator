/*
 * Transaction.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_TRANSACTION_H_
#define SRC_TRANSACTION_H_

#include <iostream>
#include "Date.h"
#include "TransactionType.h"

using namespace std;

class Transaction {

public:


	Transaction() {// @suppress("Class members should be properly initialized")
	}

	Transaction(int transaction_type, double amount, double balance, const Date& date) {

		this->transaction_type = transaction_type;
		this->amount = amount;
		this->date = date;
		this->balance = balance;
	}



	string to_string() const;

	double get_balance() const;

	Date get_transaction_date() const;

private:

	int transaction_type;

	double balance;
	double amount;
	Date date;

};

#endif /* SRC_TRANSACTION_H_ */
