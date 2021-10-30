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

	virtual string get_type_of_customer() const;

	string get_name() const;
	string get_address() const;
	int get_age() const;
	string get_telephone_number() const;
	int get_customer_number() const;

	void set_name(string &name);
	void set_address(string &address);
	void set_age(int age);
	void set_telephone_number(string &phone_number);
	void set_customer_number(int customer_number);

    virtual float get_savings_interest() const = 0;
    virtual float get_checking_interest() const = 0;
    virtual float get_checking_charge() const = 0;
    virtual float get_overdraft_penality() const = 0;

//    void set_savings_interest(float interest);
//	void set_checking_interest(float interest);
//	void set_checking_charge(float charge_amount);
//	void set_overdraft_penality(float overdraft_amount);


protected:
	std::string name;
	std::string address;
	int age;
	std::string phone_number;
	int customer_number;

//	float saving_interest;
//	float check_interest;
//	float check_charge;
//	float overdraft_penalty;
//
//	 const float SAVINGS_INTEREST;
//	 const float CHECK_INTEREST;
//	 const float CHECK_CHARGE;
//	 const float OVERDRAFT_PENALTY;

private:

};

#endif /* SRC_CUSTOMER_H_ */
