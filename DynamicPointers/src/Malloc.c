/*
 *  Malloc.c
 *  Created on: 8 Oct 2020
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200
#define MOD 10

int main()
{
int n;
int *digitpnt, *ip;
srand(time(0));

	setbuf(stdout, NULL);

	printf("\n Dynamic memory allocation of n integers");
	do{
		printf("\n Enter number of random digits (max %d): ", MAX);
		scanf(" %d", &n);
	}while(!(n>0 && n<=MAX));

	// allocate dynamic memory if possible
	if ((digitpnt=(int *)malloc(sizeof(int)*n)) != NULL){

		printf("\n Random digits \n");
		for(ip=digitpnt; ip<digitpnt+n; ip++){
			*ip=rand() % MOD;
			printf(" %d", *ip);
		}
		free(digitpnt); // free allocated memory
	}
	else
		puts("\n Cannot allocate memory!!!");

return 0;
}
