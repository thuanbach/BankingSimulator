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

//	Adult(string cus_name, string cus_address, int cus_age,
//			string cus_phone_number, string cus_number):
//
//	Customer(cus_name, cus_address, cus_age, cus_phone_number, cus_number) {};
	virtual float get_savings_interest() const;
	virtual float get_checking_interest() const;
	virtual float get_checking_charge() const;
	virtual float get_overdraft_penality() const;

	virtual string get_type_of_customer() const;

private:
	const float SAVINGS_INTEREST = 0.06;
	const float CHECK_INTEREST = 0.03;
	const float CHECK_CHARGE = 0.001;
	const float OVERDRAFT_PENALTY = 50.00;

};

#endif /* SRC_ADULT_H_ */
