/*
 * Bank.cpp
 *
 *  Created on: Oct 23, 2021
 *      Author: Thuan Bach
 */

#include <iostream>
#include <limits>
#include "Bank.h"
#include "Customer.h"
#include "Senior.h"
#include "Student.h"
#include "Adult.h"
#include "Checking_Account.h"
#include "Savings_Account.h"

using namespace std;

const long STREAM_SIZE_LIMIT = std::numeric_limits<std::streamsize>::max();

int get_user_choice(int min, int max) {
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

void Bank::get_account(){
	int account_number;

	bool found = false;
	while (true){
		cout << "Enter Account Number";
		account_number = get_user_choice(0, number_of_accounts);

		for(int i=0; i<number_of_accounts;i++){
			if (accounts[i].get_account_number() == account_number) {
				found = true;
				cout << accounts[i].to_string();
			}

		}

		if (!found) {
			cout << "Account not found" <<endl;
		} else{
			break;
		}
	}

}

void Bank::add_account() {
	//Customer customer;
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
			account  =  new Checking_Account();
			number_of_accounts++;
			break;
		case 1:
			account =   new Savings_Account();
			number_of_accounts++;
			break;
		default:
			break;
	}




	 accounts[number_of_accounts] = *account;

	 cout << accounts[number_of_accounts].to_string();

	 Account account1 =  accounts[number_of_accounts];

}

void Bank::start() {
	// TODO: Need to only integer
	int transaction_type;
	bool exit = false;
	do {
		cout << "Select:" << endl;
		cout << "0: Add Account" << endl;
		cout << "1: Make Deposit" << endl;
		cout << "2: Make Withdrawal" << endl;
		cout << "3: Check Account" << endl;
		cout << "4: Exit" << endl;

		transaction_type = get_user_choice(0, 4);

		switch (transaction_type) {
		case 0:
			add_account();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			exit = true;
			break;
		default:
			break;
		}
	} while (!exit);

	cout << "exit the program" << endl;
}
