/*
 ============================================================================
 Name        : Faculty.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int main(void) {

	setbuf(stdout,NULL);

	int n, sum;

	printf("Enter digit to Faculty program(max: %d): ",MAX);
	scanf("%d",&n);

	sum = Faculty(n);

	printf("Sum of Faculty %d is: %d",n,sum);

	return EXIT_SUCCESS;
}

// Multiplies each number from user input number down to 0
// ie: 5 * res, 4*res,3*res..
int Faculty (int start){
	int res = 1; // res set to 1 because everything multiplied with 0 is 0

	if(start>0)
	{
		res = start * Faculty(start-1); // Calling itself but send in one less than input number
	}

	return res;
}
