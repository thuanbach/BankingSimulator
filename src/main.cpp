/**
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date October 20, 2021
 *
 * The main function where the ConsoleBankingApp starts execution.
 * There is also a TEST mode to support test functionalities of Bank class.
 *
 */


#include "ConsoleBankingApp.h"
#include "TestingConsoleBanking.h"

const unsigned int TEST_MODE = 1;
const unsigned int APP_MODE = 2;

// Change to TEST_MODE to run tests for Bank class.
const unsigned int RUNNING_MODE = APP_MODE;


/**
 * The main function to start the application
 *
 * @param  N/A
 * @return 0. Returns 0 if the application shut down correctly
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
