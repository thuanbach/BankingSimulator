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

string Senior::get_type_of_customer() const{
	return "Senior";
}

float Senior::get_savings_interest() const {
	return SAVINGS_INTEREST;
}

 float Senior::get_checking_interest() const {
 	return CHECK_INTEREST;
 }

 float Senior::get_checking_charge() const {
	 return CHECK_CHARGE;
 }

 float Senior::get_overdraft_penality() const {
 	return OVERDRAFT_PENALTY;
 }
