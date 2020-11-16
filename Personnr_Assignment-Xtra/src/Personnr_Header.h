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
#include <string.h>

#define MAX_AGE 10
#define MAX_INT 20
#define ODD 1
#define EVEN 2
#define LAST_FOUR 3
#define FOUR  4
#define SEVEN 7

#define LONGEST 15

#define EXPECTED 11
#define	START	21

// Creating a struct variable that will hold year,month,day in arrays in hopes to being able to get the different digits
typedef struct{
	int year[EVEN];
	int month[EVEN];
	int day[EVEN];
	int last[LAST_FOUR];
	int control;
}Age;

void divider(char *Input, int length);
/* ========== Divider ============
 *  checks for '-' character, if found skips function
 *  if not inserts '-' at correct position
 *  if length is 14, you have entered ie: 198101031033
 *  then its inserted at position 8, if you entered ie: 9901031033
 *  then length is 12 and '-' is entered at position 6
 */

void remover(char *Input);
/*=========== Remover ================
 * 	If length are 14 then the user input
 *  has 19 or 20 in beginning, then remove
 *  the two first digits for the rest of
 *  programs to work
 */

void Input_Control(char Input[],_Bool *Aptr);
/*===========Input_Control====================
 *  Input_Control is a function that controls the input if it is a leap year,
 *  if it is a valid date of birth (ie not 1234567890 or 123a34!?)
 *  Will need a pointer to the input array that are only used here
 *  Saves the input if correct in age struct
*/

Age Struct_Saving(char Input[]);
/*============Struct_Saving===================
 *  Takes the input array and stores it in a struct
 *  the struct has int arrays called year,month,day and last
 *  it also removes the last digit from input and stores it as a control digit
 *  Returns the struct to main
 */

void Char_To_Struct(char Input, int *Iptr);
/* ============= Char_To_Struct ===============
 * supplement function used to save the input char array to diffrent struct
 * variables. takes the Input from Struct_Saving and stores it as an int in the pointers position.
 */

_Bool Date_Control(Age user, _Bool *Lptr);
/*============ Date_Control =================
 *  Checks if the date is a correct input
 *  this is done by calling a function that checks for leap year
 *  then controls how many days it are in the month
 *  if days equals the correct ammount of days in the month send back a true value
 */

int Year_Corrected(Age user);
/* ========== Year_Corrected ================
 *  Converts the two digit year input to a four digit int
 *  this is done by checking if year are below 21 then the person
 *  has to be born 2000 and forward so we add 20 to the start of the year
 *  else add 19 to the start, takes the hole struct, could have taken only the year int
 *  returns the corrected int
 */

void Leap_Year(int Year, _Bool *Lptr);
/*============= Leap_year ==================
 *  Controls if the int year are a leap year
 *  as to have a corrected year as input.
 *  A corrected value has four digits ie: 41=> 1941, 14=>2014
 *  Corrected input are achieved easy by sending the year to Year_Corrected function
 */

void Multiply(int *Aptr, int *Mptr, int *Dptr,int *Lptr, int *Sum);
/*============== Multiply =================
 *  Multipling each position of the struct array positions
 *  the function demands pointers to the different struct array positions
 *  as example a pointer to the year array in the struct. the function
 *  demands 5 different pointers. Stores the results in Sum array from main using a pointer
 */

int Add(int *Sum);
/* =========== ADD ==============
 *  Adding each digit in the sum array to each other
 *  Due to criteria from customer to use pointers
 *  this function needs a pointer to start position of array
 *  will return an int with the value to be used
 */

_Bool control(int Control,int Sum);
/* ========== Control ================
 * Controls if the last digit in sum is the same as the control digit
 * is achieved by taking the sum int and dividing by 10 until not possible
 * then taking away that digit from 10, checks the result of that equation
 * is the same as control digit
 */

#endif /* PERSONNR_HEADER_H_ */
