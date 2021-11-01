/**
 *
 * @file ConsoleBankingApp.cpp
 * @author Thuan Bach
 * @date October 26, 2021
 *
 * The main module of the application where users will interact with through the Console.
 * It is responsible for receiving users' input and invoke corresponding functionalities
 * of Bank class such as adding an account, make deposit, make withdrawal, or query accounts.
 *
 */

#include <limits>
#include <iomanip>
#include "ConsoleBankingApp.h"

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

/**
 * Parse users' input from the Console, and check the data before return it as a string object
 *
 * @return A nonempty string object from users' input.
 */
string ConsoleBankingApp::get_user_input_as_string() {
	string user_input;

	do {
		getline(cin, user_input);

		size_t start = user_input.find_first_not_of(" \n\r\t");
		user_input =
				(start == std::string::npos) ? "" : user_input.substr(start);

		if (user_input.length() == 0) {
			cout << "ERROR: data is empty. Please input again" << endl;
			cout << ">";
			continue;
		}

		break;

	} while (true);

	return user_input;
}

/**
 * Parse users' input from the Console for the age, and check the data before return it as a integer value.
 * This can be enhanced in the future to check age validation if required.
 *
 * @return An integer presents a customer's age.
 */
unsigned int ConsoleBankingApp::get_user_input_as_age() {
	unsigned int age = 0;

	while (true) {

		cin >> age;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			cout << "ERROR: Incorrect age. Please input again." << endl;
			cout << ">";
			continue;
		}

		cin.ignore(STREAM_SIZE_LIMIT, '\n');

		if (age <= 0) {
			cout << "ERROR: Incorrect age. Please input again." << endl;
			cout << ">";
			continue;
		}

		break;
	}

	return age;
}

/**
 * Parse users' input from the Console, and check the data before return it as a integer value.
 * This can be used for the case handling user's input for account number.
 *
 * @return An integer that the user inputs
 */

double ConsoleBankingApp::get_user_input_as_number() {
	int number;

	while (true) {

		cin >> number;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			cout << "ERROR: Incorrect number. Please input again." << endl;
			cout << ">";
			continue;
		}

		// ignore character return for the next input
		cin.ignore(STREAM_SIZE_LIMIT, '\n');

		break;
	}

	return number;
}

/**
 * Parse users' input from the Console for the amount, and check the data before return it as a double value.
 *
 * @return A double that the user inputs
 */

double ConsoleBankingApp::get_user_input_as_amount() {
	double amount;

	while (true) {

		cin >> amount;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			cout << "ERROR: Incorrect amount. Please input again." << endl;
			cout << ">";
			continue;
		}

		// ignore character return for the next input
		cin.ignore(STREAM_SIZE_LIMIT, '\n');

		break;
	}

	return amount;
}

/**
 * Parse users' input from the Console for the date, and check the data before return it as a Date object.
 *
 * @return A Date object that the user inputs
 */

Date ConsoleBankingApp::get_user_input_as_date() {

	string date_str;

	int day = -1, month = -1, year = -1;

	do {
		getline(cin, date_str);

		int number_of_items_parsed = sscanf(date_str.c_str(), "%4d-%2d-%2d",
				&year, &month, &day);
		bool correctFormat = (number_of_items_parsed == 3);

		if (!correctFormat) {
			cout << "ERROR: Incorrect date format." << endl;
			cout << ">";
			continue;
		}

		break;
	} while (true);

	Date date(day, month, year);

	return date;
}

/**
 * Parse users' input from the Console for a choice selection, and check the data before return.
 *
 * @param min The minimum value of the selection
 * @param max The maximum value of the selection
 *
 * @return A integer presents user's selection for options.
 */
int ConsoleBankingApp::get_user_choice(int min, int max) {
	int x = 0;

	while (true) {

		cin >> x;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			cout << "ERROR: Incorrect selection. Please input again." << endl;
			cout << ">";
			continue;
		}

		if (x >= min && x <= max) {
			cin.ignore(STREAM_SIZE_LIMIT, '\n');
			break;
		} else {
			cout << "ERROR: Incorrect selection. Please input again." << endl;
			cout << ">";
		}

	}

	return x;
}

/**
 * Start user interaction for adding a account including receiving users' input from the Console.
 * At the end, it will invoke the corresponding function to add an account to the Bank.
 *
 * @param N/A
 * @return N/A
 */
void ConsoleBankingApp::start_adding_account() {

	string customer_name;
	string customer_address;
	int customer_age;
	string customer_phone;

	cout << "Enter Customer Name>";
	customer_name = get_user_input_as_string();

	cout << "Enter Customer Address>";
	customer_address = get_user_input_as_string();

	cout << "Enter Customer Age>";
	customer_age = get_user_input_as_age();

	cout << "Enter Customer Phone Number>";
	customer_phone = get_user_input_as_string();

	int type_of_customer;
	cout << "Select:" << endl;
	cout << "0: Senior" << endl;
	cout << "1: Adult" << endl;
	cout << "2: Student" << endl;
	cout << ">";
	type_of_customer = get_user_choice(0, 2);

	Customer *customer;
	switch (type_of_customer) {
	case 0:
		customer = new Senior(customer_name, customer_address, customer_age,
				customer_phone);
		break;
	case 1:
		customer = new Adult(customer_name, customer_address, customer_age,
				customer_phone);
		break;
	default:
		customer = new Student(customer_name, customer_address, customer_age,
				customer_phone);

	}

	int type_of_account;
	cout << "Select:" << endl;
	cout << "0: Checking" << endl;
	cout << "1: Savings" << endl;
	cout << ">";
	type_of_account = get_user_choice(0, 1);

	Account *account;

	switch (type_of_account) {
	case 0:
		account = new Checking_Account();
		break;
	case 1:
		account = new Savings_Account();
		break;
	default:
		return;

	}

	account->set_customer(*customer);

	bank.add_account(*account);
}

/**
 * Start user interaction for querying a account.
 * It receives a account number from user's input and print the account's information to the console if found.
 *
 * @param N/A
 * @return N/A
 */
void ConsoleBankingApp::start_printing_account() {

	cout << ENTER_ACCOUNT_NUMBER;

	int account_number = get_user_input_as_number();

	Account *account = bank.get_account(account_number);

	if (account == NULL) {
		cout << "No account found" << endl;
	} else {
		cout << account->to_string();
		cout << endl;
	}
}


/**
 * Start user interaction for making a deposit for a account.
 * At the end, it will invoke the corresponding function to make a deposit for the account .
 * @param N/A
 * @return N/A
 */
void ConsoleBankingApp::start_deposit() {

	cout << ENTER_ACCOUNT_NUMBER;
	int account_number = get_user_input_as_number();

	cout << ENTER_AMOUNT;

	double amount = get_user_input_as_amount();

	cout << ENTER_DATE;
	Date date = get_user_input_as_date();

	bank.make_deposit(account_number, amount, date);

}

void ConsoleBankingApp::start_widthdraw() {
	cout << ENTER_ACCOUNT_NUMBER;
	int account_number = get_user_input_as_number();

	cout << ENTER_AMOUNT;

	float amount = get_user_input_as_amount();

	cout << ENTER_DATE;
	Date date = get_user_input_as_date();

	bank.make_withdrawal(account_number, amount, date);
}

void ConsoleBankingApp::start_application() {

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
			cout << "Application shut down";
			break;
		default:
			break;
		}

	} while (!exit);
}

