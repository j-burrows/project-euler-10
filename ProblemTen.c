/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ProblemTen.c
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "ProblemTen.h"

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	sum_primes_below
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
unsigned long long sum_primes_below(unsigned long long below){
	unsigned long long sum, i;
	
	
	list_llu* primes;
	primes = init_list_llu(2);
	
	/*	There are no prime numbers below two, otherwise, the sum is set to two to start. */
	if( below <= 2){
		return 0;
	}
	sum = 2;
	/*	Goes through every value below, checks if prime, and if it is adds it's value to the
	 *	sum and adds a new node to the end of the list of prime numbers.	*/
	for(i=3;i<below;i++){
		/*	Checks if the number is prime.	*/
		if(is_prime(primes,i)){
			/*	Number is prime, add it to sum, and to the end of the list of primes.	*/
			sum += i;
			if(add_node_llu(primes, i) == 0){
				/*	Allocation of new node failed, free the list and return error value.*/
				free_list_llu(primes);
				return 0;
			}
		}
	}
	
	/*	Considers the case the given value is below the lowest prime number, 2.	*/
	if( below == 1 || below == 0){
		return 0;
	}
	free_list_llu(primes);
	return sum;
}

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	main
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Prompts the user for a number, then calculates and displays the sum of all
 |				primes below that number. Will close on command, or if an error occurs.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | 	Errors:		If an error occured in calculating the sum, the program exits.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int main(){
	unsigned long long below, sum;
	
	fprintf(stdout, "This program will find the sum all prime numbers that exist below "
			"a user entered value.\n");
	
	while(1){
		below = input_ull();
		
		/*	Calculates the sum, and checks if any errors occured during calculation.	*/
		sum = sum_primes_below(below);
		if( sum == 0 && (below != 0 && below != 1 && below != 2)){
			fprintf(stdout, "\nAn error occured whilst calcuating the sum of the primes.");
			break;
		}
		/*	No errors occured, print the sum to screen.	*/
		fprintf(stdout, "\nThe sum of the primes below %"SCNu64" is %"
				SCNu64, below, sum);
		
		/*	Checks if the user would like to perform another summation.	*/
		if( another_input() == 1){			/*User would like to, continue and prompt.*/
			continue;
		}
		else break;							/*No more operations desired, break and close.*/
	}
	
	countdown(5);							//Waits five seconds before closing
	return 0;
}
