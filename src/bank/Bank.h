/**
 *
 * @file Bank.h
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * The main module of the application where users will interact with.
 * It is responsible for receiving users' input and invoke corresponding functionalities
 * of Bank class such as adding an account, make deposit, make withdrawal, or query accounts
 *
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


private:

	Account** accounts;
	int number_of_accounts;

	static const string ERROR_NO_ACCOUNT_FOUND;
	static const string TRANSACTION_DATE_IN_THE_PAST;

};


#endif /* SRC_BANK_H_ */
