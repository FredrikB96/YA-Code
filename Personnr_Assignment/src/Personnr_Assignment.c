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

	int *Age = &user.year;
	int *Month = &user.month;
	int *Day = &user.day;
	int *Last = &user.last;
	int *Sum = &sum;

	do{
		printf("\n Enter age by format: XXXXXX-XXXX ");
		fgets(User_Input,MAX_INT,stdin);

		int length = strlen(User_Input);
		if((length==EXPECTED)||(length == EXPECTED+1))
		{
			Input_Control(User_Input,Aptr);

			if(Accepted)
			{
				user = Struct_Saving(User_Input);
				Valid = Date_Control(user,Lptr);

				if(Valid)
				{
					Multiply(Age,Month,Day,Last,Sum);
					add = Add(Sum);
					Ok_Input = control(user.control,add);
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
