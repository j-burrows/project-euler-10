/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	inputs.h
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "inputs.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	input_ull
 --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
unsigned long long input_ull(){
	unsigned long long ull_input;
	fprintf(stdout, "\nPlease enter a value. A non number value will cause the "
					"unexpected behavour.\n\t\t\t\t->");
	scanf("%"SCNu64, &ull_input);
	
	return ull_input;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	another_input
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

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	countdown
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
