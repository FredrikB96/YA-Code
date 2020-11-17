/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>  SafeInputFSM.c  <<<<<<<<<<<<<<<<<<<<<<<<
 Subject		: Safe input using FSM and general instring function
 Programmer		: Kjell H Carlsson
 Last update	: 2020-10-21
 ================================================================= */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10
#define DIGIT "0123456789"
#define MONTH "01"
#define DAY   "0123"
#define SEP   "-"
#define ENTER '\n'
#define EOS '\0'

// function prototypes
_Bool char_in_string(char ch, const char *filter);

/* ------------------------ Start of Main Program ------------------- */
int main()
{
char date[MAX+1], temp;
int k=0;
_Bool ok, error_flag;
char *fsm[MAX]={DIGIT,DIGIT,DIGIT,DIGIT, SEP, MONTH,DIGIT, SEP, DAY,DIGIT};

	setbuf(stdout, NULL);

	printf("\nEnter a date (YYYY-MM-DD): ");
	// repeat input until Enter or string full
	while ( (( temp=getchar()) != ENTER) && (k<MAX ) ){
		// test if character ok using FSM
		ok = char_in_string(temp, fsm[k]);

		// store character in date string if ok
		if (ok){
			date[k++] = temp;
		}
	}
	date[k]=EOS;
	printf("\n Filtered input %s", date);

	// test if month is possible
	error_flag = (date[5]=='1' && date[6]>'2')? true: false;
	error_flag = (date[5]=='0' && date[6]=='0')? true: error_flag;
	// test if day is possible
	error_flag = (date[8]=='3' && date[9]>'1')?  true: error_flag;
	error_flag = (date[8]=='0' && date[9]=='0')?  true: error_flag;
	// test if input string has correct length
	error_flag = (strlen(date) != MAX)? true: error_flag;

   if(!error_flag)
	       puts("\n Input accepted!");
   else
          puts("\n Input not accepted!");
return 0;
}

/******************* function char_in_string ***********************
 General function for test if a character occurs in a string
 input  - wanted char, string to examine
 output - Boolean true/false (found/not found)
********************************************************************/
_Bool char_in_string(char ch, const char *filter)
{
_Bool ok = false;

	printf("Debug: current FSM filter %s \n", filter);
	// test for a character within filter string until EOS or found
	while((*filter != EOS) && ok==false){
		ok = (ch == *filter++)? true: ok;
	}
	printf("Debug: character %c accepted %d \n", ch, ok);

return ok;
}
