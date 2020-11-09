/*
 * Numbers_Functions.c
 *
 *  Created on: 19 okt. 2020
 *      Author: Benny
 */

#include "Numbers_Header.h"


void Mean_Calculation(int *ptr, float *Mptr, int size)
{

	// creating a temp variable to store the sum of the numbers added together
	float temp = 0;
	float Median = 0;

	// Adding all numbers together as long as i is less then the number of values in the memory block
	for(int i=0;i<size;i++)
	{
		temp = temp + *ptr;
		ptr++;
	}

	// Getting the median by dividing the sum with the number of values
	Median = temp/size;

	// Assigning the value of the pointer Mptr to the result of Median equation
	*Mptr = Median;
}

Values High_Low(int *ptr, int size)
{

	// Creating a struct called ref to hold high and low values
	Values ref;
	ref.high = *ptr; // Assigning temporary value to enable check of higher or lower
	ref.low = *ptr;

	for(int i=0;i<size;i++)
	{
		if(*ptr>ref.low)
		{
			ref.low = *ptr;
		}
		if(*ptr<ref.high)
		{
			ref.high = *ptr;
		}
		ptr++;
	}
	// returning Value struct called ref
	return ref;
}
