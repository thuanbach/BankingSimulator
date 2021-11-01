/**
 *
 * @file Account.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * <p>This stores information regarding accounts such as account number, balance, etc.</p>
 * <p>There are 2 kinds of accounts: Checking and Savings. </p>
 * <p>Functionalities regarding withdrawal, deposit and interest for each kind of accounts are different.</p>
 * <p>And they will be implemented in derived classes instead of Account class.</p>
 *
 */

#include <sstream>
#include <iomanip>
#include "Account.h"
#include "Adult.h"
#include "Student.h"
#include "Senior.h"

/**
 * Returns the account balance
 *
 * @return 	double The current account balance
 */
double Account::get_balance() const {
	return balance;
}

/**
 * Returns the account number
 *
 * @return	int	The account number
 */
int Account::get_account_number() const {
	return account_number;
}

/**
 * Set the account number
 *
 * @param	account_number	The account number
 */
void Account::set_account_number(int acc_number) {
	account_number = acc_number;
}


/**
 * Get a customer from the account
 *
 * @param	N/A
 * @return 	Customer* A pointer to the customer object of the account
 */
Customer* Account::get_customer() const {
	return customer;
}

/**
 * Process a transaction for the account. This updates the balance and adds a new transaction to the account
 *
 * @param	transaction_type	Type of transaction
 * @param	amount	The amount for the transaction
 * @param	date	The transaction date
 *
 * @return N/A
 */
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

/**
 * Returns a string that represents the account information
 *
 * @param	N/A
 * @return	string	A string object that represents the account information
 */
string Account::to_string() const {
	ostringstream result;

	const char CURRENCY_CHARACTER = '$';

	result << "Account: " << account_number << endl;
	result << "Owner: " << customer->get_name() << endl;

	result << "Type of customer: " << customer->get_type_of_customer() << endl;

	result << "Balance: " << CURRENCY_CHARACTER << fixed << setprecision(2) << balance << endl;

	for (int i = 0; i < number_of_transactions; i++) {
		result << transactions[i].to_string() << endl;
	}

	return result.str();

}

/**
 * Set a customer for the account
 *
 * @param	customer	A customer object
 * @return 	N/A
 */
void Account::set_customer(Customer &customer) {

	this->customer = &customer;
}

/**
 * Update the account balance
 *
 * @param	new_balance	The new balance of the account
 * @return 	N/A
 */
void Account::set_balance(double new_balance) {
	balance = new_balance;
}

/**
 * Check if the transaction date validity. The new transaction date must be equal or greater than the latest transaction date
 *
 * @param date	the date transaction
 * @return	boolean	Represents if transaction is valid
 */
bool Account::is_transaction_date_valid(const Date &date) {
	if (number_of_transactions == 0) {
		return true;
	}

	Transaction latest_transaction = transactions[number_of_transactions - 1];

	Date latest_transaction_date = latest_transaction.get_transaction_date();

	return date >= latest_transaction_date;
}
/**
 * Returns the latest transaction date
 *
 * @param	N/A
 * @return Date* The latest transaction's date
 */
Date* Account::get_latest_transaction_date() const{
	if (number_of_transactions == 0) {
		return NULL;
	}

	Date date = transactions[number_of_transactions - 1].get_transaction_date();

	return new Date(date.Day(), date.Month(), date.Year());
}

/**
 * The interface for the add_interest method that will be implemented by derived classes
 *
 * @param 	date	The date that the interest is added
 * @return	N/A
 */
void Account::add_interest(const Date &date) {
	// Method will be override by derived classes
}

/**
 * The interface for the deposit method that will be implemented by derived classes
 *
 * @param	amount	The deposit amount
 * @param 	date	The deposit's date
 * @return	N/A
 */
void Account::deposit(double amount, const Date &date) {
	// Method will be override by derived classes
}



/**
 * The interface for the withdraw method that will be implemented by derived classes
 *
 * @param	amount	The amount that is withdrawn
 * @param 	date	The withdrwal's date
 * @return	N/A
 */
void Account::withdraw(const double amount, const Date &date) {
	// Method will be override by derived classes
}
