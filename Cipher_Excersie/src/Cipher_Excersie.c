/*
 ============================================================================
 Name        : Cipher_Excersie.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "header.h"

int main(void) {


	char User_Input[MAX_INPUT];
	char Input_Corrected[CHAR_MAX];
	setbuf(stdout,NULL);

	// Creating a variable called Position to keep track of correct position in Input_Correct array
	// If we were to use i in this instance the variables would be assigned in wrong positions
	int Position = 0;
	printf(" Enter the text to be encrypted: ");
	fgets(User_Input,CHAR_MAX,stdin);

	// Simple input control to check if user input is lower case, a digit or of space character
	for(int i=0;User_Input[i] !='\n';i++)
	{
		if(islower(User_Input[i]))
		{
			Input_Corrected[Position] = User_Input[i];
			Position++;
		}
		if(isdigit(User_Input[i]))
		{
			Input_Corrected[Position] = User_Input[i];
			Position++;
		}
		if(User_Input[i]==' ')
		{
			Input_Corrected[Position] = User_Input[i];
			Position++;
		}
	}

	// Assigning end of string character to the array then calling Encrypt function
	Input_Corrected[Position] = '\0';
	Encrypt(Input_Corrected);

	return EXIT_SUCCESS;
}
