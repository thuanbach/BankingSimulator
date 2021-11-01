/**
 *
 * @file Checking_Account.h
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This class extends from the Account to implement functionalities for a checking account.
 *
 */
#ifndef SRC_CHECKING_ACCOUNT_H_
#define SRC_CHECKING_ACCOUNT_H_

#include "Account.h"
#include "Date.h"

class Checking_Account: public Account {

public:

	/**
	 * Default constructor
	 */
	Checking_Account() {
	}

	/**
	 * Default de-constructor
	 */
	~Checking_Account() {
	}

	/**
	 * The implement the deposit method for the checking account
	 *
	 * @param	amount	The deposit amount
	 * @param 	date	The deposit's date
	 * @return	N/A
	 */
	virtual void deposit(const double amount, const Date &date);

	/**
	 * The implement the withdraw method for the checking account
	 *
	 * @param	amount	The amount that is withdrawn
	 * @param 	date	The withdrwal's date
	 * @return	N/A
	 */
	virtual void withdraw(const double amount, const Date &date);

	/**
	 * The implement the add_interest method for the checking account
	 *
	 * @param 	date	The date that the interest is added
	 * @return	N/A
	 */
	virtual void add_interest(const Date &date);

private:

	/**
	 * Calculate number of days from the latest transaction
	 *
	 * @param Date The given date
	 *
	 * @return int	Number of days from the latest transaction date compared with the given date
	 */
	int calculate_days_from_last_transaction(const Date &date) const;

};

#endif /* SRC_CHECKING_ACCOUNT_H_ */
