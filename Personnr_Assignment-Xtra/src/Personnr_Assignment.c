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

int main(int args, char *Argc[]) {

	// Declaring variables needed
	int a = 0;
	char User_Input[MAX_INT];
//	char Input_Correct[MAX_AGE];
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

	char *Inputptr = &User_Input[0];

	// Pointers used in multiply just to get used with using pointers
	int *Age = &user.year[0];
	int *Month = &user.month[0];
	int *Day = &user.day[0];
	int *Last = &user.last[0];
	int *Sum = &sum[0];

	int length;

	// checks for input in launch of program
	if(args>=2)
	{
		if(args==2) // if user only put in one argument then copy it to user_input and insert \n and \0 at end of array
		{
			strcpy(User_Input,Argc[1]);

			length = strlen(User_Input);
			User_Input[length] = '\n';
			User_Input[length+1] = '\0';

		}
		else
		{
			printf("\n too may arguments from user"); // Gives feedback if arguments where too many
		}
	}
	else
	{
		printf("\n no arguments found starting from scratch"); // If no arguments found gives feedback and ask for input
	}

	if(args<=2) {
	do{

		if(args<2)
		{
			// takes input from user
			printf("\n Enter age by format: XXXXXX-XXXX ");
			fgets(User_Input,MAX_INT,stdin);
		}

		length = strlen(User_Input);

		divider(Inputptr,length);

		// Getting length of input to check if it is a valid length
		length = strlen(User_Input);

		if(length==14)
			remover(Inputptr);

		length = strlen(User_Input);
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

				else if(args>1) // Added 2020-11-17
				{
					printf("\n argument not accepted");
					break;
				}
			}
			else if(!Accepted)
			{
				Accepted = true;
				printf("\n Can't accept letters or special characters with exemption of '-' character");
				if(args==2)
				{
					break; // Breaks, because arguments where provided to prevent infinite loop
				}
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
	}
	return EXIT_SUCCESS;
}
