/*
 * Numbers_Header.h
 *
 *  Created on: 19 okt. 2020
 *      Author: Benny
 */

#ifndef SRC_NUMBERS_HEADER_H_
#define SRC_NUMBERS_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 15

typedef struct{
	int high;
	int low;

}Values;


void Mean_Calculation(int *ptr, float *Mptr,int size);
/***** Mean_Calculation***********
 *	Using a pointer to a dynamic allocated memory block array of numbers
 *	adding the numbers together then dividing by the number of values defined in size
 *	to use this function send in the array of numbers by a pointer, a pointer to store the mean
 *	value used by pointer Mptr, then the number of values in the array by size
 */


Values High_Low(int *ptr, int size);
/***** High_Low *********
 * Checking the number array after the lowest and highest numbers
 * remember it expects a pointer not array[]
 */


#endif /* SRC_NUMBERS_HEADER_H_ */
