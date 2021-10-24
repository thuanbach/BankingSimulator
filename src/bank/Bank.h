/*
 * Bank.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include <iostream>
#include "../account/Account.h"
using namespace std;

int const MAXIMUM_OF_ACCOUNTS = 1000;

class Bank {

public:
	Bank() {
		number_of_accounts = 0;
		accounts = new Account[MAXIMUM_OF_ACCOUNTS];
	}
	void add_account();
	void make_deposit(Account account, double amount);
	void make_withdrawal(Account account, double amount);
	void get_account();
	void start();

private:
	Account* accounts;
	int number_of_accounts;

};




#endif /* SRC_BANK_H_ */
