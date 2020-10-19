/*
 *  Recall.c
 *  Created on: 8 Oct 2020
 *  Author: Kjell Carlsson
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MOD 10

int main()
{
int n, k;
int *digitpnt, *ip;
srand(time(0));

	setbuf(stdout, NULL);

	// allocate and reset memory locations to zero
	if( (digitpnt=(int*)calloc(MAX, sizeof(int)) ) != NULL) {
		printf("\n Reset memory for %d random digits \n", MAX);
		for(ip=digitpnt, k=1; ip<digitpnt+MAX; ip++, k++){
			printf(" %d", *ip);
		}

	  // get needed memory size via user input
	  do{
		  printf("\n\n Enter number of random digits (max %d): ", MAX);
		  scanf(" %d", &n);
	  }while(!(n>0 && n<=MAX));

	  // reallocate dynamic memory
	  digitpnt=(int *)realloc(digitpnt, sizeof(int)*n);
	  printf("\n Random digits \n");
	  for(ip=digitpnt, k=1; ip<digitpnt+n; ip++, k++){
		  *ip=rand() % MOD;
		  printf(" %d", *ip);
	  }

	  // free allocated memory
	  free(digitpnt);
	}
	else
		puts("\n Cannot allocate memory!!!");

return 0;
}
