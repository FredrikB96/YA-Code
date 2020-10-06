/*
 ============================================================================
 Name        : Data_Struct_Excersice.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	int month;
	int day;
}Dates;



int main(void) {
	setbuf(stdout,NULL);
	Dates Input;


	printf(" Enter the year,month and day in the format of xxxx-xx-xx\n");
	scanf("%d-%d-%d",&Input.year,&Input.month,&Input.day);


	printf("%d-%d-%d",Input.year,Input.month,Input.day);

	return EXIT_SUCCESS;
}
