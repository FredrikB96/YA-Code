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
	Dates Filtered_Input[2];

	do{
		Valid_Input = true;
		printf(" Enter the first values: (Year-Month-Day)\n");
		Filtered_Input[0] = Input();

		printf(" Enter the second row of values: (Year-Month-Day\n");
		Filtered_Input[1] = Input();

		for(int i=0;i<2;i++)
		{
			if(Filtered_Input[i].year>MAX_YEAR)
			{
				Valid_Input = false;
			}
			if(Filtered_Input[i].month>MAX_MONTH)
			{
				Valid_Input = false;
			}
			if(Filtered_Input[i].day>MAX_DAYS)
			{
				Valid_Input = false;
			}
		}

		if(!Valid_Input)
		{
			printf(" Month can't be above 12, and days can't be above 30\n");
		}

	}while(!Valid_Input);


//	Dates diff = datediff(Input[0],Input[1]);

		return EXIT_SUCCESS;

}




