/*
 * header.h
 *
 *  Created on: 6 okt. 2020
 *      Author: Benny
 */

#ifndef HEADER_H_
#define HEADER_H_


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	unsigned int year: 12;
	unsigned int month: 4;
	unsigned int day: 5;
}Dates;


#define MAX_INPUT 10
#define INPUTS 2
#define MAX_MONTH 12
#define MAX_YEAR 2048
#define MAX_DAYS 30
#define INPUTS_STORED 3

Dates Input();
Dates datediff (Dates d1, Dates d2);

#endif /* HEADER_H_ */
