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


string Adult::get_type_of_customer() const{
	return "Adult";
}

float Adult::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

 float Adult::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 float Adult::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 float Adult::get_overdraft_penality() const {
 	return OVERDRAFT_PENALTY;
 }

