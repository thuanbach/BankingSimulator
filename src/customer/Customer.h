/*
 * Customer.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_CUSTOMER_H_
#define SRC_CUSTOMER_H_
#include <iostream>

using namespace std;

class Customer {

public:
	Customer() { // @suppress("Class members should be properly initialized")
	}

	Customer(string cus_name, string cus_address, int cus_age, // @suppress("Class members should be properly initialized")
			string cus_phone_number) :

			name(cus_name), address(cus_address), age(cus_age), phone_number(
					cus_phone_number), customer_number() {
	}

	virtual ~Customer() {

	}
	virtual float get_saving_interest() const;
	virtual float get_check_interest() const;
	virtual float get_check_charge() const;
	virtual float get_overdraft_penalty() const;

	string get_name() const;
	string get_address() const;
	int get_age() const;
	string get_telephone_number() const;
	string get_customer_number() const;

	void set_name(string &name);
	void set_address(string &address);
	void set_age(int age);
	void set_telephone_number(string &phone_number);
	void set_customer_number(string &customer_number);

protected:
	std::string name;
	std::string address;
	int age;
	std::string phone_number;
	std::string customer_number;

	float saving_interest;
	float check_interest;
	float check_charge;
	float overdraft_penalty;
private:

};

#endif /* SRC_CUSTOMER_H_ */
