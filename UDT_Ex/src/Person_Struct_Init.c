/*
 *  Person_Struct_Init.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */


#include <stdio.h>

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
struct p info, test={"Kalle", 57, 1.76, 75.5};

	setbuf(stdout, NULL);

	printf("\n Initialization and copying of a struct variable \n");

	info=test;

  	printf("\n %s is %d years old", info.name, info.age);
  	printf("\n %s is %3.2f m tall and weighs %4.1f kg ",
			 info.name, info.height, info.weight);

return 0;
}
