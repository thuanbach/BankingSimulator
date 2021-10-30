/*
 * Adult.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: Thuan Bach
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

