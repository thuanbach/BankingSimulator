/*
 * Bank.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include <iostream>
#include "Account.h"
#include "Date.h"


using namespace std;

int const MAXIMUM_OF_ACCOUNTS = 1000;

class Bank {

public:

	Bank() {
		number_of_accounts = 0;
		accounts = new Account*[MAXIMUM_OF_ACCOUNTS];
	}

	void add_account(Account &account);

	void make_deposit(const int account_number, const double amount, const Date &date);

	void make_withdrawal(const int account_number, const double amount, const Date &date);

	Account* get_account(int account_number);

	void start();

	void initData();

private:

	Account** accounts;
	int number_of_accounts;

	const string ERROR_NO_ACCOUNT_FOUND = "ERROR: No account found";

};


#endif /* SRC_BANK_H_ */
