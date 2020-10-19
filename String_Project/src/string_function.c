/*
 * string_function.c
 *
 *  Created on: 19 okt. 2020
 *      Author: Benny
 */

#include "header_string.h"

int Input(){
	int size = 0;
	char Input[2];
	int p= 0;

	// Getting the size of the array with input control
	printf("\n How many numbers do you want the array to consist of? ");
	printf("\n If larger than %d the program will set it to %d \n",MAX,MAX);
	char temp;
	for(int i=0;temp !='\n';i++)
	{
		temp = getchar();
		if(temp>='0'&&temp<='9')
		{
			Input[p] = temp;
			p++;
		}
	}
	size = atoi(Input); // Getting the value of the array, will remove end of string character and store the rest.
	if(size>MAX)
	{
		printf("\n Expects a number less than %d", MAX);
		size = MAX;
	}

	return size;
}


void randomizer(char *Upt, int size){

	printf("\n Letters are: ");
	for(int i=0;i<size;i++)
	{
		*Upt = rand() % 91;
		if(*Upt<='Z'&&*Upt>='A')
		{
			printf(" %c", *Upt);
			Upt++;
		}
		else
		{
			i--;
		}
	}


}

char lowest(char *Upt, int size) {

	char temp;
	char lower = *Upt;
	for(int i=0;i<size;i++)
	{
		temp = *Upt;
		if(temp<*Upt)
		{
			lower = temp;
		}
		Upt++;
	}

	return lower;
}
