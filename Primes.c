/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	Primes.c
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "Primes.h"

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	is_prime
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
