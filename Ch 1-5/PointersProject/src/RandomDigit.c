/*
 *  RandomDigit.c
 *  Created on: 8 Oct 2020
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 5
#define MOD 10

int main()
{
int *ip;
int digit[MAX], k, n;

srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Using pointers to populate an array \n");

	printf("\n Enter number of random digits(max %d): ", MAX);
	scanf(" %d", &n);

	for(ip=digit, k=1; ip<&digit[n]; ip++, k++){
		*ip=rand() % MOD;
		printf("\n Random digit %d = %d ", k, *ip);
	}

return 0;
}

