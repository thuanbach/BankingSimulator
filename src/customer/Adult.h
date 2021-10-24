/*
 * Adult.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_ADULT_H_
#define SRC_ADULT_H_

#include <iostream>
#include "Customer.h"

using namespace std;

class Adult: public Customer {

public:
	Adult(string name, string address, int age, string phone_number) :
					Customer(name, address, age, phone_number) {
			}
	const float SAVINGS_INTEREST = 0.5;
	const float CHECK_INTEREST = 0.5;
	const float CHECK_CHARGE = 0.1;
	const float OVERDRAFT_PENALTY = 0.3;


//	Adult(string cus_name, string cus_address, int cus_age,
//			string cus_phone_number, string cus_number):
//
//	Customer(cus_name, cus_address, cus_age, cus_phone_number, cus_number) {};
	virtual float get_saving_interest() const;
	virtual float get_check_interest() const;
	virtual float get_check_charge() const;
	virtual float get_overdraft_penalty() const;

};

#endif /* SRC_ADULT_H_ */
