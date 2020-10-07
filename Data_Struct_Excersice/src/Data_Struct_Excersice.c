/*
 ============================================================================
 Name        : Data_Struct_Excersice.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "header.h"

int main(void) {

	setbuf(stdout,NULL);
	_Bool Valid_Input = true;

	do{
		Valid_Input = true;
		printf(" Welcome!\n 1.Do you want to run Date Array? (Store 4 arrays)\n 2.Do you want to check Date difference?\n 3.Quit\n");
		char temp = getchar();
		char disregard = getchar();

		if(temp =='1')
			Date_Array();

		if(temp =='2')
			Datediff_Start();

		if(temp =='3')
			Valid_Input = false;



	}while(!Valid_Input);

	printf("\n Goodbye!");

	return EXIT_SUCCESS;

}




