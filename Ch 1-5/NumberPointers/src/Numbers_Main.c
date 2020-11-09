/*
 * Numbers_Main.c
 *
 *  Created on: 19 okt. 2020
 *      Author: Benny
 */

#include "Numbers_Header.h"

int main(){
	// Declaring variables and clearing output buffer
	setbuf(stdout,NULL);
	srand(time(0));

	float Mean_Value = 0;
	float *Mptr = &Mean_Value;
	int size = 0;
	char Input[MAX];
	int p = 0; // Iteration variable



		// Getting the size of the array with input control
		printf("\n How many numbers do you want the array to consist of? ");
		char temp;
		for(int i=0;temp !='\n';i++)
		{
			temp = getchar();
			if(temp>='0'&&temp<='9')
			{
				Input[p] = temp;
				p++;
			}
		}
		size = atoi(Input); // Getting the value of the array, will remove end of string character and store the rest.
		if(size>MAX)
		{
			printf("\n Expects a number less than %d", MAX);
			size = MAX;
		}


	// Creating an dynamic allocated memory block to create an array
	// We need to keep two pointers, one as safeguard and one to move
	int *Nptr, *Sptr;
	if((Nptr=(int*)malloc(sizeof(int)*size))==NULL)
	{
		printf("\n Too much memory requested!");
	} else
	{
		Sptr = Nptr;
	}

	for(int i=0;i<size;i++)
	{
		*Nptr = rand() % 99;
		Nptr++;
	}

	// Returning Nptr pointer to start address, to enable printout of all values later
	Nptr = Sptr;
	printf("\n the %d numbers are: ", size);

	for(int i=0;i<size;i++)
	{
		printf(" %d", *Nptr);
		Nptr++;
	}

	Nptr = Sptr; // returning Nptr to Safeguard pointer (Sptr)

	// Calling Mean value and storing in Mptr
	Mean_Calculation(Nptr, Mptr,size);

	// Calling funtion that checks for highest and lowest number in the memory blockS
	Values stat = High_Low(Nptr, size);

	printf("\n High number are: %d \n Low Number are: %d",stat.high,stat.low);
	printf("\n Mean value are: %2f", *Mptr);
	free(Sptr);
	return 0;
}
