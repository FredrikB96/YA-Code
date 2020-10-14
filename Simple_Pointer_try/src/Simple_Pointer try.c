/*
 ============================================================================
 Name        : Simple_Pointer.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int Value1, Value2;
	int *Fptr, *Sptr;

	setbuf(stdout,NULL);

	printf("Write First number then second number to be added together (use format: XXX-XXX\n ");
	scanf("%d-%d",&Value1,&Value2);

	*Fptr = Value1;
	*Sptr = Value2;

	int sum = Addition(Fptr,Sptr);

	printf("%d",sum);

	return EXIT_SUCCESS;
}

int Addition(int *ptr, int *Nptr)
{
	int sum;

	sum = *ptr + *Nptr;

	return sum;
}
