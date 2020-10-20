/*
 * Personnr_Header.h
 *
 *  Created on: 20 okt. 2020
 *      Author: Benny
 */

#ifndef PERSONNR_HEADER_H_
#define PERSONNR_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_AGE 10
#define MAX_INT 20
#define ODD 1
#define EVEN 2
#define LAST_FOUR 3

#define EXPECTED 11
#define START_DATE 1921
#define	START	21
#define END_DATE 2021


typedef struct{
	int year[EVEN];
	int month[EVEN];
	int day[EVEN];
	int last[LAST_FOUR];
	int control;
}Age;


Age Struct_Saving(char Input[]);
void Leap_Year(int Year, _Bool *Lptr);
int Year_Corrected(Age user);
_Bool Date_Control(Age user, _Bool *Lptr);
void Input_Control(char Input[],_Bool *Aptr);

// Input_Control is a function that controls the input if it is a leap year,
//  if it is a valid date of birth (ie not 1234567890 or 123a34!?)
// Will need a pointer to the input array that are only used here
// Saves the input if correct in age struct

// Creating a struct variable that will hold year,month,day in arrays in hopes to being able to get the different digits

#endif /* PERSONNR_HEADER_H_ */
