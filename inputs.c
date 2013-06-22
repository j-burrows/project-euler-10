/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	inputs.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions for main methods that involve inputting data and exiting.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 17th 2012
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Dependancy:	stdlib.h				
 |				stdio.h	
 |				string.h
 |				time.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "inputs.h"

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	input_ull
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Prompts and retreives a user entered number. Sends -1 to signify close.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	ull_input,			The number the user entered.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | 	Errors:		A non number value entered will cause unexpected results.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
unsigned long long input_ull(){
	unsigned long long ull_input;
	fprintf(stdout, "\nPlease enter a value. A non number value will cause the "
					"unexpected behavour.\n\t\t\t\t->");
	scanf("%"SCNu64, &ull_input);
	
	return ull_input;
}

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	another_input
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Asks the user to enter if they would like to enter another input. 
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@return:	1,					Another input is desired.
 |				0,					Another input is not desired.
 |				-2,					A memory allocation was unsuccessful.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	The user will be continously prompted to enter yes or no until they do enter
 |				either yes, no, y, or n. Once they do, entering y or yes will result in 1
 |				being returned. no or n will result in 0 being returned.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Note: 		If a memory allocation fails, a value of -2 is returned.
 | 	Errors:		If the inputted string is over 128 characters long, the program will crash.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int another_input(){
	char* string_input;							/*Buffer for the inputted word.*/
	int another;								/*Boolean value for to continue or not*/
	int i;										/*Loop control.*/
	
	/*	Allocates memory, checks if successful.	*/
	if( (string_input = malloc(128*sizeof(char))) == NULL){
		/*	Unsuccessful, return error value.	*/
		return -2;
	}
	
	/*	Asks the user to enter yes or no until they do enter yes, no, y, or n.	*/
	while(1){
		fprintf(stdout, "\n\nWould you like to do another process,"
						" enter yes or no?:\n\t\t\t\t->");
		
		scanf("%s", string_input);
		
		/*	Sets to lower case to make commands not case sensitive.	*/
		for(i=0;i<strlen(string_input);i++){
			string_input[i] = tolower(string_input[i]);
		}
		
		/*	Checks if a valid command was entered.	*/
		if(strcmp(string_input,"yes")==0 || strcmp(string_input,"y")==0){
			another = 1;						/*Given value for another input wanted.*/
			break;
		}
		if(strcmp(string_input,"no")==0 || strcmp(string_input,"n")==0){
			another = 0;						/*Given value for another input not wanted*/
			break;
		}
		else{									/*Invalid command, prompted again.*/
			fprintf(stdout, "\nInvalid input...");
		}
	}
	
	free(string_input);							/*string_input is never used again.*/
	string_input = NULL;
	
	return another;
}

/*
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	countdown
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	This function waits a given time in seconds, while displaying the time left
 |				in a countdown.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		timeout,			the number of seconds that will be counted down from.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		An additional second waited because if the computers time is close to 
 |				rolling over, a the full timout	time will not be waited.
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void countdown(int timeout){
	time_t current_second, next_second;
	
	/*	Finds the value of the next second according to the internal clock.	*/
	current_second = time(NULL);
	next_second = current_second + 1;
	
	/*	Waits till the clock rolls over to the next second before countdown.	*/
	while( (current_second = time(NULL)) < next_second);
	
	/*	Counts down in seconds the time remaining.	*/
	while(timeout > 0){
		/*	Time left until timeout is displayed.	*/
		fprintf(stdout, "%d...",timeout);
		/*	Waits until a until the time is the next second.	*/
		current_second = time(NULL);
		next_second = current_second + 1;
		while((current_second = time(NULL)) < next_second);
		/*	A second has been waited, timeout left is decrimented.	*/
		timeout--;
	}
}
