/*
 *  NumFuncPnt.c
 *  Created on: 20 okt. 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 20
#define MOD 100

// function prototypes - NB! same return type and same type of args
int func_high(int *list, int n);
int func_low(int *list, int n);
int Sum_Calc(int *list, int n);
int Mean_Value(int *list, int n);

// --------------------- Start of Main Program ------------------------
int main()
{
int numlist[ARRAY_SIZE], n, res;
_Bool error_flag = false;
// define a function pointer
int (*funcpnt)(int*, int);

	srand(42);

	setbuf(stdout, NULL);

	do{
		fflush(stdin);
   		printf("\n Enter number of integers (max 20): ");
	   	scanf(" %d", &n);
   	}while(!(n>0 && n<=ARRAY_SIZE));

	for(int k=0; k<n; k++){
		numlist[k]= rand() % MOD;
      	printf("%3d", numlist[k]);
	}
   	printf("\n\n Statistics for integer array");
   	printf("\n 1 - Highest value");
   	printf("\n 2 - Lowest value");
   	printf("\n 3 - Sum of values");
   	printf("\n 4 - Mean Value");
	printf("\n\n Choose function (1-4): ");
	fflush(stdin);
	char mode;
	scanf(" %c", &mode);

	// set funcpnt to 1 of 2 functions
	switch(mode){
		 case '1' :	 funcpnt=func_high;	 break;
		 case '2' :	 funcpnt=func_low;	 break;
		 case '3' :  funcpnt=Sum_Calc;	 break;
		 case '4' :  funcpnt=Mean_Value; break;
		 default  :	 error_flag = true;
	}

   	if(!error_flag){
		// call function via function pointer
		res=funcpnt(numlist, n);
		printf(" Result after calculation: %d ", res);
	}
	else
		 printf(" Wrong menu choice");

printf("\n\n-------------------- End of program -------------------\n");
return 0;
}

// func_high() gets highest value in list of numbers
int func_high(int *list, int n)
{
int high;

   	high=*list;
    	// go thru entire list looking for highest value
    	for(int k=0; k<n; k++){
        if(*list>high)
             high=*list;
        list++;
    	}

return high;
}
// ------------------------- end of function -----------------------

// func_low() gets lowest value in list of numbers
int func_low(int *list, int n)
{
int low;

   	low=*list;
    	// go thru entire list looking for lowest value
    	for(int k=0; k<n; k++){
        if(*list<low)
             low=*list;
        list++;
    	}

return low;
}
// ------------------------- end of function -----------------------

// Sumc_Calc() gets the sum of numbers in list
int Sum_Calc(int *list, int n)
{
	int res = 0;

	if(n>0)
	{
//		printf("\n Debug: n is: %d", n);
//		printf("\n Debug: list is: %d",list[n-1]);

		// Wanted to train on calling itself, could have used for loop
		// because I used value n i had to remove 1 from n when interacting with list
		// Because an array have position 0-4 when value 5 entered, so position '5' is 4

		res += list[--n]+Sum_Calc(list,n);

	}

//	printf("\n Debug: res is: %d",res);
	return res;
}
// ------------------------- end of function -----------------------


int Mean_Value(int *list, int n)
{
	int res;
	int temp = Sum_Calc(list,n);

	res = temp / n;

	return res;
}
