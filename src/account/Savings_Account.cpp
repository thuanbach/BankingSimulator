/*
 * Savings_Account.cpp
 *
 *  Created on: Oct 30, 2021
 *      Author: Thuan Bach
 */

#include "Savings_Account.h"
#include "Date.h"

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

void Savings_Account::deposit(const double amount, const Date &date) {
	process_transaction(DEPOSITE, amount, date);
}

void Savings_Account::withdraw(const double amount, const Date &date) {
	bool overdraft = amount > get_balance();

	process_transaction(WITHDRAW, amount, date);

	if (overdraft) {
		process_transaction(OVERDRAFT, get_customer()->get_overdraft_penality(), date);
	}

}

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
