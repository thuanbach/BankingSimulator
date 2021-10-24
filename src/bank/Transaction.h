/*
 * Transaction.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_TRANSACTION_H_
#define SRC_TRANSACTION_H_

#include <iostream>
#include "Date.h";
#include "TransactionType.h";

using namespace std;

class Transaction {

public:
	Transaction() {
	}

	void process_tran();

	string to_string() const;

private:
	int customer_number;
	TransactionType transaction_type;

	double amount;
	double fees;
	Date date;

};

#endif /* SRC_TRANSACTION_H_ */
