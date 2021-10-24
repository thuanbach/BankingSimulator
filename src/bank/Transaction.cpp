/*
 * Transaction.cpp
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
 */

#include "Transaction.h"
#include "sstream"
#include <iostream>

using namespace std;

void Transaction::process_tran() {

//	cout << "0: Add Account" << endl;
//	cout << "1: Make Deposit" << endl;
//	cout << "2: Make Withdrawal" << endl;
//	cout << "3: Check Account" << endl;
//	cout << "4: Exit" << endl;
//	cin >> transaction_type;
}

string Transaction::to_string() const {
	ostringstream result;
	result << "Date ";

	switch (transaction_type) {
		case WITHDRAW:
			result << "WID";
			break;
		case DEPOSITE:
			result << "DEP";
			break;
		default:
			break;
	}

	result << "$" << amount;
	// TODO WHAT IS FEE
	result << "$" << endl;

	return result.str();
}
