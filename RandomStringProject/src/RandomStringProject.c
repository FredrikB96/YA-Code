/*
 ============================================================================
 Name        : RandomStringProject.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 12

char lowest(char *Random);

int main(void) {

	char Random[MAX+1], *i;
	srand(time(0));

	for(i=Random ;i<Random + MAX ;i++)
	{
		int temp = rand() % 26;
		*i = temp + 'A';
	}

	Random[MAX+1] = '\0';

	int size = strlen(Random);

	printf("%d \n",size);

	for(int i=0;i<MAX;i++)
	{
		printf("%c", Random[i]);
	}

	char Minimum = lowest(Random);

	printf("\n The smallest letter is: %c", Minimum);
	return EXIT_SUCCESS;
}


char lowest(char *Random){

	char *min = Random;
	char *temp = Random;

	for(int i=0;*temp !='\0';i++)
	{
		if(*temp < *min)
			*min = *temp;
		*temp++;
	}

	return *min;
}
