/**
 *
 * @file Savings_Account.h
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * This class extends from the Account to implement functionalities for a savings account.
 *
 */
#ifndef SRC_SAVINGS_ACCOUNT_H_
#define SRC_SAVINGS_ACCOUNT_H_

#include "Account.h"
#include "Date.h"


class Savings_Account: public Account {

public:
	/**
	 * Default constructor
	 */
	Savings_Account(){};

	/**
	 * Default de-constructor
	 */
	~Savings_Account(){};

	/**
	 * The implement the deposit method for the savings account
	 *
	 * @param	amount	The deposit amount
	 * @param 	date	The deposit's date
	 * @return	N/A
	 */
	virtual void deposit(const double amount, const Date &date);


	/**
	 * The implement the withdraw method for the savings account
	 *
	 * @param	amount	The amount that is withdrawn
	 * @param 	date	The withdrwal's date
	 * @return	N/A
	 */
	virtual void withdraw(const double amount, const Date &date);

	/**
	 * The implement the add_interest method for the savings account
	 *
	 * @param 	date	The date that the interest is added
	 * @return	N/A
	 */
	virtual void add_interest(const Date &date);

private:

	/**
	 * Calculate number of annual terms from the latest transaction.
	 * For example: 2018-10-10 -> 2020-10-10 is 2 terms, but 2018-10-10 -> 2020-10-09 is 1 term
	 *
	 * @param Date The given date
	 *
	 * @return int	number of annual terms from the latest transaction compared to the given date
	 */
	int calculate_number_of_annual_terms_from_last_transaction(
				const Date &date) const;


	/**
	 * Calculate number of days from the latest transaction compared to the number of terms given
	 *
	 * @param Date The given date
	 *
	 * @return int	Calculate number of days from the latest transaction compared to the number of terms given
	 */
	int calculate_days_from_last_transaction_by_annual_terms(
					const unsigned int nr_of_annual_terms) const;

};

#endif /* SRC_SAVINGS_ACCOUNT_H_ */
