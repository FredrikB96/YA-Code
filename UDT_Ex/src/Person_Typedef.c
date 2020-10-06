/*
 *  Person_Typedef.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */

#include <stdio.h>

// struct definition
typedef struct{
	char name[10];
	int age;
	float height, weight;
}Person;

// function prototypes
Person read_struct(void);
void print_struct(Person list[], int n);

/* -------------------- Start of Main Program -------------------- */
int main()
{
Person info[3];
int k;

	setbuf(stdout, NULL);

	printf("\n Function handling of a struct array \n");

	// read values to struct array via function call
	for(k=0; k<3; k++){
		info[k]=read_struct();
	}

	// print out stored struct array values
	print_struct(info, 3);

return 0;
}

// Function read_struct() reads and returns values for 1 Person
Person read_struct()
{
Person in = {};

	printf("\n Enter a name (max 10 characters): ");
	scanf(" %s", in.name);

	printf(" Enter age: ");
	scanf(" %d", &in.age);

	printf(" Enter height: ");
	scanf(" %f", &in.height);

	printf(" Enter weight: ");
	scanf(" %f", &in.weight);

return in;
}

// Function print_struct() prints out an array of n Persons backwards
void print_struct(Person list[], int n)
{
int k;

	for(k=n-1; k>=0; k--){
		printf("\n\n %s is %d years old", list[k].name, list[k].age);
		printf("\n %s is %3.2f m tall and weighs %4.1f kg ",
				list[k].name, list[k].height, list[k].weight);
	}
}
