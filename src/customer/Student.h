/*
 * Student.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include "Customer.h"

class Student: public Customer {
public:
	Student(string name, string address, int age, string phone_number) :
				Customer(name, address, age, phone_number){
	}

	virtual string get_type_of_customer() const;


    virtual float get_savings_interest() const;
    virtual float get_checking_interest() const;
    virtual float get_checking_charge() const;
    virtual float get_overdraft_penality() const;


private:
	 const float SAVINGS_INTEREST = 0.05;
	 const float CHECK_INTEREST = 0.01;
	 const float CHECK_CHARGE = 0.02;
	 const float OVERDRAFT_PENALTY = 30.00;
};

#endif /* SRC_STUDENT_H_ */
