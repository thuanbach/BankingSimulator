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



class Bank {

public:

	/**
	 * The default constructor
	 */
	Bank() {
		number_of_accounts = 0;
		accounts = new Account*[MAXIMUM_OF_ACCOUNTS];
	}

	/**
	 * Add an account to the Bank
	 *
	 * @param	account	The account that needs to added.
	 * @return	N/A
	 */
	void add_account(Account &account);

	/**
	 * Make a deposit from the account
	 *
	 * @param	account_number	The account number
	 * @param	amount	The deposit amount
	 * @param	date	The deposit's date
	 *
	 * @return	N/A
	 */
	void make_deposit(const int account_number, const double amount, const Date &date);

	/**
	 * Make a withdrawal from the account
	 *
	 * @param	account_number	The account number
	 * @param	amount	The deposit amount
	 * @param	date	The deposit's date
	 *
	 * @return	N/A
	 */
	void make_withdrawal(const int account_number, const double amount, const Date &date);

	/**
	 * Returns the account with the acount number given
	 *
	 * @param	account_number The account number
	 *
	 * @return	Account*	The account is got from the account number
	 *
	 */
	Account* get_account(int account_number);

private:

	/* An array of pointers to Account objects */
	Account** accounts;

	/* Number of account added */
	int number_of_accounts;

	/* Define a string constant message if the account not found */
	static const string ERROR_NO_ACCOUNT_FOUND;

	/* Define a string constant message if the transaction date is invalid */
	static const string TRANSACTION_DATE_IN_THE_PAST;

	/* Define a constant that defines maximum of accounts added */
	static const int MAXIMUM_OF_ACCOUNTS = 1000;
};


#endif /* SRC_BANK_H_ */
