/**
 *
 * @file ConsoleBankingApp.h
 *
 * @author Thuan Bach
 *
 * @date Oct 26, 2021
 *
 */

#ifndef SRC_CONSOLEBANKINGAPP_H_
#define SRC_CONSOLEBANKINGAPP_H_

#include "Bank.h"
#include "Date.h"

extern Bank bank;

class ConsoleBankingApp {

public:
	void start_application();


private:
	void initData();

	void start_adding_account();

	void start_deposit();

	void start_widthdraw();

	void start_printing_account();



	int get_user_choice(int min, int max);

	string get_user_input_as_string();

	double get_user_input_as_amount();

	double get_user_input_as_number();

	unsigned int get_user_input_as_age();

	Date get_user_input_as_date();

	Bank bank;

};

#endif /* SRC_CONSOLEBANKINGAPP_H_ */
