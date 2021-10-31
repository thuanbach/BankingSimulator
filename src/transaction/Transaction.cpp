/*
 * Transaction.cpp
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
 */

#include <iostream>
#include <iomanip>
#include "Transaction.h"
#include "sstream"
#include "Bank.h"
#include "ConsoleBankingApp.h"
#include "TransactionType.h"

using namespace std;

string Transaction::to_string() const {
	const string SPACE_CHARACTER = " ";
	const string TAB_CHARACTER = "	";

	ostringstream result;

	result << right << setw(10) ;
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

double Transaction::get_balance() const {
	return balance;
}

Date Transaction::get_transaction_date() const {
	return date;
}


