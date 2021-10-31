/*
 * Checking_Account.h
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
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
		static const int ANNUAL_TERM_IN_DAYS = 365;
};



#endif /* SRC_CHECKING_ACCOUNT_H_ */
