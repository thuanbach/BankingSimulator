/**
 *
 * @file Customer.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This module is used to store customers' information such as name, age, address, or phone number.
 * There are 3 derived classes from the Customer class. Each kind of customer will have its own interest rates,
 * checking charges or overdraft penalty
 *
 */
#ifndef SRC_CUSTOMER_H_
#define SRC_CUSTOMER_H_
#include <iostream>

using namespace std;

class Customer {

public:
	Customer() :
			customer_number(-1), name(""), address(""), age(-1),
			phone_number("") {
	}

	Customer(string cus_name, string cus_address, int cus_age,
			string cus_phone_number) :
			customer_number(-1), name(cus_name), address(cus_address), age(
					cus_age), phone_number(cus_phone_number) {
	}

	virtual ~Customer() {

	}

	int get_customer_number() const;
	int get_age() const;
	string get_name() const;
	string get_address() const;
	string get_telephone_number() const;

	void set_customer_number(int customer_number);
	void set_name(string &name);
	void set_address(string &address);
	void set_age(int age);
	void set_telephone_number(string &phone_number);

	virtual string get_type_of_customer() const;
	virtual float get_savings_interest() const = 0;
	virtual float get_checking_interest() const = 0;
	virtual float get_checking_charge() const = 0;
	virtual float get_overdraft_penality() const = 0;

protected:
	int customer_number;
	std::string name;
	std::string address;
	int age;
	std::string phone_number;

};

#endif /* SRC_CUSTOMER_H_ */
