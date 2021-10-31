/*
 * Account.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: Thuan Bach
 */
#include <sstream>
#include "Account.h"
#include "Adult.h"
#include "Student.h"
#include "Senior.h"

char CURRENCY_CHARACTER = '$';

double Account::get_balance() const {
	return balance;
}

int Account::get_account_number() const {
	return account_number;
}

void Account::set_account_number(int acc_number) {
	account_number = acc_number;
}

Customer* Account::get_customer() const {
	return customer;
}

void Account::process_transaction(int transaction_type, double amount,
		const Date &date) {

	double new_balance;

	switch (transaction_type) {
		case WITHDRAW:
			new_balance = balance - amount;
			break;
		case DEPOSITE:
			new_balance = balance + amount;
			break;
		case INTEREST:
			new_balance = balance + amount;
			break;
		case CHKCHG:
			new_balance = balance - amount;
			break;
		case OVERDRAFT:
			new_balance = balance - amount;
			break;
		default:
			return;
	}

	Transaction transaction(transaction_type, amount, new_balance, date);

	balance = new_balance;

	transactions[number_of_transactions] = transaction;

	number_of_transactions++;
}

string Account::to_string() const {
	ostringstream result;
	result << "Account: " << account_number << endl;
	result << "Owner: " << customer->get_name() << endl;

	result << "Type of customer: " << customer->get_type_of_customer() << endl;

	result << "Balance: " << CURRENCY_CHARACTER << balance << endl;

	for (int i = 0; i < number_of_transactions; i++) {
		result << transactions[i].to_string() << endl;
	}

	return result.str();

}

void Account::set_customer(Customer &customer) {

	this->customer = &customer;
}

void Account::set_balance(double new_balance) {
	balance = new_balance;
}

int Account::get_number_of_days_of_account_term() const {
	return 0;
}

bool Account::is_transaction_date_valid(const Date &date) {
	if (number_of_transactions == 0) {
		return true;
	}

	Transaction latest_transaction = transactions[number_of_transactions - 1];

	Date latest_transaction_date = latest_transaction.get_transaction_date();

	return date >= latest_transaction_date;
}

int Account::calculate_days_from_last_transaction(const Date &date) const {

	if (number_of_transactions == 0) {
		return 0;
	}

	Transaction latest_transaction = transactions[number_of_transactions - 1];

	Date latest_transaction_date = latest_transaction.get_transaction_date();

	// the left right must be a const date
	int difference_in_days = -(latest_transaction_date - date);

	return difference_in_days;
}

int Account::calculate_number_of_annual_terms_from_last_transaction(
		const Date &date) const {

	if (number_of_transactions == 0) {
		return 0;
	}

	Transaction latest_transaction = transactions[number_of_transactions - 1];

	Date latest_transaction_date = latest_transaction.get_transaction_date();

	Date next_year = Date(latest_transaction_date.Day(),
			latest_transaction_date.Month(),
			latest_transaction_date.Year() + 1);

	int nr_of_annual_terms = 0;

	while (next_year < date) {
		nr_of_annual_terms++;
		next_year = Date(next_year.Day(), next_year.Month(),
				next_year.Year() + 1);
	}

	return nr_of_annual_terms;
}


void Account::add_interest(const Date &date) {
	// Method will be override by derived classes
}

void Account::deposit(double amount, const Date &date) {
	// Method will be override by derived classes
}

void Account::withdraw(const double amount, const Date &date) {
	// Method will be override by derived classes
}
