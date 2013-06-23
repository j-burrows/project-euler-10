/*--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemTen.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	A program that can find the sum of all primes below a given value and 
 |				display the result, where the given value is a user input.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		December 13th 2012.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef PROBLEMTEN_H
#define PROBLEMTEN_H 1

#include <stdio.h>
#include <inttypes.h>

#include "linkedlist_ull.h"
#include "Primes.h"
#include "inputs.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	sum_primes_below
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Finds and the sum of all prime numbers below a given value.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		below,		All primes must be below this to be added to sum.
 |	@return:	sum,		The sum of all prime numbers below the given value.
 |				0,			Either an error occured, or the given number was below 2.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Every number below a given value is checked to see it is prime by calling 
 | 				the function is_prime(). If so, its added to the sum and the list of known 
 | 				primes. Once all numbers below given value are checked the sums returned.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | 	Errors:		If memory could not be allocated for a new node on the list, an error value
 |				is returned.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern unsigned long long sum_primes_below(unsigned long long below);

#endif
