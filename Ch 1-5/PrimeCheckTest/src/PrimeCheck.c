/*
 PrimeCheck.c
 Subject        : C Functions introduced
 Programmer  	: Kjell H Carlsson
 Last update	: 2020-10-08
 ================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

#define LOWEST_FACTOR 2

// global variable available in all functions
uint16_t prime_count = 0;


uint32_t input_func()
{
	uint32_t input_value;

	do{
		printf("\n Enter a number in range (%d-%d) : ", LOWEST_FACTOR, INT_MAX);
		scanf(" %d", &input_value);
		if(input_value<LOWEST_FACTOR || input_value>INT_MAX){
			printf("\n *** Value not in range!");
		}
	}while( !(input_value>0 && input_value<=INT_MAX));

	return input_value;
}


uint32_t handle_even_factors(const uint32_t start_value)
{
	uint32_t temp_value = start_value;

	// pick out all even factors if any
	while(temp_value % LOWEST_FACTOR == 0){
		temp_value /= LOWEST_FACTOR;
		printf(" %d", LOWEST_FACTOR);
		prime_count++;
	}

	return temp_value;
}


uint16_t handle_odd_factors(uint32_t temp_value, uint32_t factor)
{
	do{
		// next odd number to test
		factor += 2;
		// pick out all instances of this factor
		while(temp_value % factor == 0){
			temp_value /= factor;
			printf(" %d", factor);
			prime_count++;
		}
	}while(temp_value > 1);

	return prime_count;
}

const char* create_output_msg()
{
	return (prime_count <= 1)?	"Prime found!": "No prime number";
}
