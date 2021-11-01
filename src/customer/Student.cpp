/**
 *
 * @file Student.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * The Student class extends from the Customer and contains its own configuration for interest rates,
 * checking charges or overdraft penalty for this kind of the Customer.
 *
 */
#ifndef SRC_CUSTOMER_STUDENT_CPP_
#define SRC_CUSTOMER_STUDENT_CPP_

#include "Student.h"

string Student::get_type_of_customer() const{
	return "Student";
}

float Student::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

 float Student::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 float Student::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 float Student::get_overdraft_penality() const {
 	return OVERDRAFT_PENALTY;
 }


#endif /* SRC_CUSTOMER_STUDENT_CPP_ */
