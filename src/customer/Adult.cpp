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

#include "Adult.h"

/**
 * Returns a string represents a Adult customer type
 *
 * @return	string Returns a string represents a Adult customer type.
 */
string Adult::get_type_of_customer() const{
	return "Adult";
}

/**
 * Get savings interest
 *
 * @return	float The savings interest of Adult customers.
 */
float Adult::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

/**
 * Get checking interest
 *
 * @return	float The checking interest of Adult customers.
 */
 float Adult::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 /**
 * Get checking charge
 *
 * @return	float The checking charge of Adult customers.
 */
 float Adult::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 /**
 * Get overdraft penalty
 *
 * @return	float The checking charge of Adult customers.
 */
 float Adult::get_overdraft_penalty() const {
 	return OVERDRAFT_PENALTY;
 }

