/*
 * ConsoleBankingApp.cpp
 *
 *  Created on: Oct 26, 2021
 *      Author: Thuan Bach
 */

#include "ConsoleBankingApp.h"
#include <limits>
#include "Senior.h"
#include "Adult.h"
#include "Student.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Date.h"
#include "Transaction.h"

const char BLANK_CHARACTER = ' ';
const string ENTER_ACCOUNT_NUMBER = "Enter Account Number>";
const string ENTER_AMOUNT = "Enter The Amount>";
const string ENTER_DATE = "Enter the date yyyy-mm-dd>";

const long STREAM_SIZE_LIMIT = std::numeric_limits<std::streamsize>::max();

Bank bank;



void ConsoleBankingApp::initData() {

	Customer* customer = new Senior("Thuan", "Le DUC THO", 11, "3038403948");
	Account* account  =  new Checking_Account();
	account->set_customer(*customer);
	bank.add_account(*account);

}

string ConsoleBankingApp::get_user_input_as_string(){
	string user_input;
	getline (cin, user_input);
	return user_input;
}

string ConsoleBankingApp::get_user_input_as_number(){
	string user_input;
	getline (cin, user_input);
	return user_input;
}

string ConsoleBankingApp::get_user_input_as_age(){
	string user_input;
	getline (cin, user_input);
	return user_input;
}

Date ConsoleBankingApp::get_user_input_as_date(){

	string date_str;

	getline (cin, date_str);

	// TODO: Check date format here
	int day, month, year;
	sscanf(date_str.c_str(), "%4d-%2d-%2d", &year,  &month, &day);

	return Date(day, month, year);
}

void ConsoleBankingApp::start_adding_account() {

	string customer_name;
	string customer_address;
	int customer_age;
	string customer_phone;

	cout << "Enter Customer Name ";
	getline (cin, customer_name);

	cout << "Enter Customer Address ";
	getline (cin, customer_address);

	cout << "Enter Customer Age ";
	customer_age = get_user_choice(1, 100);

	cout << "Enter Customer Phone Number ";
	getline (cin, customer_phone);

	cout << customer_name << " " << customer_address << " " << customer_age << " " << customer_phone;

	int type_of_customer;
	cout << "Select:" << endl;
	cout << "0: Senior" << endl;
	cout << "1: Adult" << endl;
	cout << "2: Student" << endl;
	type_of_customer = get_user_choice(0, 2);

	Customer* customer;
	switch (type_of_customer) {
		case 0:
			customer = new Senior(customer_name, customer_address, customer_age, customer_phone);
			break;
		case 1:
			customer = new Adult(customer_name, customer_address, customer_age, customer_phone);
			break;
		default:
			customer = new Student(customer_name, customer_address, customer_age, customer_phone);

	}

	int type_of_account;
	cout << "Select:" << endl;
	cout << "0: Checking" << endl;
	cout << "1: Savings" << endl;
	type_of_account = get_user_choice(0, 1);


	Account* account;

	switch(type_of_account){
		case 0:
			account  = new Checking_Account();

			break;
		case 1:
			account =  new Savings_Account();
			break;
		default:
			return;

	}

	account->set_customer(*customer);

	bank.add_account(*account);

	 cout << "Account:" << BLANK_CHARACTER << account->get_account_number() << BLANK_CHARACTER << "Added";

}


int ConsoleBankingApp::get_user_choice(int min, int max) {
	int x = 0;

	while (true) {

		cin >> x;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			continue;
		}

		if (x >= min && x <= max) {
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			break;
		}

	}

	return x;
}


void ConsoleBankingApp::start_printing_account() {

	cout << ENTER_ACCOUNT_NUMBER ;

	int account_number = get_user_choice(0, 1);

	Account* account = bank.get_account(account_number);

	if (account == NULL) {
		cout << "No account found";
	} else {
		cout << account->to_string();
		cout << endl;
	}
}


void ConsoleBankingApp::start_deposit() {

	cout << ENTER_ACCOUNT_NUMBER ;
	int account_number = get_user_choice(0, 1);

	cout << ENTER_AMOUNT;
	//TODO float or integer
	float amount = get_user_choice(0, INT32_MAX);

	cout << ENTER_DATE;
	Date date = get_user_input_as_date();

	bank.make_deposit(account_number, amount, date);

}

void ConsoleBankingApp::start_widthdraw() {
	cout << ENTER_ACCOUNT_NUMBER ;
	int account_number = get_user_choice(0, 1);

	cout << ENTER_AMOUNT;
	//TODO float or integer
	float amount = get_user_choice(0, INT32_MAX);

	cout << ENTER_DATE;
	Date date = get_user_input_as_date();

	cout << "TESTING" <<  account_number << endl;

	bank.make_withdrawal(account_number, amount, date);


}

void ConsoleBankingApp::start_application() {

	// TODO: Remove
	initData();

	Account account;
	int transaction_type;
	bool exit = false;
	do {
		cout << "Select:" << endl;
		cout << "0: Add Account" << endl;
		cout << "1: Make Deposit" << endl;
		cout << "2: Make Withdrawal" << endl;
		cout << "3: Check Account" << endl;
		cout << "4: Exit" << endl;
		cout << ">";

		transaction_type = get_user_choice(0, 4);

		switch (transaction_type) {
			case 0:
				start_adding_account();
			break;
			case 1:
				start_deposit();
				break;
			case 2:
				start_widthdraw();
				break;
			case 3:
				start_printing_account();
				break;
			case 4:
				exit = true;
				break;
			default:
				break;
		}

	} while (!exit);
}

