/**
 *
 * @file Savings_Account.cpp
 * @author Thuan Bach
 * @date October 30, 2021
 *
 * This class extends from the Account to implement functionalities for a savings account.
 *
 */
#include "Savings_Account.h"
#include "Date.h"

/**
 * Calculate number of days from the latest transaction compared to the number of terms given
 *
 * @param Date The given date
 *
 * @return int	Calculate number of days from the latest transaction compared to the number of terms given
 */
int Savings_Account::calculate_days_from_last_transaction_by_annual_terms(const unsigned int nr_of_terms) const {

	Date* latest_transaction_date  = get_latest_transaction_date();

	if (latest_transaction_date == NULL){
		return 0;
	}

	Date termDate = Date(latest_transaction_date->Day(),
				latest_transaction_date->Month(),
				latest_transaction_date->Year() + nr_of_terms);


	int difference_in_days = (termDate - *latest_transaction_date);

	return difference_in_days;
}

/**
 * Calculate number of annual terms from the latest transaction.
 * For example: 2018-10-10 -> 2020-10-10 is 2 terms, but 2018-10-10 -> 2020-10-09 is 1 term
 *
 * @param Date The given date
 *
 * @return int	number of annual terms from the latest transaction compared to the given date
 */
int Savings_Account::calculate_number_of_annual_terms_from_last_transaction(
		const Date &date) const {

	Date* latest_transaction_date  = get_latest_transaction_date();

	if (latest_transaction_date == NULL){
		return 0;
	}

	Date next_year = Date(latest_transaction_date->Day(),
			latest_transaction_date->Month(),
			latest_transaction_date->Year() + 1);

	int nr_of_annual_terms = 0;

	while (next_year <= date) {
		nr_of_annual_terms++;
		next_year = Date(next_year.Day(), next_year.Month(),
				next_year.Year() + 1);
	}

	return nr_of_annual_terms;
}

/**
 * The implement the deposit method for the savings account
 *
 * @param	amount	The deposit amount
 * @param 	date	The deposit's date
 * @return	N/A
 */
void Savings_Account::deposit(const double amount, const Date &date) {
	process_transaction(DEPOSITE, amount, date);
}

/**
 * The implement the withdraw method for the savings account
 *
 * @param	amount	The amount that is withdrawn
 * @param 	date	The withdrwal's date
 * @return	N/A
 */
void Savings_Account::withdraw(const double amount, const Date &date) {
	bool overdraft = amount > get_balance();

	process_transaction(WITHDRAW, amount, date);

	if (overdraft) {
		process_transaction(OVERDRAFT, get_customer()->get_overdraft_penalty(), date);
	}
}


/**
 * The implement the add_interest method for the savings account
 *
 * @param 	date	The date that the interest is added
 * @return	N/A
 */
void Savings_Account::add_interest(const Date &date) {

	int nr_of_terms =  calculate_number_of_annual_terms_from_last_transaction(date);

	if (nr_of_terms == 0 || get_balance() <= 0) {
		return;
	}

	int days = calculate_days_from_last_transaction_by_annual_terms(nr_of_terms);

	// interest will be calculated daily
	double interest_per_day = (double) get_customer()->get_savings_interest()
			/ ANNUAL_TERM_IN_DAYS;

	double amount = days * interest_per_day *  get_balance();

	process_transaction(INTEREST, amount, date);
}
