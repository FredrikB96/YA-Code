/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>  SafeInput.c  <<<<<<<<<<<<<<<<<<<<<<<<
 Subject		: Safe input using string and filters
 Programmer		: Kjell H Carlsson
 Last update	: 2020-10-21
 ================================================================= */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DATE_LENGTH 10

int main()
{
char date[DATE_LENGTH + 1], temp;
int k=0;

		// Enter a string to buffer for input control
		printf("\n Enter a date (YYYY-MM-DD): ");	fflush(stdout);
		while ( (( temp=getchar()) != '\n') && (k<DATE_LENGTH) ){
			if (isdigit(temp) || temp=='-'){
				date[k++] = temp;
			}
		}

		date[k]='\0';
		printf("\n %s", date);

		if(strlen(date) == DATE_LENGTH)
			puts("\n Input accepted!");
		else
			puts("\n Input not accepted!");

return 0;
}
