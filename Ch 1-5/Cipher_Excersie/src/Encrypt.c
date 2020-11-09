/*
 * Encrypt.c
 *
 *  Created on: 5 okt. 2020
 *      Author: blomg
 */

#include "header.h"

void Encrypt(char Input_Corrected[CHAR_MAX]){
	// Encrypt Function gets the Input from main array function


	char Encrypted[CHAR_MAX];
	char Temp_array[CHAR_MAX];
	char Temp_Space[CHAR_MAX];
	int size = strlen(Input_Corrected); // getting the length of the array Input_Correct

	// Creating 3 iteration variables
	int Spaces = 0;
	int Position = 0;
	int Number_Of_Letters = 0;

	// Input control
	for(int i=0;i<size;i++)
	{
		if(Input_Corrected[i]>='a'&& Input_Corrected[i]<='y')
		{
			Number_Of_Letters++; // adding 1 to the Number_Of_Letters variable to keep track of how many letters it is in the array
			Temp_array[Position] = toupper(Input_Corrected[i]+1); // Converting the lower case letter to upper case letter
			Position++; // Moving forward 1 position in Temp_array
		}
		if(Input_Corrected[i]=='z')
		{
			// the z character is a special case, we will need to change it to A by hard coding
			Number_Of_Letters++;
			Temp_array[Position] = 'A';
			Position++;

		}
		if(isdigit(Input_Corrected[i]))
		{
			// moving the variable from Input_Corrected to Temp_array
			Temp_array[Position] = Input_Corrected[i];
			Position++;
		}
		if(Input_Corrected[i]==' ')
		{
			// changing space to corresponding lower case letter depending on the position in the array
			// then store it in Temp_Space to use later
			Temp_Space[Spaces] = 'a' + i;
			Spaces++; // Moving forward 1 step
		}
	}

	for(int i=0;i<size;i++)
	{
		if(isdigit(Temp_array[i]))
		{
		// taking away the character 0 to convert it to an int. Then we store it in temp variable
		int temp = Temp_array[i] -'0';
		// Adding the number of letters that was in the input
		temp += Number_Of_Letters;
		// we divide with 10 and only keeping the remainder of the equations
		temp %= TEN;
		Temp_array[i] = temp + '0'; // Adding character of 0 to convert it back to a char
		}
	}
	Temp_Space[Spaces] = '\n';
	Spaces = 0; // Resetting iteration to use in for loop
	for(int i=Position;Temp_Space[Spaces] !='\n';i++)
	{
		// We assign the lower case letters from spaces that we created before, to the end of the array
		Temp_array[i]= Temp_Space[Spaces];
		Spaces++;
		Position++;
	}
	Temp_array[Position]='\0';
	size = strlen(Temp_array); // Getting the new size of the array
//	Temp_array[size] = '\0';
	int k = 0;

	for(int i=size;i>=0;i--)
	{
		// Reversing the Temp_array and storing it in Encrypted. Then we print it out
		Encrypted[k] = Temp_array[i];
		printf("%c", Encrypted[k]);
		k++;
	}
}
