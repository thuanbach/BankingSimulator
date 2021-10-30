/*
 * Savings_Account.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
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

};

#endif /* SRC_SAVINGS_ACCOUNT_H_ */
