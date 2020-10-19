/*
 ============================================================================
 Name        : Random_String.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "header_string.h"


int main(void) {

	setbuf(stdout,NULL);
	srand(time(0));

	int size = Input();

	char *Uptr;

	if((Uptr=(char*)malloc(sizeof(char)*size))!=NULL)
	{

	randomizer(Uptr,size);

	char lower = lowest(Uptr,size);


	printf("\n Lowest character are: %c", lower);
	}
	else
	{
		printf("\n Memmory couldn't be allocated");
	}

	return 0;
}
