/*
 *  VarArg_1.c
 *  Created on: 20 okt. 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdarg.h>

// function prototype
long int sumofints(int args, int first, ...);

/* --------------------- Start of Main Program ------------------------ */
int main()
{
long int sum;

	printf("\n\n List of integers: ");
	sum = sumofints(4, 15, 11, 39, 42);
	printf("\n Sum of numbers is: %ld", sum);

	printf("\n\n List of integers: ");
	sum = sumofints(5, 30000, 25, 20000, 15, 10000);
	printf("\n Sum of numbers is: %ld", sum);

	printf("\n\n List of integers: ");
	sum = sumofints(1, 100);
	printf("\n Sum of numbers is: %ld", sum);

	printf("\n---------------- End of program ----------------");

return 0;
}

long int sumofints(int args, int first, ...)
{
long int tempsum=0;
int val;
va_list argptr;

	// test if there are any arguments in list
	if(args){
		// decrease counter and print out first argument
		args--;
		printf(" %d", first);
		tempsum += first;

		// init pointer to first argument in list
		va_start(argptr, first);

		// read arguments from list until end of list
		while(args--){
			val=va_arg(argptr, int);
			printf(" %d", val);
			tempsum += val;
		}

		// set argument pointer to NULL at end of list
		va_end(argptr);
	}

return tempsum;
}
