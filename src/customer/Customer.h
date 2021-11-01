/**
 *
 * @file Customer.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * This is used to store customers' information such as name, age, address, or phone number.
 * There are 3 derived classes from the Customer class. Each kind of customer will have its own interest rates,
 * checking charges or overdraft penalty.
 *
 */
#ifndef SRC_CUSTOMER_H_
#define SRC_CUSTOMER_H_
#include <iostream>

using namespace std;

class Customer {

public:

	/**
	 * Default constructor
	 */
	Customer() :
			customer_number(-1), name(""), address(""), age(0), phone_number("") {
	}

	/**
	 * Constructor
	 * @param	cus_name Name of a customer.
	 * @param	cus_address	The address of a customer.
	 * @param	cus_age	The age of a customer.
	 * @param	cus_phone_number The phone number of a customer.
	 *
	 */
	Customer(string cus_name, string cus_address, int cus_age,
			string cus_phone_number) :
			customer_number(-1), name(cus_name), address(cus_address), age(
					cus_age), phone_number(cus_phone_number) {
	}

	/**
	 * De-constructor
	 */
	virtual ~Customer() {}

	/**
	 * Returns a customer number.
	 *
	 * @return int The customer number
	 */
	int get_customer_number() const;

	/**
	 * Returns a customer age.
	 *
	 * @return int The Customer age
	 */
	int get_age() const;

	/**
	 * Returns a customer name.
	 *
	 * @return string The customer name
	 */
	string get_name() const;

	/**
	 * Returns a customer name.
	 *
	 * @return string The customer address
	 */
	string get_address() const;

	/**
	 * Returns a customer name.
	 *
	 * @return string The customer phone number
	 */
	string get_telephone_number() const;

	/**
	 * Update the customer number
	 *
	 * @param int The customer number
	 * @return N/A
	 */
	void set_customer_number(int customer_number);

	/**
	 * Update the customer name
	 *
	 * @param int The customer name
	 * @return N/A
	 */
	void set_name(string &name);

	/**
	 * Update the customer address
	 *
	 * @param int The customer address
	 * @return N/A
	 */
	void set_address(string &address);

	/**
	 * Update the customer address
	 *
	 * @param int The customer age
	 * @return N/A
	 */
	void set_age(int age);


	/**
	 * Update the phone number
	 *
	 * @param string The customer phone number
	 * @return N/A
	 */
	void set_telephone_number(string &phone_number);

	/**
	 * Abstract function that returns the type of Customer
	 *
	 * @return string	Presents the type of Customer
	 */
	virtual string get_type_of_customer() const = 0;

	/**
	 * Abstract function that returns the savings interest, will be implemented by derived classes
	 *
	 * @return float	The savings interest for this Customer
	 */
	virtual float get_savings_interest() const = 0;

	/**
	 * Abstract function that returns the savings interest, will be implemented by derived classes
	 *
	 * @return float	The checking interest for this Customer
	 */
	virtual float get_checking_interest() const = 0;

	/**
	 * Abstract function that returns the checking charge, will be implemented by derived classes
	 *
	 * @return float	The checking charge for this Customer
	 */
	virtual float get_checking_charge() const = 0;

	/**
	 * Abstract function that returns the overdraft penalty, will be implemented by derived classes
	 *
	 * @return float	The checking charge for this Customer
	 */
	virtual float get_overdraft_penalty() const = 0;

protected:
	int customer_number;
	std::string name;
	std::string address;
	int age;
	std::string phone_number;

};

#endif /* SRC_CUSTOMER_H_ */
