/*
 * Date_Array.c
 *
 *  Created on: 7 okt. 2020
 *      Author: Benny
 */

#include "header.h"

	Dates date[DATE_ARRAY];
void Date_Array() {
	char User_Input[MAX_INPUT];
	_Bool Valid = true;

	do {
	for(int i=0;i<DATE_ARRAY;i++)
	{
		printf("\n Enter date number %d (Correctly!)(XXXX-XX-XX): ",i+1);
		fgets(User_Input,MAX_INPUT,stdin);
		date[i] = Input(User_Input);
		fflush(stdin);
		Valid = Input_Control(date[i]);
		if(!Valid)
		{
			i--;
			printf("\n Enter a date between 1582-2048, with a maximum value of 12 in months and have correct days in the month!");
		}
	}


	}while(!Valid);
	printdate();
}

Dates readdate(int i)
{
	return date[i];
}

void printdate()
{
	Dates Correct_Date[DATE_ARRAY];

	for(int i=0;i<DATE_ARRAY;i++)
	{
		Correct_Date[i] = readdate(i);
	}

	printf(" Here are your dates: \n");
	for(int i=0;i<DATE_ARRAY;i++)
	{
		printf(" %d-%d-%d\n",Correct_Date[i].year,Correct_Date[i].month,Correct_Date[i].day);
	}

}
