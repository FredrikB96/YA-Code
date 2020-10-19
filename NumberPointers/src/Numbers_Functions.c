/*
 * Numbers_Functions.c
 *
 *  Created on: 19 okt. 2020
 *      Author: Benny
 */

#include "Numbers_Header.h"

void Mean_Calculation(int *ptr, int *Mptr, int size)
{

	int temp = 0;

	for(int i=0;i<size;i++)
	{
		temp = temp + *ptr;
		*ptr++;
	}

	temp = temp / size;

	*Mptr = temp;
}
