/*
 * Datediff_Start.c
 *
 *  Created on: 7 okt. 2020
 *      Author: Benny
 */


#include "header.h"

void Datediff_Start() {

	setbuf(stdout,NULL);
	_Bool Valid_Input = true;
	Dates Filtered_Input[INPUTS];
	char User_Input[MAX_INPUT];

	for(int i=0;i<INPUTS;i++)
	{
		printf("\n Enter date number %d (Correctly!)(XXXX-XX-XX): ",i+1);
		fgets(User_Input,MAX_INPUT,stdin);
		Filtered_Input[i] = Input(User_Input);
		fflush(stdin);
		Valid_Input = Input_Control(Filtered_Input[i]);
		if(!Valid_Input)
		{
			i--;
			printf("\n Entered either above 2048 years, above 12 months or above 30 days!");
		}
	}



	Dates diff = datediff(Filtered_Input[0],Filtered_Input[1]);


	printf(" The difference is %d years, %d months and %d days\n",diff.year,diff.month,diff.day);

}
