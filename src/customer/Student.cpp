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

#include "Student.h"

string Student::get_type_of_customer() const{
	return "Student";
}

/**
 * Get savings interest
 *
 * @return	float The savings interest of Student customers.
 */
float Student::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

/**
 * Get checking interest
 *
 * @return	float The checking interest of Senior customers.
 */
 float Student::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 /**
 * Get checking charge
 *
 * @return	float The checking charge of Senior customers.
 */
 float Student::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 /**
 * Get overdraft penalty
 *
 * @return	float The checking charge of Senior customers.
 */
 float Student::get_overdraft_penalty() const {
 	return OVERDRAFT_PENALTY;
 }

