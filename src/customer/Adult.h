/**
 *
 * @file Adult.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * The Adult class extends from the Customer and contains its own configuration for interest rates,
 * checking charges or overdraft penalty for this kind of the Customer.
 *
 */

#ifndef SRC_ADULT_H_
#define SRC_ADULT_H_

#include <iostream>
#include "Customer.h"

using namespace std;

class Adult: public Customer {

public:

	/**
	 * Constructor
	 *
	 * @param	name Name of a Adult customer.
	 * @param	address	The address of a Adult customer.
	 * @param	age	The age of a Adult customer.
	 */
	Adult(string name, string address, int age, string phone_number) :
			Customer(name, address, age, phone_number) {
	}

	/**
	 * Get savings interest
	 *
	 * @return	float The savings interest of Adult customers.
	 */
	virtual float get_savings_interest() const;


	/**
	 * Get checking interest
	 *
	 * @return	float The checking interest of Adult customers.
	 */
	virtual float get_checking_interest() const;

	/**
	 * Get checking charge
	 *
	 * @return	float The checking charge of Adult customers.
	 */
	virtual float get_checking_charge() const;

	/**
	 * Get overdraft penalty
	 *
	 * @return	float The checking charge of Adult customers.
	 */
	virtual float get_overdraft_penalty() const;

	/**
	 * Returns a string represents a Adult customer type
	 *
	 * @return	string Returns a string represents a Adult customer type.
	 */
	virtual string get_type_of_customer() const;

private:
	/* Define a constant for savings interest of Adult customer*/
	const float SAVINGS_INTEREST = 0.03;

	/* Define a constant for checking interest of Adult customer*/
	const float CHECK_INTEREST = 0.005;

	/* Define a constant for checking charge of Adult customer*/
	const float CHECK_CHARGE = 0;

	/* Define a constant for overdraft penalty of Adult customer*/
	const float OVERDRAFT_PENALTY = 50.00;

};

#endif /* SRC_ADULT_H_ */
