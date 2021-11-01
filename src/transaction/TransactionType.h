/**
 *
 * @file TransactionType.h
 * @author Thuan Bach
 * @date October 24, 2021
 *
 * The file defines constants for transaction types
 *
 */

#ifndef SRC_BANK_TRANSACTIONTYPE_H_
#define SRC_BANK_TRANSACTIONTYPE_H_

/* A constant representing a deposit transaction */
const int	DEPOSITE = 1;

/* A constant representing a withdrawal transaction */
const int 	WITHDRAW = 2;

/* A constant representing a interest transaction */
const int	INTEREST = 3;

/* A constant representing a check charge transaction */
const int	CHKCHG = 4;

/* A constant representing a overdraft transaction */
const int	OVERDRAFT = 5;


#endif /* SRC_BANK_TRANSACTIONTYPE_H_ */
