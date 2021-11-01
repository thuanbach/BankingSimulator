/**
 *
 * @file Senior.cpp
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * The Senior class extends from the Customer and contains its own configuration for interest rates,
 * checking charges or overdraft penalty for this kind of the Customer.
 *
 */
#include "Senior.h"

/**
 * Returns a string represents a Senior customer type
 *
 * @return	string Returns a string represents a Senior customer type.
 */
string Senior::get_type_of_customer() const{
	return "Senior";
}

/**
 * Get savings interest
 *
 * @return	float The savings interest of Senior customers.
 */
float Senior::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

/**
 * Get savings interest
 *
 * @return	float The checking interest of Senior customers.
 */
 float Senior::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 /**
 * Get savings interest
 *
 * @return	float The checking charge of Senior customers.
 */
 float Senior::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 /**
 * Get savings interest
 *
 * @return	float The checking charge of Senior customers.
 */
 float Senior::get_overdraft_penalty() const {
 	return OVERDRAFT_PENALTY;
 }
