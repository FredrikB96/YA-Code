/*
 * Main_File.c
 *
 *  Created on: 12 okt. 2020
 *      Author: Benny
 */

#include "header.h"

int main(void) {

	int Array1[MAX],Array2[MAX];
	int *p1,*p2;

	srand(time(0));

	for(p1=Array1;p1 < Array1 + MAX;p1++)
	{
		*p1 = rand() % 50;
	}

	for(p2 = Array2;p2 < Array2 + MAX; p2++)
	{
		*p2 = rand() % 50;
	}
	p1 = Array1;
	p2 = Array2;

	int med1 = Calculate_Median(p1);
	int med2 = Calculate_Median(p2);

	PrintOut(med1,med2,p1,p2);

	return EXIT_SUCCESS;
}
