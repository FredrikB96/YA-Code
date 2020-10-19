/*
 *  Structmx.c
 *  Created on: 8 Oct 2020
 *  Author: Kjell Carlsson
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

// struct definition
struct phonelist
{
	int area;
	long int phone;
	char name[MAX];
};

int main()
{
struct phonelist *spnt;		// declare a struct pointer

setbuf(stdout, NULL);

// Allocate dynamic memory for the struct pointer
spnt=(struct phonelist*) malloc(sizeof(struct phonelist));

  printf("\n Dynamic memory allocation for a struct \n");

  // Defining constant input to structure 'phonelist'
  spnt->area = 31;
  spnt->phone = 9995087;
  strcpy(spnt->name, "Mr C");

  printf("\n Dial %ld to call %s who lives in area %03d ",\
			spnt->phone, spnt->name, spnt->area);

  free(spnt);			// free allocated memory

return 0;
}
