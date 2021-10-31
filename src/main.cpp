/**
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date Oct 20, 2021
 *
 */


#include <iostream>
#include "ConsoleBankingApp.h"
#include "TestingConsoleBanking.h"

using namespace std;

const unsigned int TEST_MODE = 1;
const unsigned int APP_MODE = 2;

const unsigned int RUNNING_MODE = APP_MODE;

void testConsoleBankingApp();

int main() {

	if (RUNNING_MODE == TEST_MODE) {
		testConsoleBankingApp();
	} else {
		ConsoleBankingApp app;
		app.start_application();
	}

	return 0;
}
