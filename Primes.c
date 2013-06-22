/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	Primes.c
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions for making lists of primes, and determing if numbers are
 |				prime.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		Nov 20 2012
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	References:	Primes.h			predeclares all functions.
 |				linkedlist_ull.h	Has the structures and functions for unsigned long long
 |									lists.
 |	Dependancy:	<stdlib.h>			NULL
 |									malloc
 |				<math.h>			sqrt
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "Primes.h"

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
int is_prime(list_llu* primes, unsigned long long number){
	node_llu* conductor;					/*Used for traversing the list.*/
	int number_is_prime;					/*Boolean value determining if number is prime*/
	int	seeve;								/*Loop control (max prime decomposite value).*/
	
	seeve = sqrt(number);					/*	Sets the seeve.	*/
	number_is_prime = 1;
	/*	Every known prime is checked for modularity with the number.	*/
	/*	Searches the list, starting at the head, until the list runs out or the value of
	 *	seeve is passed.	*/
	for(conductor=primes->head; conductor!=NULL && conductor->value <= seeve;
		conductor=conductor->next){
		/*	Checks modularity.	*/
		if((number%(conductor->value))!=0){	/*Is not modular.*/
			continue;
		}
		else{								/*Is modular*/
			number_is_prime = 0;			/*Cannot be prime, set to reflect.*/
			break;
		}
	}
	
	/*1 if and only if the number is prime. 0 if the number is not prime.*/
	return number_is_prime;
}

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
int add_if_prime(list_llu* primes, unsigned long long number){
	/*	Number is checked to see if it is prime.	*/
	if(is_prime(primes,number)){			/*It is prime.*/
		/*A node with the given value is added to the end of the list.*/
		if(add_node_llu(primes,number) == 0){
			return 0;						/*Allocation failed, return error value.*/
		}
	}
	
	return 1;								/*Check and/or add successful.*/
}
