/*
 * Student.cpp
 *
 *  Created on: Oct 24, 2021
 *      Author: Thuan Bach
 */

#ifndef SRC_CUSTOMER_STUDENT_CPP_
#define SRC_CUSTOMER_STUDENT_CPP_

#include "Student.h"

float Student::get_saving_interest() const {
	return 10;
}

 float Student::get_check_interest() const {
 	return 1;
 }

 float Student::get_check_charge() const {
 	return 0;
 }

 float Student::get_overdraft_penalty() const {
 	return 0;
 }


#endif /* SRC_CUSTOMER_STUDENT_CPP_ */
