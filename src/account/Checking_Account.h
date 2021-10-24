/*
 * Checking_Account.h
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_CHECKING_ACCOUNT_H_
#define SRC_CHECKING_ACCOUNT_H_

#include "Account.h"

class Checking_Account: public Account {
	public:
		Checking_Account(){

		}
		string to_string() const;

		void deposit(double amount);

		void withdraw(double amount);

		void add_interest();

	private:
};



#endif /* SRC_CHECKING_ACCOUNT_H_ */
