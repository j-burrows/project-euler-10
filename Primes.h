/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	Primes.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions for making lists of primes, and determing if numbers are
 |				prime.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		Nov 20 2012
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef PRIMES_H
#define PRIMES_H 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "linkedlist_ull.h"

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	is_prime
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Checks if a given number is prime.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		primes,				The list of known primes.
 |				number, 			The number who will be checked to see if a prime.
 |	@return:	is_prime,			1 if number is prime.
 |									0 if number is not prime.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Checks if the number has any prime decomposites. If it does, it cannot be
 |				prime. Prime decomposites are primes that have a modularity of zero with it,
 |				and are between 2 and the square root of the number. Every prime below the
 |				square root of two in the primes list is checked for modularity with the 
 |				number. If no matches, 1 is returned. Otherwise, 0 is returned.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int is_prime(list_llu* primes, unsigned long long number);

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	add_if_prime
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	If the given number is a prime, it is added to the end of the list.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		primes,				The list of known primes.
 |				number, 			the number that is checked to be prime.
 |	@return:	1,					The check and add was successful.
 |				0,					There was an error while adding a prime number to list. 
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	A function is called to see if it is prime. If it is, another function is 
 |				called to add it to the end of the list.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int add_if_prime(list_llu* primes, unsigned long long number);

#endif
