/*
 * Input.c
 *
 *  Created on: 6 okt. 2020
 *      Author: Benny
 */
#include "header.h"

Dates Input(char User_Input[MAX_INPUT]){

	_Bool Not_Digit = false;
	int Year_Length = 4;
	int Day_Month_Length = 2;
	unsigned char Temp_Array[MAX_INPUT];
	Dates Input;
	int i;
	int Position = 0;
	char temp;


	for(i=0;!Not_Digit;i++)
	{
		temp = User_Input[Position];
		if(isdigit(temp))
		{
			Temp_Array[i] = temp;
			Position++;
		}
		if(!isdigit(temp))
		{
			Not_Digit = true;
		}
	}
	i--;
	Temp_Array[i] = '\0';
	int User_Length = strlen(Temp_Array);
	if(User_Length<=Year_Length)
	{
		Input.year = atoi(Temp_Array);
	}
	temp = 0;
	Position++;
	Not_Digit = false;

	for(i=0;!Not_Digit;i++)
	{
		temp = User_Input[Position];
		if(isdigit(temp))
		{
			Temp_Array[i] = temp;
			Position++;
		}
		if(!isdigit(temp))
		{
			Not_Digit = true;
		}
	}
	i--;
	Temp_Array[i] = '\0';
	 User_Length = strlen(Temp_Array);
	if(User_Length<=Day_Month_Length)
	{
		Input.month = atoi(Temp_Array);
	}
	temp = 'a';
	Position++;

	for(i=0;temp !='\0';i++)
	{
		temp = User_Input[Position];
		if(isdigit(temp))
		{
			Temp_Array[i] = temp;
			Position++;
		}
	}
	i--;
	Temp_Array[i] = '\0';
	User_Length = strlen(Temp_Array);
	if(User_Length<=Day_Month_Length)
	{
		Input.day = atoi(Temp_Array);
	}
	temp = 0;
	Position++;

	return Input;
}
