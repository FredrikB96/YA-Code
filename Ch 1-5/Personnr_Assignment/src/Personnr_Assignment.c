/*
 ============================================================================
 Name        : Personnr_Assignment.c
 Author      : Fredrik Blomgren
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Personnr_Header.h"

int main(void) {

	// Declaring variables needed
	char User_Input[MAX_INT];
	_Bool Valid = false;
	_Bool Accepted = true;
	_Bool Leap = false;
	_Bool Ok_Input = false;
	int sum[MAX_AGE-ODD];
	int add = 0;
	Age user;

	setbuf(stdout,NULL);
	// Declaring pointers and assigning pointers to correct variable
	_Bool *Aptr = &Accepted;
	_Bool *Lptr = &Leap;

	// Pointers used in multiply just to get used with using pointers
	int *Age = &user.year[0];
	int *Month = &user.month[0];
	int *Day = &user.day[0];
	int *Last = &user.last[0];
	int *Sum = &sum[0];

	do{
		// takes input from user
		fflush(stdin);
		printf("\n Enter age by format: XXXXXX-XXXX ");
		fgets(User_Input,MAX_INT,stdin);

		// Getting length of input to check if it is a valid length
		int length = strlen(User_Input);
		if((length==EXPECTED)||(length == EXPECTED+1))
		{
			Input_Control(User_Input,Aptr); // Checks for letters, then requesting new input if letters are found

			if(Accepted)
			{
				user = Struct_Saving(User_Input); // refactors char input to struct
				Valid = Date_Control(user,Lptr); // Controls if input is a valid date, ie leap year, days in the month

				if(Valid)
				{
					Multiply(Age,Month,Day,Last,Sum); // Equation function, check h file for more info
					add = Add(Sum); // Equation function, check h file for more info
					Ok_Input = control(user.control,add); // Equation function, check h file for more info
				}
				else if(*Lptr == false)
					printf("\n not leap year, inputted 29 days in february");
			}
			else if(!Accepted)
			{
				Accepted = true;
				printf("\n Can't accept letters or special characters with exemption of '-' character");
			}
		}
		else{
			printf("Less than %d characters, not valid personal number!",MAX_AGE);
		}

	}while(!Valid);

	if(Ok_Input)
	{
		printf("\n Input: %s Has control digit: %d",User_Input,user.control);
		printf("\n Was OK!");
	}
	else
	{
		printf("\n Input: %s Has control digit: %d",User_Input,user.control);
		printf("\n Was NOT OK!");

	}

	return EXIT_SUCCESS;
}
