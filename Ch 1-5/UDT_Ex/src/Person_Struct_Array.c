/*
 *  Person_Struct_Array.c
 *  Created on: 25 Sep 2020
 *  Author: Kjell H Carlsson
 */


#include <stdio.h>

// struct definition
struct p{
	char name[10];
	int age;
	float height, weight;
};

/* -------------------- Start of Main Program -------------------- */
int main()
{
struct p info[3];
int k;

	setbuf(stdout, NULL);

	printf("\n Arrays of structs \n");

	// read values to struct array
	for(k=0; k<3; k++){
		printf("\n Enter a name (max 10 characters) : ");
		scanf(" %s", info[k].name);
		printf(" Enter age: ");
		scanf(" %d", &info[k].age);
		printf(" Enter height: ");
		scanf(" %f", &info[k].height);
		printf(" Enter weight: ");
		scanf(" %f", &info[k].weight);
	}

	// print out stored struct array values
	for(k=2; k>=0; k--){
		printf("\n\n %s is %d years old", info[k].name, info[k].age);
		printf("\n %s is %3.2f m tall and weighs %4.1f kg ",
			info[k].name, info[k].height, info[k].weight);
	}

return 0;
}
