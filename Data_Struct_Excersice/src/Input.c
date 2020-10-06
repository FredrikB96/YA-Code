/*
 * Input.c
 *
 *  Created on: 6 okt. 2020
 *      Author: Benny
 */
#include "header.h"

Dates Input(){

	int Year_Length = 4;
	int Day_Month_Length = 2;
	unsigned char User_Input[MAX_INPUT];
	Dates Input;
	int i;
	char temp;


	for(i=0;temp!='-';i++)
	{
		temp = getchar();
		if(isdigit(temp))
		{
			User_Input[i] = temp;
		}
	}
	i--;
	User_Input[i] = '\0';
	int User_Length = strlen(User_Input);
	if(User_Length<=Year_Length)
	{
		Input.year = atoi(User_Input);
	}


	for(i=0;temp!='-';i++)
	{
		temp = getchar();
		if(isdigit(temp))
		{
			User_Input[i] = temp;
		}
	}
	i--;
	User_Input[i] = '\0';
	 User_Length = strlen(User_Input);
	if(User_Length<=Day_Month_Length)
	{
		Input.month = atoi(User_Input);
	}


	for(i=0;temp!='-';i++)
	{
		temp = getchar();
		if(isdigit(temp))
		{
			User_Input[i] = temp;
		}
	}
	i--;
	User_Input[i] = '\0';
	User_Length = strlen(User_Input);
	if(User_Length<=Day_Month_Length)
	{
		Input.day = atoi(User_Input);
	}

	return Input;
}
