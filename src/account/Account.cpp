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



//string Account::get_type_of_customer() const {
//	const Customer* pcustomer = &customer;
//	const Adult *adult = dynamic_cast<const Adult*>(pcustomer);
//	const Senior *senior = dynamic_cast<const Senior*>(pcustomer);
//	const Student *student = dynamic_cast<const Student*>(pcustomer);
//	if (adult != NULL) {
//		return "Adult";
//	} else if (senior != NULL) {
//		return "Senior";
//	} else if (student != NULL) {
//		return "Student";
//	} else {
//		return "";
//	}
//}

double Account::calculate_interest_amount(float interest_rate,
		const Date &date) const {
	int nr_of_days = calculate_days_from_last_transaction(date);

	return (nr_of_days - 1) / ANNUAL_TERM_IN_DAYS * interest_rate;
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

	// TODO: Seems it not correct
	result << "Type of customer: " << customer->get_type_of_customer() << endl;

	result << "Balance: " << CURRENCY_CHARACTER << balance << endl;

	for (int i = 0; i < number_of_transactions; i++) {
		result << transactions[i].to_string() << endl;
	}

	return result.str();

}

void Account::set_customer(Customer &customer) {
	// TODO: Please check if it correct
	this->customer = &customer;
}

void Account::set_balance(double new_balance) {
	balance = new_balance;
}

int Account::get_number_of_days_of_account_term() const {
	return 0;
}

int Account::calculate_days_from_last_transaction(const Date &date) const {

	if (number_of_transactions == 0) {
		return 0;
	}

	Transaction latest_transaction = transactions[number_of_transactions - 1];

	Date latest_transaction_date = latest_transaction.get_transaction_date();

	int difference_in_days = -(latest_transaction_date - date);

	return difference_in_days;
}

bool Account::has_interest(const Date &date) const {

	return (calculate_days_from_last_transaction(date) -1) /ANNUAL_TERM_IN_DAYS > 0;
}

void Account::add_interest(const Date &date) {
	cout
			<< "Account::add_interest is invoked. This method needs to be override by a derived class";
}

void Account::deposit(double amount, const Date &date) {
	cout
			<< "Account::deposit is invoked. This method needs to be override by a derived class";
}

void Account::withdraw(const double amount, const Date &date) {
	cout
			<< "Account::withdraw is invoked. This method needs to be override by a derived class";
}
