/**
 *
 * @file TestingBanking.cpp
 * @author Thuan Bach
 * @date October 31, 2021
 *
 * The module functions as unit test of the Bank's functionalities.
 * It is independent to ConsoleBankingApp that needs user's interaction through the console.
 */
#include "Senior.h"
#include "Adult.h"
#include "Student.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Date.h"
#include "Transaction.h"
#include "Bank.h"

Bank bank;

const unsigned int CHECKING_ACCOUNT = 0;
const unsigned int SAVINGS_ACCOUNT = 1;
const unsigned int ADULT_CUSTOMER = 0;
const unsigned int SENIOR_CUSTOMER = 1;
const unsigned int STUDENT_CUSTOMER = 2;


/**
 * Initiate mock data for Customer object based on customer_type
 *
 * @param	customer_type	Type of customer
 *
 * @return	Customer* A point to Customer.
 */
Customer* initCustomer(unsigned int customer_type) {
	Customer *customer;
	if (customer_type == ADULT_CUSTOMER) {
		customer = new Adult("Adult", "Le DUC THO", 30, "3434909");
	} else if (customer_type == SENIOR_CUSTOMER) {
		customer = new Senior("Senior", "Le DUC THO", 25, "45689989");
	} else {
		customer = new Student("Student", "Le DUC THO", 20, "34654677");
	}

	return customer;
}

/**
 *	Test the functionalities implemented in Bank module for for a a given account type with 3 kindsof customers
 *
 *	@param type_of_account	Type of account
 *	@return N/A
 */
void testBankingWithAccountType(unsigned int type_of_account) {

	for (unsigned int i = 0; i < 3; i++) {
		Customer *customer = initCustomer(i);
		Account *account;
		if (type_of_account == 0) {
			account = new Checking_Account();
		} else {
			account = new Savings_Account();
		}
		account->set_customer(*customer);

		bank.add_account(*account);

		Date depositeDate(10, 10, 2018);

		bank.make_deposit(account->get_account_number(), 500, depositeDate);

		Date withdrawDate(10, 10, 2020);

		bank.make_withdrawal(account->get_account_number(), 100, withdrawDate);

		Date withdrawDateWithOverdraft(10, 11, 2020);

		bank.make_withdrawal(account->get_account_number(), 1000,
				withdrawDateWithOverdraft);

		cout << bank.get_account(account->get_account_number())->to_string();
	}
}

/**
 *	Test the functionalities implemented in Bank module for Checking account.
 *
 *	@param N/A
 *	@return N/A
 */
void testCheckingAccount() {
	testBankingWithAccountType(CHECKING_ACCOUNT);
}

/**
 *	Test the functionalities implemented in Bank module for Savings account.
 *
 *	@param N/A
 *	@return N/A
 */
void testSavingsAccount() {
	testBankingWithAccountType(SAVINGS_ACCOUNT);
}

/**
 *	Test the functionalities implemented in Bank module.
 *
 *	@param N/A
 *	@return N/A
 */
void testBankingApp() {

	testCheckingAccount();
	testSavingsAccount();
}
