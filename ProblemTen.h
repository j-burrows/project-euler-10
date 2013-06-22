/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
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

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	sum_primes_below
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Finds and the sum of all prime numbers below a given value.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		below,		All primes must be below this to be added to sum.
 |	@return:	sum,		The sum of all prime numbers below the given value.
 |				0,			Either an error occured, or the given number was below 2.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern unsigned long long sum_primes_below(unsigned long long below);

#endif
