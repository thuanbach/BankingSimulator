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
	Account() {}

	Account(Customer &aCustomer, int acc_number) :
			customer(&aCustomer), account_number(acc_number), balance(0) {
		//transactions = new Tra[];
	};

	double get_balance() const;
	Customer* get_customer() const;
	string to_string() const;

	void set_customer(Customer &customer);
	void set_balance(double new_balance);

	int get_account_number() const;

protected:
	static const int MAXIMUM_OF_TRANSACTIONS_PER_ACC = 1000;

	Customer *customer;
	int account_number;
	double balance;
	Transaction* transactions;
	int number_of_transactions;

};

#endif /* SRC_ACCOUNT_H_ */
