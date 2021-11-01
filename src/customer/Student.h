/**
 *
 * @file Student.h
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * The Student class extends from the Customer and contains its own configuration for interest rates,
 * checking charges or overdraft penalty for this kind of the Customer.
 *
 */
#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include "Customer.h"

class Student: public Customer {
public:

	/**
	 * Constructor
	 *
	 * @param	name Name of a Student customer.
	 * @param	address	The address of a Student customer.
	 * @param	age	The age of a Student customer.
	 */
	Student(string name, string address, int age, string phone_number) :
				Customer(name, address, age, phone_number){
	}

	/**
	 * Get savings interest
	 *
	 * @return	float The savings interest of Student customers.
	 */
    virtual float get_savings_interest() const;


	/**
	 * Get checking interest
	 *
	 * @return	float The checking interest of Student customers.
	 */
	virtual float get_checking_interest() const;

	/**
	 * Get checking charge
	 *
	 * @return	float The checking charge of Student customers.
	 */
	virtual float get_checking_charge() const;

	/**
	 * Get overdraft penalty
	 *
	 * @return	float The overdraft penalty of Student customers.
	 */
	virtual float get_overdraft_penalty() const;

    /**
	 * Returns a string represents a Student customer type
	 *
	 * @return	string Returns a string represents a Student customer type.
	 */
    virtual string get_type_of_customer() const;


private:
    	/* Define a constant for savings interest of Student customer*/
	 const float SAVINGS_INTEREST = 0.05;

	 /* Define a constant for checking interest of Student customer*/
	 const float CHECK_INTEREST = 0.01;

	 /* Define a constant for checking charge of Student customer*/
	 const float CHECK_CHARGE = 0.02;

	 /* Define a constant for overdraft penalty of Student customer*/
	 const float OVERDRAFT_PENALTY = 30.00;
};

#endif /* SRC_STUDENT_H_ */
