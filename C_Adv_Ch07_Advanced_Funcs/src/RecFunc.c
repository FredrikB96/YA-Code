/*
 *  RecFunc.c
 *  Created on: 20 okt. 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#define MAX 100

// function prototype
int sumofnums(int start);

int main()
{
int n, sum;

	setbuf(stdout, NULL);

	do{
		printf("\n Enter an int for calculation of sum of 1-> n (1-%d): ", MAX);
		scanf(" %d", &n);
	}while(!(n>0 && n<=MAX));

	sum=sumofnums(n);
	printf("\n Sum of numbers 1 to %d = %d", n, sum);

return 0;
}

// a recursive function
int sumofnums(int start)
{
int res=0;

//	printf("\n DEBUG: --- Entering function start %d", start);
	if(start>0){
		res=start+sumofnums(start-1);
	}
//	printf("\n DEBUG: *** Leaving function res %d", res);

return res;
}
