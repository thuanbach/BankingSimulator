/**
 *
 * @file ConsoleBankingApp.h
 * @author Thuan Bach
 * @date October 26, 2021
 *
 * The main module of the application where users will interact with through the Console.
 * It is responsible for receiving users' input and invoke corresponding functionalities
 * of Bank class such as adding an account, make deposit, make withdrawal, or query accounts
 *
 *
 */

#ifndef SRC_CONSOLEBANKINGAPP_H_
#define SRC_CONSOLEBANKINGAPP_H_

#include "Bank.h"
#include "Date.h"


class ConsoleBankingApp {

public:

	/**
	 *  Start the console banking application that users can interact with
	 *
	 *  @param	N/A
	 *  @return N/A
	 *
	 */
	void start_application();

private:

	/**
	 * Start adding account interaction
	 *
	 * @param	N/A
	 * @return	N/A
	 */
	void start_adding_account();

	/**
	 * Start the deposit interactive process.
	 *
	 * @param	N/A
	 * @return	N/A
	 */
	void start_deposit();

	/**
	 * Start the withdrawal interactive process.
	 *
	 * @param	N/A
	 * @return	N/A
	 */
	void start_widthdraw();

	/**
	 * Start the printing account interactive process.
	 *
	 * @param	N/A
	 * @return	N/A
	 */
	void start_printing_account();

	/**
	 * Get user's choice in range min and max
	 *
	 * @param	min	The minimum value that user needs to input
	 * @param	max	The maximum value that user needs to input
	 * @return	int The value in rage of min and max that user input
	 */
	int get_user_choice(int min, int max);


	/**
	 * Get user's input and parse to string
	 *
	 * @return	string	A line user input
	 */
	string get_user_input_as_string();

	/**
	 * Get user's input and parse to double
	 *
	 * @return	double	The input amount
	 */
	double get_user_input_as_amount();


	/**
	 * Get user's input and parse to number
	 *
	 * @return	double	The number user input
	 */
	int get_user_input_as_number();

	/**
	 * Get user's input as age
	 *
	 * @return	int	The number user input considered as age
	 */
	unsigned int get_user_input_as_age();

	/**
	 * Get user's input as date
	 *
	 * @return	date	The date that user input
	 */
	Date get_user_input_as_date();


	/* The Bank object that stores the whole data of the application*/
	Bank bank;

};

#endif /* SRC_CONSOLEBANKINGAPP_H_ */
