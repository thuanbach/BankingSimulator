/*
 * Transaction.cpp
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
 */

#include "Transaction.h"
#include "sstream"
#include <iostream>
#include "Bank.h"
#include "ConsoleBankingApp.h"
#include "TransactionType.h"

using namespace std;

string Transaction::to_string() const {
	const string SPACE_CHARACTER = " ";

	ostringstream result;


	switch (transaction_type) {
		case WITHDRAW:
			result << "WD";
			break;
		case DEPOSITE:
			result << "DEP";
			break;
		case CHKCHG:
			result << "CHKCHG";
			break;
		case OVERDRAFT:
			result << "CHKCHG";
			break;
		default:
			break;
	}

	result << SPACE_CHARACTER;;

	result << "$" << SPACE_CHARACTER << amount;
	result << SPACE_CHARACTER << balance;

	return result.str();
}

double Transaction::get_balance() const {
	return balance;
}

Date Transaction::get_transaction_date() const {
	return date;
}


