/*
 ============================================================================
 Name        : Number_Array_Median.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "header.h"

int Calculate_Median(int *temp)
{

	int median = 0;


	int size = MAX / 2; // MAGIC NUMBERS!!
	// This is because we have to divide by 2, this will round it down so we
	// increment one position to get the middle number.

//	int size = sizeof(*temp) / sizeof(int);

	median = temp[size];


	return median;
}

void PrintOut(int *median1,int *median2, int *temp1,int *temp2)
{

	setbuf(stdout,NULL); // Clear the buffer to enable printout

	printf("\n Median of first array are: %d", median1); // printing out the median value of the first array
	printf("\n The numbers are: ");

	// for loop to print out each array positions value
	for(int i=0;i<MAX;i++)
	{
		printf(" %d", temp1[i]);
	}

	printf("\n");

	printf("\n Median of second array are: %d", median2);
	printf("\n The numbers are: ");

	for(int i=0;i<MAX;i++)
	{
		printf(" %d", temp2[i]);
	}

}
