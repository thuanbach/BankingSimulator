/**
 *
 * @file Checking_Account.cpp
 * @author Thuan Bach
 * @date October 23, 2021
 *
 * This class extends from the Account to implement functionalities for a checking account.
 * Functionalities for each kind of accounts are different.
 *
 */

#ifndef SRC_CHECKING_ACCOUNT_H_
#define SRC_CHECKING_ACCOUNT_H_

#include "Account.h"
#include "Date.h"


class Checking_Account: public Account {
	public:

		Checking_Account() {}

		~Checking_Account() {}


		virtual void deposit(const double amount, const Date &date);

		virtual void withdraw(const double amount, const Date &date);

		virtual void add_interest(const Date &date);

	private:

		int calculate_days_from_last_transaction(const Date &date) const;

};



#endif /* SRC_CHECKING_ACCOUNT_H_ */
