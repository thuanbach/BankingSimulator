/**
 *
 * @file Savings_Account.h
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * This class extends from the Account to implement functionalities for a savings account.
 * Functionalities for each kind of accounts are different.
 *
 */
#ifndef SRC_SAVINGS_ACCOUNT_H_
#define SRC_SAVINGS_ACCOUNT_H_

#include "Account.h"
#include "Date.h"


class Savings_Account: public Account {

public:
	Savings_Account(){};

	~Savings_Account(){};

	virtual void deposit(const double amount, const Date &date);

	virtual void withdraw(const double amount, const Date &date);

	virtual void add_interest(const Date &date);

private:
	int calculate_number_of_annual_terms_from_last_transaction(
				const Date &date) const;

	int calculate_days_from_last_transaction_by_annual_terms(
				const unsigned int nr_of_annual_terms) const;

};

#endif /* SRC_SAVINGS_ACCOUNT_H_ */
