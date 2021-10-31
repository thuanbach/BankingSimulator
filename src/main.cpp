/**
 *
 * @file main.cpp
 * @author Thuan Bach
 * @date Oct 20, 2021
 *
 */


#include <iostream>
#include "transact.h"
#include "bank.h"
#include "Student.h"
#include "ConsoleBankingApp.h"

// TOD REMOVE HERE
#include "TestingConsoleBanking.h"

using namespace std;

void test_date(){

	Date date1(10,10,2018);

	Date date2(10,10,2020);

	long days = (date2 - date1);

	cout << "days: " << (date2 - date1)  << endl;

	cout << "years:" << (days-1)/365  << endl;;




}

int main() {

	testConsoleBankingApp();

	ConsoleBankingApp app;

	app.start_application();

	return 0;
}
