/*
 *  PrimeCheckMain.c
 *  Created on: 8 October 2020
 *  Author: Kjell H Carlsson
 */
#include <stdio.h>

#include "PrimeCheck.h"

extern uint16_t prime_count;

/* --------------------- Start of Main Program ------------------------ */
int main(int argc, char *argv[])
{
// test value input=11321 output Prime found!
// test value input=32648 output 2 2 2 7 11 53
// test value input=31 output Prime found!
// test value input=821238 output 2 3 11 23 541

	uint32_t temp_value, start_value;
	uint32_t factor=1;
	const char* output_msg;

	setbuf(stdout, NULL);

	// get a valid input value from user to check
	start_value = input_func();

	// pick out all even factors
	temp_value = handle_even_factors(start_value);

	// pick out all odd factors
	prime_count = handle_odd_factors(temp_value, factor);
	if(prime_count > 1){
		printf("\n Entered value %d holds %d factors", start_value, prime_count);
	}

	// present outcome of investigation
	output_msg = create_output_msg();

	printf(" %s", output_msg);
	putchar('\n');

	return 0;
}
