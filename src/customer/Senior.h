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
	virtual float get_saving_interest() const;
	virtual float get_check_interest() const;
	virtual float get_check_charge() const;
	virtual float get_overdraft_penalty() const;
private:

};

#endif /* SRC_SENIOR_H_ */
