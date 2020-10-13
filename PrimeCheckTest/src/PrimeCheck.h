/*
 * PrimeCheck.h
 * Created on: 8 October 2020
 * Author: Kjell H Carlsson
 */

#ifndef PRIMECHECK_H_
#define PRIMECHECK_H_

#include <stdint.h>

/**
 * input_func is used for user input of value including input control
 * input  - none
 * output - entered accepted value within range
 */
uint32_t input_func();

/**
 * input_func is used for user input of value including input control
 * input  - read-only initial value to investigate
 * output - current value after removing even factors
 */
uint32_t handle_even_factors(const uint32_t start_value);

/**
 * handle_odd_factors is used for separating all odd factors from current value
 * input  - temp_value the value that holds the rest after found factors
 * 		  - factor the odd value to start looking for as a factor
 * output - prime_count value indicating if a prime is found (returns 1)
 */
uint16_t handle_odd_factors(uint32_t temp_value, uint32_t factor);

/**
 * create_output_msg convert prime_count into a text msg
 * input  - none
 * output - a string defining textual output of investigation
 */
const char* create_output_msg();

#endif /* PRIMECHECK_H_ */
