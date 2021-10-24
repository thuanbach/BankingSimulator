/*
 * Savings_Account.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_SAVINGS_ACCOUNT_H_
#define SRC_SAVINGS_ACCOUNT_H_

#include "Account.h"

class Savings_Account: public Account {

	public:
		Savings_Account(): Account(){

		}

		void deposit(double amount);

		void withdraw(double amount);

		void add_interest();

	private:

};

#endif /* SRC_SAVINGS_ACCOUNT_H_ */
