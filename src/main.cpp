/**
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * The main function of the application where the ConsoleBankingApp starts execution.
 * There is also a TEST mode to support unit tests of Bank class.
 *
 */


#include <TestingBanking.h>
#include "ConsoleBankingApp.h"

// Define a Test mode used to run unit tests
const unsigned int TEST_MODE = 1;

// Define a APP mode used to run the ConsoleBankingApp module
const unsigned int APP_MODE = 2;

// Define a running mode for the application.
const unsigned int RUNNING_MODE = APP_MODE;


/**
 * The main function of the application where the ConsoleBankingApp starts execution
 *
 * @param  N/A
 * @return Returns 0 if the application shut down correctly
 */
int main() {

	if (RUNNING_MODE == TEST_MODE) {
		testConsoleBankingApp();
	} else {
		ConsoleBankingApp app;
		app.start_application();
	}

	return 0;
}
