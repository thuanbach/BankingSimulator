/**
 *
 * @file Transaction.cpp
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * This holds information of a transaction such as transaction's date , the type of the transaction, the amount, and the balance after the transaction
 *
 */
#include <iostream>
#include <iomanip>
#include "Transaction.h"
#include "sstream"
#include "Bank.h"
#include "ConsoleBankingApp.h"
#include "TransactionType.h"

using namespace std;


/**
 * Returns a string object represents a transaction
 *
 * @return A string object represents a transaction
 */
string Transaction::to_string() const {
	const string SPACE_CHARACTER = " ";
	const string TAB_CHARACTER = "	";

	ostringstream result;

	result << right << setw(10);

	switch (transaction_type) {
		case WITHDRAW:
			result << "WD";
			break;
		case DEPOSITE:
			result << "DEP";
			break;
		case INTEREST:
			result << "INT CR";
			break;
		case CHKCHG:
			result << "CHKCHG";
			break;
		case OVERDRAFT:
			result << "OVERDRAFT";
			break;
		default:
			break;
	}

	result << SPACE_CHARACTER << date ;

	result << TAB_CHARACTER << "$" << right << setw(10) << fixed << setprecision(2) << amount;

	result << TAB_CHARACTER <<  "$" << right << setw(10) << fixed << setprecision(2) << balance;

	return result.str();
}

/**
 * Returns the balance that is hold by transaction
 *
 * @return string The account balance at the end of the transaction
 */
double Transaction::get_balance() const {
	return balance;
}

/**
 * Returns the transaction date
 *
 * @return date The transaction date
 */
Date Transaction::get_transaction_date() const {
	return date;
}
