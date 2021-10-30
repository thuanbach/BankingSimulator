/*
 * Senior.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_SENIOR_H_
#define SRC_SENIOR_H_

#include "Customer.h"

class Senior: public Customer {

public:

	Senior(string name, string address, int age, string phone_number) :
			Customer(name, address, age, phone_number) {
	}

    virtual float get_savings_interest() const;
	virtual float get_checking_interest() const;
	virtual float get_checking_charge() const;
	virtual float get_overdraft_penality() const;

	virtual string get_type_of_customer() const;
private:
	 const float SAVINGS_INTEREST = 0.06;
	 const float CHECK_INTEREST = 0.03;
	 const float CHECK_CHARGE = 0.02;
	 const float OVERDRAFT_PENALTY = 50.00;

};

#endif /* SRC_SENIOR_H_ */
