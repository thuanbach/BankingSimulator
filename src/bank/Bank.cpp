/**
 *
 * @file Bank.cpp
 * @author Thuan Bach
 * @date October 23, 2021
 *
 * The main module is responsible for storing the main application's data and execute .
 * It is responsible for receiving users' input and invoke corresponding functionalities
 * of Bank class such as adding an account, make deposit, make withdrawal, or query accounts
 *
 */
#include <iostream>
#include <stdio.h>
#include <limits>
#include <iomanip>

#include "Bank.h"
#include "Customer.h"
#include "Senior.h"
#include "Student.h"
#include "Adult.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "TransactionType.h"
#include "Date.h"
#include "Transaction.h"

using namespace std;


const string Bank::ERROR_NO_ACCOUNT_FOUND = "ERROR: No account found";
const string Bank::TRANSACTION_DATE_IN_THE_PAST = "ERROR: The current transaction date is before the latest transaction date";

Account* Bank::get_account(int account_number) {
	Account *account = NULL;

	for (int i = 0; i < number_of_accounts; i++) {
		if (accounts[i]->get_account_number() == account_number) {
			account = accounts[i];
			break;
		}
	}

	return account;
}

void Bank::add_account(Account &account) {

	// initiate customer_number and account_number got from bank

	account.get_customer()->set_customer_number(number_of_accounts);

	account.set_account_number(number_of_accounts);

	accounts[number_of_accounts] = &account;

	number_of_accounts++;

	cout << "Account: " << account.get_account_number() << " Added" << endl;
}

void Bank::make_deposit(const int account_number, const double amount,
		const Date &date) {

	Account *account = get_account(account_number);

	if (account == NULL) {
		cout << ERROR_NO_ACCOUNT_FOUND << endl;
		return;
	}

	if (!account->is_transaction_date_valid(date)) {
		cout << TRANSACTION_DATE_IN_THE_PAST << endl;
		return;
	}


	account->add_interest(date);

	account->deposit(amount, date);

	cout << "Deposit in " << account_number << " amount: $" << fixed
				<< setprecision(2) << amount << " on " << date << " new balance: $"
				<< fixed << setprecision(2) << account->get_balance() << endl;
}

void Bank::make_withdrawal(const int account_number, const double amount,
		const Date &date) {

	Account *account = get_account(account_number);

	if (account == NULL) {
		cout << ERROR_NO_ACCOUNT_FOUND << endl;;
		return;
	}

	if (!account->is_transaction_date_valid(date)) {
		cout << TRANSACTION_DATE_IN_THE_PAST << endl;
		return;
	}

	account->add_interest(date);

	account->withdraw(amount, date);

	cout << "Withdraw from " << account_number << " amount: $" << fixed
			<< setprecision(2) << amount << " on " << date << " new balance: $"
			<< fixed << setprecision(2) << account->get_balance() << endl;

}

