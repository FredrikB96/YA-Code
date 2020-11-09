/*
 *  Person_Struct.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>
#include <string.h>


// struct definition
struct p
{
	char name[10];
	int age;
	float height, weight;
};


/* -------------------- Start of Main Program -------------------- */
int main()
{
struct p info;

char test[10]="Kalle";

	setbuf(stdout, NULL);

	printf("\n Handling of a user defined type (struct) \n");

  	/* ----- Defining constant input to struct variable 'info' ----- */
  	info.age=57;
  	info.height=1.76;
  	info.weight=75.5;
  	strcpy(info.name, test);

  	printf("\n %s is %d years old", info.name, info.age);
  	  	printf("\n %s is %3.2f m tall and weighs %4.1f kg ",
  				 info.name, info.height, info.weight);

  	return 0;
  	}
