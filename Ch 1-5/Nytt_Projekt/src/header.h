/*
 * header.h
 *
 *  Created on: 6 okt. 2020
 *      Author: Benny
 */

#ifndef HEADER_H_
#define HEADER_H_

// #include "..\\test\SimpleCTester.h"
#include <Ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	unsigned int year: 12;
	unsigned int month: 4;
	unsigned int day: 5;
}Dates;


#define MAX_INPUT 11
#define INPUTS 2
#define MAX_MONTH 12
#define MAX_YEAR 2048
#define MAX_DAYS 30
#define INPUTS_STORED 3
#define DATE_ARRAY 4
#define EARLIEST_YEAR 1582


Dates Input(char User_Input[MAX_INPUT]);
Dates datediff (Dates d1, Dates d2);
void Datediff_Start();
void Date_Array();
Dates readdate(int i);
void printdate();
_Bool Input_Control(Dates date);
_Bool Leap_Year(Dates date);

#endif /* HEADER_H_ */
